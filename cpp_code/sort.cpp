#include<bits/stdc++.h>
using namespace std;
ll a[600000], b[600000], ans;
void mergee(ll l, ll r) {
	if (l >= r) {  //不能再分了，直接返回。
		return ;
	}
	ll mid = (l + r) / 2;//取一个中间值
	ll i = l, j = mid + 1, tot = l;  // i是第一个序列的开头，j是第二个序列的开头，tot是整个的大序列。
	while (i <= mid && j <= r) {  //合并
		if (a[i] <= a[j]) {  //谁小就把谁放到前面。
			b[tot++] = a[i]; 
			i++;
		} else {
			b[tot++] = a[j];
			j++;
		}
	}
	while (i <= mid) {  //可能还没有放完，就把剩下的放进来。
		b[tot++] = a[i];
		i++;
	}
	while (j <= r) {  // 同上
		b[tot++] = a[j];
		j++;
	}
	for (int i = l; i <= r; i++) {  // 给最终的答案数组赋值。
		a[i] = b[i];
	}
	return;
}
void mergesort(ll l, ll r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergesort(l, mid);  //  先给左子序列排序。
		mergesort(mid + 1, r); //再给右子序列排序。
		mergee(l, r);  // 最后把两个子序列合并。
	}
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[],int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    print_array(arr, n);
}