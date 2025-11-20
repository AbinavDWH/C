// Problem statement:

// Find the length of the Longest Non-decreasing Subsequence in a given Sequence.

// Eg:


// Input:9

// Sequence:[-1,3,4,5,2,2,2,2,3]

// the subsequence is [-1,2,2,2,2,3]

// Output:6
// Answer:(penalty regime: 0 %)

#include <stdio.h>

int longestNonDecreasingSubsequence(int arr[], int n) {
    int dp[n];
   
    for (int i=0;i<n;i++)
        dp[i] = 1;

    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (arr[i]>=arr[j]&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }

    int max=dp[0];
    for (int i=1;i<n;i++) {
        if (dp[i]>max)
            max=dp[i];
    }

    return max;
}

int main() {
    int arr[]={-1, 3, 4, 5, 2, 2, 2, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);

    int result=longestNonDecreasingSubsequence(arr, n);
    printf("%d\n", result);

    return 0;
}

