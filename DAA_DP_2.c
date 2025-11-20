// Ram is given with an n*n chessboard with each cell with a monetary value. Ram stands at the (0,0), that the position of the top left white rook. He is been given a task to reach the bottom right black rook position (n-1, n-1) constrained that he needs to reach the position by traveling the maximum monetary path under the condition that he can only travel one step right or one step down the board. Help ram to achieve it by providing an efficient DP algorithm.

// Example:
// Input
// 3
// 1 2 4
// 2 3 4
// 8 7 1
// Output:
// 19

// Explanation:
// Totally there will be 6 paths among that the optimal is
//  Optimal path value:1+2+8+7+1=19

// Input Format
// First Line contains the integer n
// The next n lines contain the n*n chessboard values
 
// Output Format

// Print Maximum monetary value of the path




#include <stdio.h>

#define MAX_N 100  

int main() {
    int n;
    int board[MAX_N][MAX_N];
    int dp[MAX_N][MAX_N];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &board[i][j]);


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0)
                dp[i][j] = board[i][j];
            else if (i == 0)
                dp[i][j] = dp[i][j-1] + board[i][j];
            else if (j == 0)
                dp[i][j] = dp[i-1][j] + board[i][j];
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + board[i][j];
        }

    printf("%d", dp[n-1][n-1]);

    return 0;
}

