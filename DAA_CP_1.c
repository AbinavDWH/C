// Find Duplicate in Array.

// Given a read only array of n integers between 1 and n, find one number that repeats.

// Input Format:

// First Line - Number of elements

// n Lines - n Elements
// Output Format:

// Element x - That is repeated

// For example:
// Input 	Result

// 5
// 1 1 2 3 4

	

// 1

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int tortoise = arr[0];
    int hare = arr[arr[0]];

    while (tortoise != hare) {
        tortoise = arr[tortoise];
        hare = arr[arr[hare]];
    }

    tortoise = 0;
    while (tortoise != hare) {
        tortoise = arr[tortoise];
        hare = arr[hare];
    }

    printf("%d\n", hare);

    free(arr);
    return 0;
}