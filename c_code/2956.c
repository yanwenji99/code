#include <stdio.h>
int main()
{
    int m, n, k, i, j, l, ans = 0;
    scanf("%d%d%d", &m, &n, &k);
    int x1[k], y1[k], x2[k], y2[k], a[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (i = 0; i < k; i++)
    {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        for (j = x1[i] - 1; j < x2[i]; j++)
        {
            for (l = y1[i] - 1; l < y2[i]; l++)
            {
                a[j][l] = 1;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}