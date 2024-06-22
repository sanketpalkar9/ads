#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

int *quickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int main()
{

    int arr[] = {4, 3, 54, 65, 23, 62, 23, 54, 23, 78, 24, 45, 98, 32, 54};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
