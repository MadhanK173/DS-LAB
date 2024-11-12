#include<stdio.h>

void insert(int queue[], int *rear, int max_size, int element) {
    if(*rear >= max_size - 1) {
        printf("Queue Overflow\nQueue is Full");
    }
    else {
        (*rear)++;
        queue[*rear] = element;
        printf("The element %d is inserted into the queue",element);
    }
}

void delete(int queue[], int *front, int max_size) {
    if(*front >= max_size - 1) {
        printf("Queue Underflow\nQueue is Empty");
    }
    else {
        int delete_element = queue[*front];
        printf("The element %d is deleted from the queue",delete_element);
        (*front)++;
    }
}

void display(int queue[], int *rear, int *front, int max_size) {
    if(*rear == -1 || *front >= max_size - 1) {
        printf("Queue is Empty");
    }
    else {
        printf("The Queue elements are : \n");
        for(int i = *front; i <= *rear; i++) {
            printf("%d\n",queue[i]);
        }
    }
}

int main() {
    int max_size;
    printf("Enter the size of a queue : ");
    scanf("%d",&max_size);
    int queue[max_size];
    int rear = -1;
    int front = 0;
    int element;
    int choice;

    printf("The Queue operations are : \n");
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");

    while (1) {
        printf("\nEnter your choice :");
        scanf("%d",&choice);

        switch(choice) {
            case 1 : printf("Enter an element to insert into queue : ");
                     scanf("%d",&element);
                     insert(queue,&rear,max_size,element);
                     break;
            case 2 : delete(queue,&front,max_size);
                     break;
            case 3 : display(queue,&rear,&front,max_size);
                     break;
            default : printf("Invalid choice\nEnter a valid choice");
                     break;
        }
    }
}
