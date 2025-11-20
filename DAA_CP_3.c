// Find the intersection of two sorted arrays.

// OR in other words,

// Given 2 sorted arrays, find all the elements which occur in both the arrays. 

// Input Format

// ·       The first line contains T, the number of test cases. Following T lines contain:

// 1.     Line 1 contains N1, followed by N1 integers of the first array

// 2.     Line 2 contains N2, followed by N2 integers of the second array

// Output Format

// The intersection of the arrays in a single line

// Example

// Input:

// 1

// 3 10 17 57

// 6 2 7 10 15 57 246

// Output:

// 10 57

// Input:

// 1

// 6 1 2 3 4 5 6

// 2 1 6

// Output:

// 1 6

// For example:
// Input 	Result

// 1
// 3 10 17 57
// 6 
// 2 7 10 15 57 246

	

// 10 57

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n1, n2;

        scanf("%d", &n1);
        int A[n1];
        for (int i = 0; i < n1; i++)
            scanf("%d", &A[i]);

        scanf("%d", &n2);
        int B[n2];
        for (int i = 0; i < n2; i++)
            scanf("%d", &B[i]);

        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                i++;
                j++;
            } else if (A[i] < B[j]) {
                i++;
            } else {
                j++;
            }
        }

        printf("\n");
    }

    return 0;
}

