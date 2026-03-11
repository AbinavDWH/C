#include<stdio.h>

int main(){
    int n;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int at[n],bt[n];
    for(int i=0;i<n;i++){
        printf("Enter Arrival Time and Burst Time for P%d ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    int wt[n],tat[n];
    int ct[n];
    for(int i=0;i<n;i++){
        if(i==0){
            ct[0]=at[0]+bt[0];
        }
    }

}