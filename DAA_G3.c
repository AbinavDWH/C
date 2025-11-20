//  A person needs to eat burgers. Each burger contains a count of calorie. After eating the burger, the person needs to run a distance to burn out his calories. 
//  If he has eaten i burgers with c calories each, then he has to run at least 3i * c  kilometers to burn out the calories. For  example, if he ate 3
//  burgers with the count of calorie in the order: [1, 3, 2], the kilometers he needs to run are (30 * 1) + (31 * 3) + (32 * 2) = 1 + 9 + 18 = 28.
//  But this is not the minimum, so need to try out other orders of consumption and choose the minimum value. Determine the minimum distance
//  he needs to run. Note: He can eat burger in any order and use an efficient sorting algorithm.Apply greedy approach to solve the problem.
// Input Format
// First Line contains the number of burgers
// Second line contains calories of each burger which is n space-separate integers 

//  Output Format
 
// Print: Minimum number of kilometers needed to run to burn out the calories

//  Sample Input
 
// 3
// 5 10 7
 
// Sample Output
// 76

// For example:
// Test 	Input 	Result

// Test Case 1

	

// 3
// 1 3 2

	

// 18

// Answer:(penalty regime: 0 %)
// Feedback
// 	Test 	Input 	Expected 	Got 	
	

// Test Case 1

	

// 3
// 1 3 2

	

// 18

	

// 18

	
	

// Test Case 2

	

// 4
// 7 4 9 6

	

// 389

	

// 389

	
	

// Test Case 3

	

// 3
// 5 10 7

	

// 76

	

// 76

	

// Passed all tests!  

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int sort(const void *a,const void *b)
{
    return(*(int *)b-*(int *)a);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),sort);
    int dist=0;
    for(int i=0;i<n;i++)
    dist+=pow(n,i)*a[i];
    printf("%d",dist);
    
}