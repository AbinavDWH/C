// Aryan is learning about hash tables using linear probing. He wants to build a hash table that supports the following operations:



// Insert: Places a key into the table using linear probing.
// Delete: Marks a key as deleted using a placeholder -2 (not removed completely).
// Search: Checks if a key is present in the table.


// If a collision occurs during insertion, he uses linear probing to resolve it. If a slot is marked as -2, it is considered deleted and reusable for future insertions.



// Implement a program that performs these operations and displays the final state of the hash table.

// Input format :
// The first line of the input contains a single integer size — the size of the hash table.

// The second line contains an integer n — the number of operations to be performed.

// The next n lines each contain an operation:

// insert x — insert the value x
// delete x — delete the value x
// search x — search for the value x
// Output format :
// For each search operation, print either: Value x found or Value x not found

// After all operations, print the final hash table with each slot separated by a space:

// Use "EMPTY" for an unused slot
// Use "DELETED" for a deleted slot


// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ size ≤ 100

// 1 ≤ n ≤ 100

// 0 ≤ x ≤ 10^3

// Sample test cases :
// Input 1 :
// 5
// 6
// insert 5
// insert 10
// insert 15
// delete 10
// search 10
// search 5
// Output 1 :
// Value 10 not found
// Value 5 found
// 5 DELETED 15 EMPTY EMPTY 
// Input 2 :
// 5
// 5
// insert 10
// insert 15
// insert 20
// search 15
// search 30
// Output 2 :
// Value 15 found
// Value 30 not found
// 10 15 20 EMPTY EMPTY 
// Input 3 :
// 4
// 6
// insert 1
// insert 5
// insert 9
// delete 5
// insert 13
// search 13
// Output 3 :
// Value 13 found
// EMPTY 1 13 9 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define EMPTY -1
#define DELETED -2

int hash_table[MAX_SIZE];
int table_size;

// Hash function
int hash(int key) {
    return key % table_size;
}

// Insert function using linear probing
void insert(int key) {
    for (int i = 0; i < table_size; i++) {
        int index = (hash(key) + i) % table_size;
        if (hash_table[index] == EMPTY || hash_table[index] == DELETED) {
            hash_table[index] = key;
            return;
        }
    }
    printf("Hash table full. Cannot insert %d\n", key);
}

// Delete function
void delete(int key) {
    for (int i = 0; i < table_size; i++) {
        int index = (hash(key) + i) % table_size;
        if (hash_table[index] == EMPTY) {
            return; // Not found
        } else if (hash_table[index] == key) {
            hash_table[index] = DELETED;
            return;
        }
    }
}

// Search function
int search(int key) {
    for (int i = 0; i < table_size; i++) {
        int index = (hash(key) + i) % table_size;
        if (hash_table[index] == EMPTY) {
            return 0; // Not found
        } else if (hash_table[index] == key) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

int main() {
    scanf("%d", &table_size);

    // Initialize hash table
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = EMPTY;
    }

    int n;
    scanf("%d", &n);

    char operation[10];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", operation, &value);

        if (strcmp(operation, "insert") == 0) {
            insert(value);
        } else if (strcmp(operation, "delete") == 0) {
            delete(value);
        } else if (strcmp(operation, "search") == 0) {
            if (search(value)) {
                printf("Value %d found\n", value);
            } else {
                printf("Value %d not found\n", value);
            }
        }
    }

    // Print final state of the hash table
    for (int i = 0; i < table_size; i++) {
        if (hash_table[i] == EMPTY)
            printf("EMPTY ");
        else if (hash_table[i] == DELETED)
            printf("DELETED ");
        else
            printf("%d ", hash_table[i]);
    }
    printf("\n");

    return 0;
}