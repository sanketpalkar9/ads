// It doesnt have errors it just looks like it


// Radix sort is nothing but counting Sort on all the digits


#include <stdio.h>
int getMax(int arr[], int n)
{

    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int pos, int n)
{

    int count[10] = {0}; // ten digits 0 to 9

    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }

    for (int i = 1; i <= 9; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    int b[n];
    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
}
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int pos = 1; max / pos > 0; pos = pos * 10)
    {
        countingSort(arr, pos, n);
    }
}

int main()
{

    int arr[] = {902, 102, 12, 2, 544, 423, 120, 23, 821, 327, 723, 129, 542, 10, 231, 29};

    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
