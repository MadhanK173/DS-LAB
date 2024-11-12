#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* first = NULL;

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    struct Node* newNode = getNode(data);
    newNode->next = first;
    first = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = getNode(data);

    if (first == NULL) {
        first = newNode;
    } else {
        struct Node* temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(int data, int position) {
    struct Node* newNode = getNode(data);

    if (position == 0) {
        newNode->next = first;
        first = newNode;
    } else {
        struct Node* temp = first;
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of range.\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteAtBeginning() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = first;
    first = first->next;
    free(temp);
}

void deleteAtEnd() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (first->next == NULL) {
        free(first);
        first = NULL;
    } else {
        struct Node* temp = first;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAtPosition(int position) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = first;

    if (position == 0) {
        first = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}



void display() {
    struct Node* temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, data, position;
    printf("\nOperations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");


    while (1) {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert data: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                display();
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
