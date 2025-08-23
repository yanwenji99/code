#include <stdio.h>

void printCombination(int arr[], int n, int m, int index, int data[], int i)
{
    // 当组合完成时，打印组合
    if (index == m)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", data[j]);
        }
        printf("\n");
        return;
    }

    // 当没有更多元素可以放入组合时，返回
    if (i >= n)
    {
        return;
    }

    // 当前元素包含在组合中
    data[index] = arr[i];
    printCombination(arr, n, m, index + 1, data, i + 1);

    // 当前元素不包含在组合中
    printCombination(arr, n, m, index, data, i + 1);
}

void generateCombinations(int arr[], int n, int m)
{
    int data[m];
    printCombination(arr, n, m, 0, data, 0);
}

int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);

    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    generateCombinations(arr, n, m);

    return 0;
}