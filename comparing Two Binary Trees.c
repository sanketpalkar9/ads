#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int compareBT(struct node *A, struct node *B) {
    if (A == NULL && B == NULL) {
        return 1; // Both trees are empty
    }

    if (A == NULL || B == NULL) {
        return 0; // One tree is empty, and the other is not
    }

    if (A->data != B->data) {
        return 0; // Data at the current node is different
    }

    // Compare the left and right subtrees
    return compareBT(A->left, B->left) && compareBT(A->right, B->right);
}

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    struct node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if (compareBT(root1, root2)) {
        printf("The trees are identical.\n");
    } else {
        printf("The trees are not identical.\n");
    }

    return 0;
}
