// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

// Example 1:

// Input: 

// 3

// 1 2 3

// 2

// 1 1

// Output: 

// 1

// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 

// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.

// You need to output 1.

// Constraints:

// 1 <= g.length <= 3 * 10^4

// 0 <= s.length <= 3 * 10^4

// 1 <= g[i], s[j] <= 2^31 - 1

// Answer:(penalty regime: 0 %)
// Feedback
// 	Input 	Expected 	Got 	
	

// 2

// 1 2

// 3

// 1 2 3

	

// 2

	

// 2

	

// Passed all tests!  

#include<stdio.h>

int main(){
    int n1,n2;
    scanf("%d",&n1);
    int arr1[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&n2);
    int arr2[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    int c=0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]!=0&&arr2[j]!=0&&arr1[i]==arr2[j]){
                c++;
                arr2[j]=arr1[i]=0;
                
            }
        }
    }
    printf("%d",c);
}