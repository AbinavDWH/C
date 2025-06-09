// Neha is developing a program to merge two dictionaries containing words and their respective frequencies. 



// Guide her with a program that takes input for two dictionaries, merges them while ensuring no duplicate keys, and prints the resulting merged dictionary using hashing.

// Input format :
// The first line consists of an integer n, indicating the number of key-value pairs in the first dictionary.

// The next n lines consist of a string 'key' and an integer 'value', separated by a space, representing the key-value pairs in the first dictionary.

// The next line consists of an integer m, indicating the number of key-value pairs in the second dictionary.

// The following m lines consist of a string 'key' and an integer 'value', separated by a space, representing the key-value pairs in the first dictionary.

// Output format :
// The first line prints "Merged Dictionary:".

// The following lines print the key-value pairs in the merged dictionary, maintaining the insertion order from the first dictionary followed by any new keys from the second dictionary.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ m, n ≤ 10

// The keys are case-sensitive.

// 3 ≤ Length of the keys ≤ 100

// Sample test cases :
// Input 1 :
// 3
// Hello 10
// Hi 78 
// Today 77
// 4
// Here 77
// 123 44
// Over 14
// Runs 0
// Output 1 :
// Merged Dictionary:
// Hello 10
// Hi 78
// Today 77
// Here 77
// 123 44
// Over 14
// Runs 0
// Input 2 :
// 2
// Monday 20
// Tuesday 10
// 2
// Tuesday 10
// Wednesday 30
// Output 2 :
// Merged Dictionary:
// Monday 20
// Tuesday 10
// Wednesday 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100

typedef struct KeyValuePair {
    char *key;
    int value;
    struct KeyValuePair *next;
} KeyValuePair;

typedef struct {
    KeyValuePair *head;
} HashBucket;

typedef struct {
    HashBucket *buckets;
    int size;
} HashTable;

typedef struct {
    char **keys;
    int count;
} OrderedList;

// Function Prototypes
unsigned int hash(const HashTable *table, const char *key);
void initHashTable(HashTable *table, int size);
void destroyHashTable(HashTable *table);
int insertIfNotExists(HashTable *table, OrderedList *order, const char *key, int value);
void printMergedDictionary(const OrderedList *order, const HashTable *table);

int main() {
    int n, m;

    // Initialize hash tables and ordered list
    HashTable table;
    OrderedList order;
    order.keys = (char **)malloc(MAX_KEYS * sizeof(char *));
    order.count = 0;

    initHashTable(&table, MAX_KEYS);

    // Read first dictionary
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char key[101];
        int value;
        scanf("%s %d", key, &value);
        insertIfNotExists(&table, &order, key, value);
    }

    // Read second dictionary
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char key[101];
        int value;
        scanf("%s %d", key, &value);
        insertIfNotExists(&table, &order, key, value);
    }

    // Print result
    printf("Merged Dictionary:\n");
    printMergedDictionary(&order, &table);

    // Cleanup
    destroyHashTable(&table);
    for (int i = 0; i < order.count; i++) {
        free(order.keys[i]);
    }
    free(order.keys);

    return 0;
}

// Hash function
unsigned int hash(const HashTable *table, const char *key) {
    unsigned long int hash_val = 0;
    for (; *key != '\0'; key++) {
        hash_val = hash_val * 37 + *key;
    }
    return hash_val % table->size;
}

// Initialize hash table
void initHashTable(HashTable *table, int size) {
    table->size = size;
    table->buckets = (HashBucket *)calloc(size, sizeof(HashBucket));
}

// Destroy hash table to avoid memory leaks
void destroyHashTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        KeyValuePair *current = table->buckets[i].head;
        while (current != NULL) {
            KeyValuePair *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table->buckets);
}

// Insert if not exists
int insertIfNotExists(HashTable *table, OrderedList *order, const char *key, int value) {
    unsigned int index = hash(table, key);
    KeyValuePair *current = table->buckets[index].head;

    // Check if key already exists
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 0; // Key exists
        }
        current = current->next;
    }

    // Key does not exist — insert it
    KeyValuePair *newPair = (KeyValuePair *)malloc(sizeof(KeyValuePair));
    newPair->key = strdup(key);
    newPair->value = value;
    newPair->next = table->buckets[index].head;
    table->buckets[index].head = newPair;

    // Store the key in order list
    order->keys[order->count] = strdup(key);
    order->count++;

    return 1; // Inserted successfully
}

// Print merged dictionary
void printMergedDictionary(const OrderedList *order, const HashTable *table) {
    for (int i = 0; i < order->count; i++) {
        const char *key = order->keys[i];
        unsigned int index = hash(table, key);
        KeyValuePair *current = table->buckets[index].head;

        while (current != NULL) {
            if (strcmp(current->key, key) == 0) {
                printf("%s %d\n", current->key, current->value);
                break;
            }
            current = current->next;
        }
    }
}