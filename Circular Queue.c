#include <stdio.h>

void insert(int queue[], int *front, int *rear, int max_size, int element) {

    if ((*rear + 1) % max_size == *front) {
        printf("Queue Overflow\nQueue is Full\n");
    } else {

        *rear = (*rear + 1) % max_size;
        queue[*rear] = element;
        if (*front == -1) {
            *front = 0;
        }
        printf("The element %d is inserted into the queue\n", element);
    }
}

void delete(int queue[], int *front, int *rear, int max_size) {

    if (*front == -1) {
        printf("Queue Underflow\nQueue is Empty\n");
    } else {
        int deleted_element = queue[*front];
        printf("The element %d is deleted from the queue\n", deleted_element);
        if (*front == *rear) {
            *front = *rear = -1;
        } else {
            *front = (*front + 1) % max_size;
        }
    }
}

void display(int queue[], int front, int rear, int max_size) {

    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("The Queue elements are: \n");
        int i = front;
        while (1) {
            printf("%d\n", queue[i]);
            if (i == rear) break;
            i = (i + 1) % max_size;
        }
    }
}

int main() {
    int max_size;
    printf("Enter the size of the queue: ");
    scanf("%d", &max_size);

    int queue[max_size];
    int rear = -1;
    int front = -1;
    int element;
    int choice;

    printf("The Queue operations are: \n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to insert into the queue: ");
                scanf("%d", &element);
                insert(queue, &front, &rear, max_size, element);
                break;
            case 2:
                delete(queue, &front, &rear, max_size);
                break;
            case 3:
                display(queue, front, rear, max_size);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Enter a valid choice.\n");
                break;
        }
    }
}
