// This code implements the simple hashing using table size as 10

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct node
{
    int data;
    struct node *next;
};

struct node *table[TABLE_SIZE]; // Array of pointers to nodes

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insert(int value)
{
    int location = (2 * value + 3) % TABLE_SIZE;

    struct node *newNode = createNode(value);
    if (table[location] == NULL)
    {
        table[location] = newNode;
    }
    else
    {
        struct node *temp = table[location];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int search(int value)
{
    int location = (2 * value + 3) % TABLE_SIZE;
    struct node *temp = table[location];
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("table[%d]: ", i);
        struct node *temp = table[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int value, n;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    printf("Enter number of elements you want to insert: ");
    scanf("%d", &n);

    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }

    // Display the hash table
    display();

    // Search for a value in the hash table
    printf("Enter value to search: ");
    scanf("%d", &value);
    if (search(value))
    {
        printf("%d found in the hash table.\n", value);
    }
    else
    {
        printf("%d not found in the hash table.\n", value);
    }

    // Free allocated memory
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct node *temp = table[i];
        while (temp != NULL)
        {
            struct node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}
