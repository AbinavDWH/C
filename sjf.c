#include<stdio.h>

int main(){
    int n;int at[10],bt[10],wt[10],tat[10],complete[10]={0};
    int time=0,done=0;
    float total_tat=0,total_wt=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter the arrival time and burst time for process %d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
    while(done<n){
        int idx=-1;
        int min_bt=9999;
        for(int i=0;i<n;i++){
            if(at[i]<=time && complete[i]==0&&bt[i]<min_bt){
                min_bt=bt[i];
                idx=i;
            }
        if(idx==-1){
            wt[idx]=time-at[idx];
            if(wt[idx]<0) wt[idx]=0;
            time+=bt[idx];

            tat[idx]=wt[idx]+bt[idx];

            complete[idx]=1;
            done++;
        }
        else{
            time++;
        }
    }
}
        printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(int i=0;i<n;i++){
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+
            1,at[i],bt[i],wt[i],tat[i]);

            total_wt+=wt[i];
            total_tat+=tat[i];
        }
        printf("\nAverage Waiting Time: %.2f\n",total_wt/n);
        printf("Average Turnaround Time: %.2f\n",total_tat/n);

        printf("\n");
}