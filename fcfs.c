#include<stdio.h>
int main()
{
    int n, i, j, temp, total = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n], burst_time[n], waiting_time[n], turnaround_time[n];
     printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
     printf("Enter the Arrail time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &at[i]);
    }
    int ct[n];
    ct[0] = at[0] + burst_time[0];
    for(int i=1;i<n;i++){
        ct[i] = ct[i-1] + burst_time[i];
    }
    waiting_time[0] = 0;
    
    for(i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    for(i = 0; i < n; i++)
    {
        turnaround_time[i] = ct[i] - at[i];
        total += turnaround_time[i];
    }

    printf("\nProcess\tBurst Time\tCT\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], ct[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Turnaround Time: %.2f\n", (float)total / n);
    return 0;
}