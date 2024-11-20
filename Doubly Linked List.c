#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node* NODE;

NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createList(int data, NODE* head) {
    NODE newNode = createNode(data);
    *head = newNode;
}

void insertLeft(NODE* head, int data, int target) {
    NODE temp = *head;
    NODE newNode = createNode(data);

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target value not found in the list\n");
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }

    temp->prev = newNode;
}

void delete(NODE* head, int value) {
    NODE temp = *head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void display(NODE head) {
    NODE temp = head;
    printf("The Doubly Linked List elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;
    int choice, data, target;

    printf("\nDoubly Linked List Operations:\n");
    printf("1. Create List\n");
    printf("2. Insert Left\n");
    printf("3. Delete Node\n");
    printf("4. Display List\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                createList(data, &head);
                printf("List created %d.\n", data);
                break;

            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the target node data to insert before: ");
                scanf("%d", &target);
                insertLeft(&head, data, target);
                break;

            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                delete(&head, data);
                break;

            case 4:
                display(head);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
