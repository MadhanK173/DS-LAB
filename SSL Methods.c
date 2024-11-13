#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** first, int data) {
    struct Node* newNode = getNode(data);
    newNode->next = *first;
    *first = newNode;
}

void insertAtEnd(struct Node** first, int data) {
    struct Node* newNode = getNode(data);
    if (*first == NULL) {
        *first = newNode;
    } else {
        struct Node* temp = *first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(struct Node** first, int data, int position) {
    struct Node* newNode = getNode(data);

    if (position == 0) {
        newNode->next = *first;
        *first = newNode;
    } else {
        struct Node* temp = *first;
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

void display(struct Node* first) {
    struct Node* temp = first;
    if (temp == NULL) {
        printf("List is empty.\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void sort(struct Node* first) {
    struct Node* i, *j;
    int temp;
    for(i = first; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse(struct Node** first) {
    struct Node* prev = NULL;
    struct Node* current = *first;
    struct Node* next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *first = prev;
}

void concatenate(struct Node** first1, struct Node** first2) {
    if (*first1 == NULL) {
        *first1 = *first2;
    } else {
        struct Node* temp = *first1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *first2;
    }
}

int main() {
    int choice, data, position;
    struct Node* first = NULL;
    struct Node* secondList = NULL;
    int listChoice;

    printf("\nOperations:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Sort the list\n");
    printf("5. Reverse the list\n");
    printf("6. Concatenate the two lists\n");
    printf("7. Display the lists\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Which list to insert into? (1 = first list, 2 = second list): ");
                scanf("%d", &listChoice);
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                if (listChoice == 1) {
                    insertAtBeginning(&first, data);
                } else if (listChoice == 2) {
                    insertAtBeginning(&secondList, data);
                } else {
                    printf("Invalid list choice.\n");
                }
                break;

            case 2:
                printf("Which list to insert into? (1 = first list, 2 = second list): ");
                scanf("%d", &listChoice);
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                if (listChoice == 1) {
                    insertAtEnd(&first, data);
                } else if (listChoice == 2) {
                    insertAtEnd(&secondList, data);
                } else {
                    printf("Invalid list choice.\n");
                }
                break;

            case 3:
                printf("Which list to insert into? (1 = first list, 2 = second list): ");
                scanf("%d", &listChoice);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert data: ");
                scanf("%d", &position);
                if (listChoice == 1) {
                    insertAtPosition(&first, data, position);
                } else if (listChoice == 2) {
                    insertAtPosition(&secondList, data, position);
                } else {
                    printf("Invalid list choice.\n");
                }
                break;

            case 4:
                printf("Which list to sort? (1 = first list, 2 = second list): ");
                scanf("%d", &listChoice);
                if (listChoice == 1) {
                    sort(first);
                    printf("First list sorted.\n");
                } else if (listChoice == 2) {
                    sort(secondList);
                    printf("Second list sorted.\n");
                } else {
                    printf("Invalid list choice.\n");
                }
                break;

            case 5:
                printf("Which list to reverse? (1 = first list, 2 = second list): ");
                scanf("%d", &listChoice);
                if (listChoice == 1) {
                    reverse(&first);
                    printf("First list reversed.\n");
                } else if (listChoice == 2) {
                    reverse(&secondList);
                    printf("Second list reversed.\n");
                } else {
                    printf("Invalid list choice.\n");
                }
                break;

            case 6:
                concatenate(&first, &secondList);
                printf("Lists concatenated.\n");
                break;

            case 7:
                printf("First List: ");
                display(first);
                printf("Second List: ");
                display(secondList);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
