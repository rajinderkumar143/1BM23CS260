#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 

int hash_table[TABLE_SIZE] = {0}; 

int is_empty(int index) {
    return hash_table[index] == 0;
}

int hash_function(int key) {
    return key % TABLE_SIZE;
}


void insert() {
    int key, index;
    printf("\nEnter a value to insert into hash table: ");
    scanf("%d", &key);

    int hash_key = hash_function(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hash_key + i) % TABLE_SIZE; 
        if (is_empty(index)) {
            hash_table[index] = key;
            printf("Inserted %d at index %d with %d probes.\n", key, index, i + 1);
            return;
        }
    }
    printf("Hash table is full. Cannot insert %d.\n", key); 
}

void search() {
    int key, index;
    printf("\nEnter a value to search: ");
    scanf("%d", &key);

    int hash_key = hash_function(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hash_key + i) % TABLE_SIZE; 
        if (hash_table[index] == key) {
            printf("Key %d found at index %d with %d probes.\n", key, index, i + 1);
            return;
        }
        if (is_empty(index)) { 
            break;
        }
    }
    printf("Key %d not found in the hash table.\n", key);
}

void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %d\n", i, hash_table[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Hashing with Linear Probing ===\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
