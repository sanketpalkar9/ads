#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r <= n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(arr, n, i);
    }
    for (int i = n; i >= 2; i--)
    {
        swap(&arr[1], &arr[i]);
        maxHeapify(arr, i - 1, 1);
    }
}

int main()
{
    int arr[] = {0, 15, 5, 20, 1, 17, 10, 30}; // Note the dummy element at index 0 for 1-based indexing
    int n = sizeof(arr) / sizeof(arr[0]) - 1;

    heapSort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
