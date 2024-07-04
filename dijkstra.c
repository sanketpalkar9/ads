#include <stdio.h>

#define INFINITY 9999
#define graphSize 9

int main(int argc, char const *argv[])
{

    int arr[graphSize][graphSize];
    int graphCost[graphSize][graphSize] = {
        0, 4, 0, 0, 8, 0, 0, 0, 0,
        4, 0, 8, 0, 11, 0, 0, 0, 0,
        0, 8, 0, 7, 0, 0, 4, 0, 2,
        0, 0, 7, 0, 0, 0, 14, 9, 0,
        8, 11, 0, 0, 0, 1, 0, 0, 7,
        0, 0, 0, 0, 1, 0, 2, 0, 6,
        0, 0, 4, 14, 0, 2, 0, 10, 0,
        0, 0, 0, 9, 0, 0, 0, 0, 0,
        0, 0, 2, 0, 7, 6, 0, 0, 0

    };

    int n = graphSize;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graphCost[i][j] == 0)
            {
                arr[i][j] = INFINITY;
            }
            else
            {
                arr[i][j] = graphCost[i][j];
            }
        }
    }
    printf("Adjency Matrix of cost of edges:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])

                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    printf("\n");
    printf("Adjacency matrix of lowest cost between the vertices:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
