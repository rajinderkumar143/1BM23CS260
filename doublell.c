#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *);
void display(struct node *);
struct node *insert_after(struct node *);
struct node *delete_after(struct node *);

struct node *create_ll(struct node *start) {
    struct node *newnode, *ptr;
    int num;

    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);

    while (num != -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;

        if (start == NULL) {
            newnode->prev = NULL;
            start = newnode;
        } else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
        }

        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return start;
}

void display(struct node *start) {
    struct node *ptr = start;

    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to insert a node after a specific value
struct node *insert_after(struct node *start) {
    struct node *ptr, *newnode;
    int num, val;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    printf("\nEnter the value after which the node has to be inserted: ");
    scanf("%d", &val);

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", val);
        return start;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = ptr->next;
    newnode->prev = ptr;

    if (ptr->next != NULL) {
        ptr->next->prev = newnode;
    }
    ptr->next = newnode;

    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr, *temp;
    int val;

    printf("\nEnter the value after which the node has to be deleted: ");
    scanf("%d", &val);

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        printf("No node found to delete after the value %d.\n", val);
        return start;
    }

    temp = ptr->next;
    ptr->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = ptr;
    }

    free(temp);
    return start;
}

int main() {
    int choice = 0;

    printf("MENU\n");
    printf("1. Create List\n");
    printf("2. Display List\n");
    printf("3. Insert After\n");
    printf("4. Delete After\n");
    printf("5. Exit\n");

    while (choice != 5) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = create_ll(start);
                printf("Doubly linked list created successfully.\n");
                break;
            case 2:
                display(start);
                break;
            case 3:
                start = insert_after(start);
                break;
            case 4:
                start = delete_after(start);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
