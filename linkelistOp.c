#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(struct node **head) {
    struct node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sortList(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return; 
    }

    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void concatenate(struct node **head1, struct node *head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct node *temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert at the end (list1)\n");
        printf("2. Insert at the end (list2)\n");
        printf("3. Display list1\n");
        printf("4. Display list2\n");
        printf("5. Reverse list1\n");
        printf("6. Sort list1\n");
        printf("7. Concatenate list1 and list2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter value to insert into list1: ");
                scanf("%d", &value);
                struct node *newNode = createNode(value);
                if (list1 == NULL) {
                    list1 = newNode;
                } else {
                    struct node *temp = list1;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
                break;
            }
            case 2: {
                printf("Enter value to insert into list2: ");
                scanf("%d", &value);
                struct node *newNode = createNode(value);
                if (list2 == NULL) {
                    list2 = newNode;
                } else {
                    struct node *temp = list2;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
                break;
            }
            case 3:
                printf("List1: ");
                display(list1);
                break;
            case 4:
                printf("List2: ");
                display(list2);
                break;
            case 5:
                reverse(&list1);
                printf("List1 reversed.\n");
                break;
            case 6:
                sortList(list1);
                printf("List1 sorted.\n");
                break;
            case 7:
                concatenate(&list1, list2);
                printf("Lists concatenated.\n");
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
