#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
        }
    else if(data > root->data) {
        root->right = insert(root->right,data);
    }
    return root;
}


void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void displayTree(struct Node* root) {
    printf("In-Order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrder(root);
    printf("\n");
}


int main() {
    struct Node* root = NULL;
    int choice, value;

    printf("Binary Search Tree Operations:\n");
    printf("1. Insert element\n");
    printf("2. Display Tree (Traversals)\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                if (root == NULL) {
                    printf("The Tree is Empty\n");
                } else {
                    displayTree(root);
                }
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}
