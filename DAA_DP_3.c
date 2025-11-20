// Given two strings find the length of the common longest subsequence(need not be contiguous) between the two.


// Example:

//  s1: ggtabe

//  s2: tgatasb


// s1 	  	a 	g 	
// g
	
// t
	
// a
	
// b
	 
// s2 	  	
// g
// 	x 	
// t
	
// x
	
// a
	
// y
	
// b

// The length is 4

// Solveing it using Dynamic Programming

// For example:
// Input 	Result

// aab
// azb

	

// 2

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[m + 1][n + 1];

    // Initialize the dp table
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    char s1[1001], s2[1001];

    while (scanf("%s %s", s1, s2) == 2) {
        int result = longestCommonSubsequence(s1, s2);
        printf("%d\n", result);
    }

    return 0;
}

