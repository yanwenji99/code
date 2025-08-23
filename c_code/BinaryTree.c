#include<stdio.h>
#include<stdlib.h>
#define ElemType char
typedef enum
{
    ERROR,
    OK
} Status;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
Status CreatBiTree(BiTree *T)
{
    ElemType ch;
    scanf("%c",&ch);
    if(ch == ' ')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(0);
        (*T)->data = ch;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
    return OK;
}
Status PreOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%c ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
}
Status InOrderTraverse(BiTree *T)
{
    if(*T)
    {
        InOrderTraverse(&(*T)->lchild);
        printf("%c ",(*T)->data);
        InOrderTraverse(&(*T)->rchild);
    }
    return OK;
}
Status PostOrderTraverse(BiTree *T)
{
    if(*T)
    {
        PostOrderTraverse(&(*T)->lchild);
        PostOrderTraverse(&(*T)->rchild);
        printf("%c ",(*T)->data);
    }
    return OK;
}
int main()
{
    BiTree T;
    CreatBiTree(&T);
    printf("PreOrderTraverse: ");
    PreOrderTraverse(T);
    printf("\nInOrderTraverse: ");
    InOrderTraverse(&T);
    printf("\nPostOrderTraverse: ");
    PostOrderTraverse(&T);
    return 0;
}