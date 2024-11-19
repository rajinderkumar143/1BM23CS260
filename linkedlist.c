#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);

int main()
{
    int choice;
    printf("MENU\n 1.create_ll\n 2.display\n 3.insert_beg\n 4. insert_end\n 5.insert_after\n 6.delete_beg\n 7.delete_end\n 8. delete_after\n 9.exit\n");
    while(choice != 9){
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: start = create_ll(start);
            printf("Linkedlist created successfully");
            break;
            case 2: start = display(start);
            break;
            case 3: start = insert_beg(start);
            break;
            case 4: start = insert_end(start);
            break;
            case 5: start = insert_after(start);
            break;
            case 6: start = delete_beg(start);
            break;
            case 7: start = delete_end(start);
            break;
            case 8: start = delete_after(start);
            break;
            default: printf("Invalid choice");
        }
    }
    return 0;
}

struct node *create_ll(struct node *start){
    struct node *new_node , *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data:");
    scanf("%d",&num);
    while(num != -1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if(start == NULL){
            start = new_node;
        }
        else{
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
        }
        ptr->next = new_node;
    }
        printf("Enter the data:\n");
        scanf("%d",&num);

    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    if(ptr == NULL){
        printf("Linkedlist is empty.\n");
    }
    printf("Linkedlist contents:");
    while(ptr != NULL){
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node;
    int num;
    printf("Enter the data:\n");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *new_node , *ptr;
    int num;
    printf("Enter the data:\n");
    scanf("%d",&num);
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    if(start == NULL){
        start = new_node;
    }
    else{
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    }
    return start;
}

struct node *insert_after(struct node *start){
    struct node *new_node , *ptr , *preptr;
    int num , val;
    printf("Enter the data:\n");
    scanf("%d",&num);
    printf("Enter the value where data has to be inserted:\n");
    scanf("%d",&val);
    ptr = start;
    preptr = ptr;
    while(preptr->data != val){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next  = new_node;
    new_node->next = ptr;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    printf("Node deleted from the beginning.\n");
    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    printf("Node deleted from the end.\n");
    return start;
}

struct node *delete_after(struct node *start){
    struct node *ptr , *preptr;
    int val;
    printf("Enter the value after which node has to be deleted:\n");
    scanf("%d",&val);
    ptr = start;
    preptr = ptr;
    while(preptr->data != val){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    printf("Node delete.\n");
    return start;
}
