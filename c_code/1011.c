#include <stdio.h>
int calculate_people_on_train(int n, int a, int m, int x)
{
    int up[n], down[n], ren[n], i, j;
    up[0] = a;
    down[0] = 0;
    ren[0] = a;
    for (i = 0; i <= m;i++)
    {
        up[1] = i;
        down[1] = i;
        ren[1] = a;
        for (j = 2; j < n-1;j++)
        {
            up[j] = up[j - 2] + up[j - 1];
            down[j] = up[j - 1];
            ren[j] = ren[j - 1] + up[j] - down[j];
        }
        if(ren[n-2]==m)
        {
            break;
        }
    }
    return ren[x - 1];
}
int main()
{
    int n, a, m, x;
    scanf("%d%d%d%d", &a,&n,&m,&x);
    int result = calculate_people_on_train(n, a, m, x);
    printf("%d\n", result);
    return 0;
}