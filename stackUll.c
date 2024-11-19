#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL, *top1, *temp;

void push(int x) {
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("Node is inserted\n");
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1;  
    }
    top1 = top;
    top = top->next;
    int popped = top1->data;
    free(top1);
    return popped;
}

void display() {
    top1 = top;
    if (top1 == NULL) {
        printf("\nStack underflow\n");
        return;
    }
    printf("The stack is:\n");
    while (top1 != NULL) {
        printf("%d-->", top1->data);
        top1 = top1->next;
    }
    printf("NULL\n");
}

int main() {
    int choice = 0, value;
    while (choice != 4) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) { 
                    printf("Popped element is: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
