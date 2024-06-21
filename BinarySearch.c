*/ Binary Search using sorted array */


#include <stdio.h>

int main()
{

    int arr[] = {2, 15, 16, 25, 36, 46, 57, 61, 73, 83, 91};

    int n = 11;
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;

    int data;
    printf("Enter a number to search: ");
    scanf("%d", &data);
    while (l < r)
    {
        if (data == arr[mid])
        {
            printf("Element found at index %d", mid);
            break;
        }
        else if (data > arr[mid])
        {
            l = mid + 1;
            mid = (l + r) / 2;
        }
        else if (data < arr[mid])
        {
            r = mid - 1;
            mid = (l + r) / 2;
        }
    }
    if (l >= r)
    {
        printf("Element found not found");
    }

    return 0;
}
