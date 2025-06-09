
// Anu is given an array of integers and a target value. Her task is to find a pair of distinct numbers from the array that add up to the given target value. She can assume that there is exactly one solution for each input, and she should output the indices of the two numbers that form the required pair using direct addressing.


// Example 1:


// Input: 

// 4

// 2 7 11 15

// 9

// Output: [0,1]

// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


// Example 2:


// Input:

// 3

// 3 2 4

// 6

// Output: [1,2]


// Example 3:


// Input: 

// 2

// 3 3

// 6

// Output: [0,1]
// Input format :

// The first line of input contains an integer N representing the number of elements in the array.

// The second line of input contains N space-separated integers representing the elements of the array.

// The third line of input contains an integer representing the target value.
// Output format :

// If a valid pair of numbers is found, the output will be two integers separated by a space, representing the indices of the pair in the array (0-based index).

// If no valid pair is found, the output will be "No solution found."


// Refer to the sample output for formatting specifications.
// Code constraints :

// The given test cases fall under the following constraints:

// The array contains up to 100 integers.

// Each integer in the array is in the range [-100, 100].
// Sample test cases :
// Input 1 :

// 4
// 2 7 11 15
// 9

// Output 1 :

// [0, 1]

// Input 2 :

// 3
// 3 2 4
// 6

// Output 2 :

// [1, 2]

// Input 3 :

// 2
// 3 3
// 6

// Output 3 :

// [0, 1]

// Input 4 :

// 7
// 1 2 3 4 5 6 7
// 14

// Output 4 :

// No solution found.

// You are using GCC
#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }
    
    int ele;
    scanf("%d",&ele);
    for(int i=0;i<n;i++){
        for(int j=0;j<n&&i!=j;j++){
            if(arr[i]+arr[j]==ele){
                printf("[%d, %d]",j,i);
                return 0;
            }
        }
    }
    printf("No solution found.");
}