// Ravi is analyzing the performance of a hash function by checking how often collisions occur when inserting data. He uses a hash table with linear probing to resolve collisions. For every insertion, if the hashed index is already occupied, it counts as a collision and the algorithm tries the next index.



// Write a program to insert n elements into a hash table using linear probing and count how many collisions occur in total during the insertions.

// Input format :
// The first line of the input contains two integers n and table_size — the number of elements and the size of the hash table.

// The second line contains n space-separated integers — the elements to insert.

// Output format :
// The output should print:

// Total Collisions: <number>

// Hash Table:

// index_0: value

// index_1: value

// ...

// If an index is empty, print: index_x: -1



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// 1 ≤ table_size ≤ 100

// 0 ≤ value ≤ 9999

// Sample test cases :
// Input 1 :
// 4 5
// 1 6 11 16
// Output 1 :
// Total Collisions: 3
// Hash Table:
// index_0: -1
// index_1: 1
// index_2: 6
// index_3: 11
// index_4: 16
// Input 2 :
// 5 7
// 10 17 24 3 10
// Output 2 :
// Total Collisions: 4
// Hash Table:
// index_0: 10
// index_1: -1
// index_2: -1
// index_3: 10
// index_4: 17
// index_5: 24
// index_6: 3

#include <stdio.h>

void initializeHashTable(int hashTable[], int table_size) {
    for (int i = 0; i < table_size; i++) {
        hashTable[i] = -1; // Initialize all indices to -1 (empty)
    }
}

int hashFunction(int value, int table_size) {
    return value % table_size; // Compute the hash index
}

int insertIntoHashTable(int hashTable[], int table_size, int value) {
    int index = hashFunction(value, table_size);
    int collisions = 0;

    while (hashTable[index] != -1) { // Resolve collision using linear probing
        collisions++;
        index = (index + 1) % table_size; // Move to the next index
        if (collisions >= table_size) { // Prevent infinite loop if table is full
            printf("Hash table is full, cannot insert %d\n", value);
            return collisions;
        }
    }

    hashTable[index] = value; // Insert the value into the hash table
    return collisions; // Return the number of collisions for this insertion
}

void printHashTable(int hashTable[], int table_size) {
    printf("Hash Table:\n");
    for (int i = 0; i < table_size; i++) {
        printf("index_%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, table_size;
    scanf("%d %d", &n, &table_size);

    int hashTable[table_size];
    initializeHashTable(hashTable, table_size);

    int values[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]); // Input the elements to insert
    }

    int totalCollisions = 0;
    for (int i = 0; i < n; i++) {
        totalCollisions += insertIntoHashTable(hashTable, table_size, values[i]);
    }

    printf("Total Collisions: %d\n", totalCollisions);
    printHashTable(hashTable, table_size);

    return 0;
}