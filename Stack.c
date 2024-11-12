#include<stdio.h>

void push(int stack[], int *top, int max_size, int element) {
    if(*top >= max_size - 1) {
        printf("Stack Overflow\nStack is Full");
    }
    else {
        (*top)++;
        stack[*top] = element;
        printf("The element %d is pushed to the stack",element);
    }
}

void pop(int stack[], int *top) {
    if(*top == -1) {
        printf("Stack Underflow\nStack is Empty");
    }
    else {

        int popped_element = stack[*top];
        (*top)--;
        printf("The element %d is popped from the stack",popped_element);
    }
}

void display(int stack[], int *top) {
    if(*top == -1) {
        printf("Stack is Empty");
    }
    else {
        printf("The stack elements are : \n");
        for(int i=*top; i>-1; i--) {
            printf("%d\n",stack[i]);
        }
    }
}

int main() {

    int top = -1;
    int choice;
    int element;
    int max_size;

    printf("Enter the size of a stack : ");
    scanf("%d",&max_size);
    int stack[max_size];

    printf("The stack operations are : \n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display\n");

    while (1) {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1 : printf("Enter an element to push to the stack : ");
                     scanf("%d",&element);
                     push(stack,&top,max_size,element);
                     break;
            case 2 : pop(stack,&top);
                     break;
            case 3 : display(stack,&top);
                     break;
            default : printf("Invalid choice\nEnter an valid choice");
                     break;
        }
    }
}
