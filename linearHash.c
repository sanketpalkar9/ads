#include <stdio.h>

#define TABLE_SIZE 10
int HashTable[TABLE_SIZE];

void initialize_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashTable[i] = -1; // Initialize with -1 to indicate empty slots
    }
}

void insert(int value)
{
    int location = (2 * value + 3) % TABLE_SIZE;
    int i = 0;

    while (HashTable[location] != -1)
    {
        location = (location + 1) % TABLE_SIZE; // Increment by 1 for linear probing
    }
    HashTable[location] = value;
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("table[%d]: ", i);
        if (HashTable[i] == -1)
        {
            printf("NULL\n");
        }
        else
        {
            printf("%d\n", HashTable[i]);
        }
    }
}

void search(int value)
{
    int location = (2 * value + 3) % TABLE_SIZE;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int current_location = (location + i) % TABLE_SIZE;
        if (HashTable[current_location] == -1)
        {
            break; // If an empty slot is found, the value is not in the table
        }
        if (HashTable[current_location] == value)
        {
            printf("Element %d found at index %d\n", value, current_location);
            return;
        }
    }
    printf("Element %d not found\n", value);
}

int main()
{
    initialize_table();

    int n;
    int value;
    printf("Enter number of elements you want to insert: ");
    scanf("%d", &n);

    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }

    display();
    search(12);
    search(5);

    return 0;
}
