#include<stdio.h> 
#include<limits.h> 
 
int main() { 
    int n, at[10], bt[10], wt[10], tat[10], ct[10], rbt[10]; 
    int completed = 0, time = 0, i, quantum; 
    float totaltat = 0, totalwt = 0; 
 
    printf("Enter the total number of processes: "); 
    scanf("%d", &n); 
 
    printf("\nEnter Arrival Time and Burst Time for each process:\n"); 
    for (i = 0; i < n; i++) { 
        printf("Process[%d] Arrival Time: ", i + 1); 
        scanf("%d", &at[i]); 
        printf("Process[%d] Burst Time: ", i + 1); 
        scanf("%d", &bt[i]); 
        rbt[i] = bt[i];   
    } 
 
    printf("Enter the time quantum: "); 
    scanf("%d", &quantum); 
 
    while (completed != n) { 
        int all_done = 1; 
        for (i = 0; i < n; i++) { 
            if (rbt[i] > 0 && at[i] <= time) { 
                all_done = 0; 
                if (rbt[i] > quantum) { 
                    time += quantum; 
                    rbt[i] -= quantum; 
                } else { 
                    time += rbt[i]; 
                    wt[i] = time - at[i] - bt[i]; 
                    tat[i] = time - at[i];  
                    rbt[i] = 0;  
                    completed++; 
                } 
            } 
        } 
        if (all_done == 1) { 
            time++;  
        } 
    } 
 
    for (i = 0; i < n; i++) { 
        totaltat += tat[i]; 
        totalwt += wt[i]; 
    } 
+ 
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n"); 
    for (i = 0; i < n; i++) { 
        ct[i] = tat[i] + at[i];  
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]); 
    } 
 
    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n); 
    printf("Average Waiting Time: %.2f\n", totalwt / n); 
 
    return 0; 
}