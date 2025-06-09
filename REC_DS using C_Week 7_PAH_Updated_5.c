
// You are required to implement a contact management system using hashing techniques. 


// The system should allow users to store and retrieve contact information based on names. The implementation should include hash table collision handling using chaining. 


// Write a program that accepts contact information and retrieves the contact number based on the provided name.
// Input format :

// The first line of input consists of an integer N, representing the number of contacts to be added.

// The following N lines consist of two space-separated strings each: the name (a non-empty string) and the phone number (a non-empty string), representing the name and phone number of a contact.

// The last line consists of a string, representing the name for which the phone number needs to be retrieved.
// Output format :

// The output prints "Phone number for X: Y", where X is the name and Y is the phone number associated with the given name.

// If the contact is not found, print "Phone number for X: Contact not found", where X is the name.


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// The hash table size is fixed to 100

// 1 ≤ N ≤ 10

// 1 ≤ phone number length ≤ 10

// 1 ≤ length of a contact ≤ 50

// Names are strings consisting of alphanumeric characters, without spaces.

// Phone numbers are strings of digits.
// Sample test cases :
// Input 1 :

// 3
// Alice 9632587415
// Bob 9876543210
// Carol 7412589636
// Alice

// Output 1 :

// Phone number for Alice: 9632587415

// Input 2 :

// 2
// John 8521479632
// Mary 9876543212
// Janice

// Output 2 :

// Phone number for Janice: Contact not found

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ContactNode {
    char name[50];
    char phone[11]; 
    struct ContactNode *next;
};


struct ContactNode *hashTable[100];


int hashFunction(const char *name) {
    int sum = 0;
    while (*name) {
        sum += *name++;
    }
    return sum % 100;
}


void insertContact(const char *name, const char *phone) {
    int index = hashFunction(name);

    
    struct ContactNode *newNode = (struct ContactNode *)malloc(sizeof(struct ContactNode));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        
        struct ContactNode *current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


const char* searchContact(const char *name) {
    int index = hashFunction(name);

    struct ContactNode *current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->phone; 
        }
        current = current->next;
    }

    return NULL; 
}

int main() {
   
    for (int i = 0; i < 100; i++) {
        hashTable[i] = NULL;
    }

    int n;
    scanf("%d", &n); 

    char name[50], phone[11];

    for (int i = 0; i < n; i++) {
        scanf("%s %s", name, phone);
        insertContact(name, phone);
    }

    char searchName[50];
    scanf("%s", searchName);

    const char *result = searchContact(searchName);

    if (result != NULL) {
        printf("Phone number for %s: %s\n", searchName, result);
    } else {
        printf("Phone number for %s: Contact not found\n", searchName);
    }

    return 0;
}