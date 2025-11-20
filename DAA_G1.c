// Write a program to take value V and  we want to make change for V Rs, and we have infinite supply of each of the denominations in Indian currency, i.e., we have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

// Input Format:

// Take an integer from stdin.

// Output Format:

// print the integer which is change of the  number.

// Example Input :

// 64

// Output:

// 4

// Explanaton:

// We need a 50 Rs note and a 10 Rs note and two 2 rupee coins.

// Answer:(penalty regime: 0 %)
// Feedback
// 	Input 	Expected 	Got 	
	

// 49

	

// 5

	

// 5

	

// Passed all tests!  

#include<stdio.h>
int main(){
    int n,i=8,arr[]={1, 2, 5, 10, 20, 50, 100, 500, 1000},j=0;
    
    scanf("%d",&n);
    while(n>0){
        if(n>=arr[i]){
            j+=n/arr[i];
            // if(n==1) break;
            n%=arr[i];
            
        }i--;
    }
    printf("%d",j);
}