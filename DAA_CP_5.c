// Given an array A of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[j] - A[i] = k, i != j.

// Input Format:

// First Line n - Number of elements in an array

// Next n Lines - N elements in the array

// k - Non - Negative Integer
// Output Format:

// 1 - If pair exists

// 0 - If no pair exists

// Explanation for the given Sample Testcase:

// YES as 5 - 1 = 4

// So Return 1.


// For example:
// Input 	Result

// 3
// 1 3 5
// 4

	

// 1
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int k;
    scanf("%d", &k);

    int i = 0, j = 1;

    while (i < n && j < n) {

        int diff = A[j] - A[i];

        if (diff == k && i != j) {
            printf("1\n");
            return 0;
        }

        if (diff < k) {
            j++;     
        } else {
            i++;      
            if (i == j)
                j++;  
        }
    }

    printf("0\n");
    return 0;
}

