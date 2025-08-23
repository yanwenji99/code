#include<stdio.h>
// 计算阶乘的函数
long long factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= num; i++)
    {
        result *= i;
    }
    return result;
}

// 计算组合数的函数
long long combination(int n, int k)
{
    if (k > n)
    {
        return 0; // 如果 k > n，组合数为 0
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
}
int main()
{
    int bx, by, mx, my, way = 0;
    scanf("%d%d%d%d", &bx, &by, &mx, &my);
    if(mx-3>=0&&my+3<=by)
    {
        int t1,t2;
        t1 = combination(mx - 3 + my, my);
        t2 = combination(bx - mx + by - my - 1, by - my);
        way += t1 * t2;
    }
    if (my - 3 >= 0 && mx + 3 <= bx)
    {
        int t1, t2;
        t1 = combination(my - 3 + mx, mx);
        t2 = combination(bx - mx + by - my - 1, bx - mx);
        way += t1 * t2;
    }
    printf("%d\n", way);
}