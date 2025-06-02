// You are tasked with implementing a hash table to store student roll numbers and their corresponding marks using linear probing for collision handling. The hash table will support three operations:



// Insert: Insert a student's roll number and marks into the hash table.
// Delete: Delete a student's record.
// Search: Search for a student's record.


// The hash table will be used to efficiently store and query student roll numbers. Each student's roll number is an integer, and their marks are also integers.

// Input format :
// The first line contains an integer N, the size of the hash table.

// The second line contains an integer M, the number of operations.

// The next M lines describe the operations:

// "Insert R M": Insert roll number R and marks M.
// "Delete R": Delete the record with roll number R.
// "Search R": Search for the student with roll number R.
// Output format :
// For each "Insert R M" operation, output "Inserted R".

// For each "Delete R" operation:

// If the record is found, output "Deleted R".
// If not found, output "Not Found R".
// For each "Search R" operation:

// If found, output "Found R".
// If not found, output "Not Found R".


// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases
#include <stdio.h>
#include <string.h>

#define EMPTY -1 // Indicates an empty slot
#define DELETED -2 // Indicates a deleted slot

typedef struct {
    int rollNumber;
    int marks;
} HashTableEntry;

void initializeHashTable(HashTableEntry hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i].rollNumber = EMPTY;
        hashTable[i].marks = 0;
    }
}

int hashFunction(int rollNumber, int size) {
    return rollNumber % size;
}

void insert(HashTableEntry hashTable[], int size, int rollNumber, int marks) {
    int index = hashFunction(rollNumber, size);
    int originalIndex = index;

    while (hashTable[index].rollNumber != EMPTY && hashTable[index].rollNumber != DELETED) {
        index = (index + 1) % size;
        if (index == originalIndex) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index].rollNumber = rollNumber;
    hashTable[index].marks = marks;
    printf("Inserted %d\n", rollNumber);
}

void delete(HashTableEntry hashTable[], int size, int rollNumber) {
    int index = hashFunction(rollNumber, size);
    int originalIndex = index;

    while (hashTable[index].rollNumber != EMPTY) {
        if (hashTable[index].rollNumber == rollNumber) {
            hashTable[index].rollNumber = DELETED;
            hashTable[index].marks = 0;
            printf("Deleted %d\n", rollNumber);
            return;
        }
        index = (index + 1) % size;
        if (index == originalIndex) {
            break;
        }
    }

    printf("Not Found %d\n", rollNumber);
}

void search(HashTableEntry hashTable[], int size, int rollNumber) {
    int index = hashFunction(rollNumber, size);
    int originalIndex = index;

    while (hashTable[index].rollNumber != EMPTY) {
        if (hashTable[index].rollNumber == rollNumber) {
            printf("Found %d\n", rollNumber);
            return;
        }
        index = (index + 1) % size;
        if (index == originalIndex) {
            break;
        }
    }

    printf("Not Found %d\n", rollNumber);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    HashTableEntry hashTable[N];
    initializeHashTable(hashTable, N);

    for (int i = 0; i < M; i++) {
        char operation[10];
        int rollNumber, marks;

        scanf("%s", operation);

        if (strcmp(operation, "Insert") == 0) {
            scanf("%d %d", &rollNumber, &marks);
            insert(hashTable, N, rollNumber, marks);
        } else if (strcmp(operation, "Delete") == 0) {
            scanf("%d", &rollNumber);
            delete(hashTable, N, rollNumber);
        } else if (strcmp(operation, "Search") == 0) {
            scanf("%d", &rollNumber);
            search(hashTable, N, rollNumber);
        }
    }

    return 0;
}

