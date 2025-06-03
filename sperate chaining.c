#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

int main(){
    int n;
    scanf("%d", &n);
    NODE obj[n];
    for(int i = 0; i < n; i++) {
        obj[i].data = i + 1; // Assigning some data
        obj[i].next = NULL; // Initializing next pointer to NULL
    }

    for (size_t i = 0; i < n; i++)
    {
        /* code */
        printf("Node %zu: data = %d, next = %p\n", i, obj[i].data, (void*)obj[i].next);
    }
    
}