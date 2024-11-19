#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOverflow\n");
        return;
    }
    ptr->data = item;
    ptr->next = NULL;

    if (rear == NULL) {
        front = ptr;
        rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("%d is inserted\n", item);
}

void delete() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    } else {
        struct node *temp = front;
        front = front->next;
        printf("%d is deleted\n", temp->data);
        if (front == NULL) {
            rear = NULL; 
        }
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *ptr = front;
    printf("Queue: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice = 0, value;

    while (choice != 4) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
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
