/* This code is about Binary Search Tree
This includes:
1)Creation
2)Deletion
3)Searching
4)Traversal
5)Height of tree

*/



#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
struct node {
    int data;
    struct node *right, *left;
};

// Function to create a new node in the BST
struct node *create(struct node *root, int x) {
    if (root == NULL) {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->left = newnode->right = NULL;
        root = newnode;
    } else if (root->data > x) {
        root->left = create(root->left, x);
    } else if (root->data < x) {
        root->right = create(root->right, x);
    } else {
        printf("Duplicate node\n");
    }
    return root;
}

// Function to delete a node from the BST
struct node *deletenode(struct node *root, int k) {
    if (root == NULL)
        return root;

    if (k < root->data) {
        root->left = deletenode(root->left, k);
        return root;
    } else if (k > root->data) {
        root->right = deletenode(root->right, k);
        return root;
    }

    if (root->left == NULL) {
        struct node *temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL) {
        struct node *temp = root->left;
        free(root);
        return temp;
    }

    struct node *succParent = root;
    struct node *succ = root->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    root->data = succ->data;

    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;

    free(succ);
    return root;
}

// Function to find the height of the BST
int findHeight(struct node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int lheight = findHeight(root->left);
        int rheight = findHeight(root->right);
        if (lheight > rheight) {
            return lheight + 1;
        } else {
            return rheight + 1;
        }
    }
}

// Function for in-order traversal of the BST
void inorder(struct node *root) {
    if (root == 0) {
        return;
    }
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

// Function to find the inorder predecessor of a node
struct node *inorderPred(struct node *root) {
    if (root == NULL || root->left == NULL) {
        return NULL;
    }
    struct node *current = root->left;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Function to find the inorder successor of a node
struct node *inorderSucc(struct node *root) {
    if (root == NULL || root->right == NULL) {
        return NULL;
    }
    struct node *current = root->right;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function for post-order traversal of the BST
void postorder(struct node *root) {
    if (root == 0) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->data);
}

// Function for pre-order traversal of the BST
void preorder(struct node *root) {
    if (root == 0) {
        return;
    }
    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to search for an element in the BST
void search(struct node *root, int x) {
    if (root == NULL) {
        printf("Element not found\n");
    } else if (root->data == x) {
        printf("Element found\n");
        return;
    } else if (root->data > x) {
        return search(root->left, x);
    } else if (root->data < x) {
        return search(root->right, x);
    }
}

// Main function
int main() {
    struct node *root = NULL;
    int choice;

    while (1) {
        printf("Choice: \n");
        printf("1 -> New data\n");
        printf("-1 -> Exit\n");
        printf("-2 -> Delete data\n");
        printf("-3 -> Traversal\n");
        printf("-4 -> Search\n");
        printf("-5 -> Height\n:");
        scanf("%d", &choice);

        if (choice == -1) {
            break;
        } else if (choice == -2) {
            int i;
            printf("Enter element to delete: ");
            scanf("%d", &i);
            root = deletenode(root, i);
        } else if (choice == 1) {
            int x;
            printf("Enter data: ");
            scanf("%d", &x);
            root = create(root, x);
        } else if (choice == -3) {
            int v;
            printf("Enter traversal choice: \n");
            printf("1 -> Preorder\n2 -> Inorder\n3 -> Postorder\n");
            scanf("%d", &v);
            switch (v) {
            case 1:
                preorder(root);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
        } else if (choice == -4) {
            int u;
            printf("Enter element to search: ");
            scanf("%d", &u);
            search(root, u);
        } else if (choice == -5) {
            printf("Height of the tree is %d\n", findHeight(root));
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
