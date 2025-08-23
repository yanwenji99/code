#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#define ElemType int 
#define MAX_DIM 8
typedef enum {OK, OVERFLOW, ERROR} Status;

// 普通数组

typedef struct {
    ElemType *base;
    int dim;
    int *bounds;
    int *constants;
    int t;
} Array;
Status InitArray(Array *A, int dim, ...)
{
    if(dim<1 || dim>MAX_DIM)
        return ERROR;
    A->dim = dim;
    A->bounds = (int *)malloc(dim*sizeof(int));
    if(!A->bounds)
        exit(OVERFLOW);
    va_list ap;
    int i, elemtotal = 1;
    va_start(ap, dim);
    for (i = 0; i < dim; i++)
    {
        A->bounds[i] = va_arg(ap, int);
        if(A->bounds[i]<0)
            return ERROR;
        elemtotal *= A->bounds[i];
    }
    va_end(ap);
    A->base =(ElemType*)malloc(elemtotal*sizeof(ElemType));
    if(!A->base)
        exit(OVERFLOW);
    A->constants = (int *)malloc(dim*sizeof(int));
    if(!A->constants)
        exit(OVERFLOW);
    A->constants[dim-1] = 1;
    for (i = dim-2; i >= 0; i--)
    {
        A->constants[i] = A->bounds[i+1]*A->constants[i+1];
    }
    A->t = 0;
    for(i=0; i<elemtotal; i++)
        A->base[i] = 0;
    return OK;
}
Status DestroyArray(Array *A)
{
    if(!A->base)
        return ERROR;
    free(A->base);
    A->base = NULL;
    if(!A->bounds)
        return ERROR;
    free(A->bounds);
    A->bounds = NULL;
    if(!A->constants)
        return ERROR;
    free(A->constants);
    A->constants = NULL;
    return OK;
}
Status Locate(Array A, int *off, va_list ap)
{
    int i, ind;
    *off = 0;
    for (i = 0; i < A.dim; i++)
    {
        ind = va_arg(ap, int)-1;
        if(ind<0 || ind>=A.bounds[i])
            return OVERFLOW;
        *off += A.constants[i]*ind;
    }
    return OK;
}
Status Value(Array A, ElemType *e, ...)
{
    int off;
    va_list ap;
    va_start(ap, e);
    if(Locate(A, &off, ap)==OVERFLOW)
        return OVERFLOW;
    *e = *(A.base+off);
    return OK;
}
Status Assign(Array *A, ElemType e, ...)
{
    int off;
    va_list ap;
    va_start(ap, e);
    if(Locate(*A, &off, ap)==OVERFLOW)
        return OVERFLOW;
    *(A->base+off) = e;
    A->t++;
    return OK;
}
void PrintArray(Array A)
{
    int i, j;
    ElemType e;
    for (i = 1; i <= A.bounds[0]; i++)
    {
        for (j = 1; j <= A.bounds[1]; j++)
        {
            Value(A, &e, i, j);
            printf("%d ", e);
        }
        printf("\n");
    }
}

// 稀疏矩阵

#define MAX_SIZE 12500
typedef struct {
    int i, j;
    ElemType e;
} Triple;
typedef struct {
    Triple data[MAX_SIZE+1];
    int mu, nu, tu;
} TSMatrix;
Status is_Sparse(Array A)
{
    int n = A.dim, i, elemtatal = 1;
    for (i = 0; i < n; i++)
    {
        elemtatal *= A.bounds[i];
    }
    if((double)A.t / elemtatal < 0.5)
        return OK;
    return ERROR;
}
Status InitSMatrix(TSMatrix *M)
{
    M->mu = M->nu = M->tu = 0;
    return OK;
}
Status Compress(TSMatrix *M, Array A)
{
    int i, j, k = 0;
    M->mu = A.bounds[0];
    M->nu = A.bounds[1];
    for (i = 0; i < M->mu; i++)
    {
        for (j = 0; j < M->nu; j++)
        {
            if(A.base[k]!=0)
            {
                M->data[M->tu].i = i;
                M->data[M->tu].j = j;
                M->data[M->tu].e = A.base[k];
                M->tu++;
            }
            k++;
        }
    }
    return OK;
}
Status FastTransposeSMatrix(TSMatrix M, TSMatrix *T)
{
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    if(T->tu)
    {
        int col,t,p,num[M.nu],cpot[M.nu];
        for (col = 0; col < M.nu; col++)
        {
            num[col] = 0;
        }
        for (t = 0; t < M.tu; t++)
        {
            num[M.data[t].j]++;
        }
        cpot[0] = 0;
        for (col = 1; col < M.nu; col++)
        {
            cpot[col] = cpot[col-1]+num[col-1];
        }
        for (p = 0; p < M.tu; p++)
        {
            col = M.data[p].j;
            int q = cpot[col];
            T->data[q].i = M.data[p].j;
            T->data[q].j = M.data[p].i;
            T->data[q].e = M.data[p].e;
            cpot[col]++;
        }
    }
    return OK;
}
void PrintSMatrix(TSMatrix M)
{
    int i;
    for (i = 0; i < M.tu; i++)
    {
        printf("%d %d %d\n", M.data[i].i, M.data[i].j, M.data[i].e);
    }
}
int main()
{
    Array A;
    InitArray(&A, 2, 3, 4);
    Assign(&A, 5, 1, 2);
    Assign(&A, 6, 2, 3);
    PrintArray(A);
    if( !is_Sparse(A) && A.dim==2 )
    {
        TSMatrix M;
        InitSMatrix(&M);
        Compress(&M, A);
        PrintSMatrix(M);
        printf("\n");
        TSMatrix T;
        FastTransposeSMatrix(M, &T);
        PrintSMatrix(T);
    }
    return 0;
}