#include <stdio.h>
#include <limits.h>

typedef struct shell
{
    int pd;   // 标记是否已选
    int love; // 喜爱度
} sl;

// 深度优先搜索函数
void happy(sl a[], int n, int m, int start, int current_love, int selected, int *max_love)
{
    // 如果已经选择了 m 个贝壳，更新最大值并返回
    if (selected == m)
    {
        if (current_love > *max_love)
        {
            *max_love = current_love;
        }
        return;
    }

    // 遍历剩余的贝壳
    for (int i = start; i < n; i++)
    {
        if (a[i].pd == 0)
        {                // 如果当前贝壳未被选择
            a[i].pd = 1; // 标记为已选择
            // 更新喜爱度，并递归选择下一个贝壳
            happy(a, n, m, i + 1, current_love & a[i].love, selected + 1, max_love);
            a[i].pd = 0; // 回溯，取消选择
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m); // 输入贝壳数量和口袋容量

    sl shell[n];
    for (int i = 0; i < n; i++)
    {
        shell[i].pd = 0;             // 初始化为未选择
        scanf("%d", &shell[i].love); // 输入每个贝壳的喜爱度
    }

    int max_love = 0; // 初始化最大开心程度为 0
    happy(shell, n, m, 0, INT_MAX, 0, &max_love);

    printf("%d\n", max_love); // 输出最大开心程度
    return 0;
}