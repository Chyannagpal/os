#include<stdio.h> 
#include<limits.h> 
int main() { 
    int n, at[10], bt[10], wt[10], tat[10], ct[10], pr[10], rbt[10]; 
    int completed = 0, time = 0, i, smallest; 
    float totaltat = 0, totalwt = 0; 
   printf("Enter the total number of processes: "); 
    scanf("%d", &n); 
  printf("\nEnter Arrival Time, Burst Time, and Priority for each process:\n"); 
    for (i = 0; i < n; i++) { 
        printf("Process[%d] Arrival Time: ", i + 1); 
        scanf("%d", &at[i]); 
        printf("Process[%d] Burst Time: ", i + 1); 
        scanf("%d", &bt[i]); 
        printf("Process[%d] Priority: ", i + 1); 
        scanf("%d", &pr[i]); 
        rbt[i] = bt[i];   
    } 
 
    while (completed != n) { 
        smallest = -1; 
        int min_priority = INT_MAX; 
        for (i = 0; i < n; i++) { 
            if (at[i] <= time && rbt[i] > 0 && pr[i] < min_priority) { 
                min_priority = pr[i]; 
                smallest = i; 
            } 
        } 
 
        if (smallest == -1) { 
            time++;   
            continue; 
        } 
        time += rbt[smallest]; 
        rbt[smallest] = 0;   
        completed++; 
        ct[smallest] = time; 
        tat[smallest] = ct[smallest] - at[smallest];   
        wt[smallest] = tat[smallest] - bt[smallest];   
    } 
    for (i = 0; i < n; i++) { 
        totaltat += tat[i]; 
        totalwt += wt[i]; 
    } 
    printf("\nProcess\tAT\tBT\tPr\tCT\tTAT\tWT\n"); 
    for (i = 0; i < n; i++) { 
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]); 
    } 
printf("\nAverage Turnaround Time: %.2f\n", totaltat / n); 
    printf("Average Waiting Time: %.2f\n", totalwt / n); 
   return 0; 
} 
 
 
