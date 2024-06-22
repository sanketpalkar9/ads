#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("Sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{

    int arr[] = {4, 3, 54, 65, 23, 62, 23, 54, 23, 78, 24, 45, 98, 32, 54};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);
}
