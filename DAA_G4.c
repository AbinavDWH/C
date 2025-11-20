// Given an array of N integer, we have to maximize the sum of arr[i] * i, where i is the index of the element (i = 0, 1, 2, ..., N).Write an algorithm based on Greedy technique with a Complexity O(nlogn).

//  Input Format:

// First line specifies the number of elements-n

// The next n lines contain the array elements.

// Output Format:

// Maximum Array Sum to be printed.

// Sample Input:

// 5

// 2 5 3 4 0

// Sample output:

// 40


//  	Input 	Expected 	Got 	
	

// 5
// 2
// 5
// 3
// 4
// 0

	

// 40

	

// 40

	
	

// 10
// 2
// 2
// 2
// 4
// 4
// 3
// 3
// 5
// 5
// 5

	

// 191

	

// 191

	
	

// 2
// 45
// 3

	

// 45

	

// 45

	

#include<stdio.h>
#include<stdlib.h>



void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        
    }
      mergeSort(arr, 0, n - 1);
    
    
    for(int i=0;i<n;i++){
        sum+=arr[i]*i;
    }
    printf("%d",sum);
}