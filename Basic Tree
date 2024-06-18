#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to print the binary tree in-order
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// Function to print the binary tree pre-order
void printPreOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Function to print the binary tree post-order
void printPostOrder(Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the height of the binary tree
int findHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int main() {
    Node* root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 13);

    // Print the binary tree in-order
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    // Print the binary tree pre-order
    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    // Print the binary tree post-order
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    // Find and print the height of the binary tree
    int height = findHeight(root);
    printf("Height of the binary tree: %d\n", height);

    return 0;
}
