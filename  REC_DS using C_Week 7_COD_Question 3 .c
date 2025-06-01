// in a messaging application, users maintain a contact list with names and corresponding phone numbers. Develop a program to manage this contact list using a dictionary implemented with hashing. 


// The program allows users to add contacts, delete contacts, and check if a specific contact exists. Additionally, it provides an option to print the contact list in the order of insertion.
// Input format :

// The first line consists of an integer n, representing the number of contact pairs to be inserted.

// Each of the next n lines consists of two strings separated by a space: the name of the contact (key) and the corresponding phone number (value).

// The last line contains a string k, representing the contact to be checked or removed.
// Output format :

// If the given contact exists in the dictionary:

//     The first line prints "The given key is removed!" after removing it.
//     The next n - 1 lines print the updated contact list in the format: "Key: X; Value: Y" where X represents the contact's name and Y represents the phone number.


// If the given contact does not exist in the dictionary:

//     The first line prints "The given key is not found!".
//     The next n lines print the original contact list in the format: "Key: X; Value: Y" where X represents the contact's name and Y represents the phone number.


// Refer to the sample outputs for the formatting specifications.
// Code constraints :

// In this scenario, the test cases fall under the following constraints:

// 2 ≤ n ≤ 50

// The keys are case-sensitive.

// 3 ≤ Length of the input strings, k ≤ 10
// Sample test cases :
// Input 1 :

// 3
// Alice 1234567890
// Bob 9876543210
// Charlie 4567890123
// Bob

// Output 1 :

// The given key is removed!
// Key: Alice; Value: 1234567890
// Key: Charlie; Value: 4567890123

// Input 2 :

// 2
// Quinn 1112223333
// Roger 2223334444
// Sarah 

// Output 2 :

// The given key is not found!
// Key: Quinn; Value: 1112223333
// Key: Roger; Value: 2223334444

// You are using GCC
#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char key[11];
    char value[20];
    int isActive; // 1 if the entry is active, 0 if deleted
} Contact;

int main() {
    int n;
    scanf("%d", &n);

    Contact contacts[MAX];
    int count = 0;

    // Read contacts
    for (int i = 0; i < n; i++) {
        scanf("%s %s", contacts[i].key, contacts[i].value);
        contacts[i].isActive = 1;
    }
    count = n;

    // Read key to remove
    char toRemove[11];
    scanf("%s", toRemove);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (contacts[i].isActive && strcmp(contacts[i].key, toRemove) == 0) {
            contacts[i].isActive = 0;
            found = 1;
            printf("The given key is removed!\n");
            break;
        }
    }

    if (!found) {
        printf("The given key is not found!\n");
    }

    
    for (int i = 0; i < count; i++) {
        if (contacts[i].isActive) {
            printf("Key: %s; Value: %s\n", contacts[i].key, contacts[i].value);
        }
    }

    return 0;
}
