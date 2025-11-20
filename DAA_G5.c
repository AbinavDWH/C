// Given two arrays array_One[] and array_Two[] of same size N. We need to first rearrange the arrays such that the sum of the product of pairs( 1 element from each) is minimum. That is SUM (A[i] * B[i]) for all i is minimum.

// For example:
// Input 	Result

// 3
// 1
// 2
// 3
// 4
// 5
// 6

	

// // 28

#include<stdio.h>
#include<stdlib.h>

int compare_0(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int compare_1(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}


int main(){
    int n;
    scanf("%d",&n);
    int A[n],B[n];
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
    for(int i=0;i<n;i++)
    scanf("%d",&B[i]);
    qsort(A,n,sizeof(n),compare_0);
    qsort(B,n,sizeof(n),compare_1);
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=A[i]*B[i];
    printf("%d",sum);
}