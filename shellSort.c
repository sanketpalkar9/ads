#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void shellSort(int arr[], int n)
{

    for (int gap = n / 2; gap >= 1; gap++)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (arr[i + gap] > arr[i])
                {
                    break;
                }
                else
                {
                    swap(&arr[i + gap], &arr[i]);
                }
            }
        }
    }
}

int main()
{

    int arr[] = {4, 3, 54, 65, 23, 62, 23, 54, 23, 78, 24, 45, 98, 32, 54};
    int n = sizeof(arr) / sizeof(int);

    shellSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
