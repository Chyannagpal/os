#include <stdio.h> 
#include <limits.h> 
int main() { 
    int n, time = 0, completed = 0, smallest; 
    int at[10], bt[10], rbt[10], wt[10] = {0}, tat[10] = {0}, p[10]; 
    float totalwt = 0, totaltat = 0; 
 printf("Enter the total number of processes: "); 
    scanf("%d", &n); 
 printf("\nEnter Arrival Time and Burst Time for each process:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("P%d Arrival Time: ", i + 1); 
        scanf("%d", &at[i]); 
        printf("P%d Burst Time: ", i + 1); 
        scanf("%d", &bt[i]); 
        rbt[i] = bt[i]; 
        p[i] = i + 1;  
    } 
 
    while (completed != n) { 
        smallest = -1; 
        int min_time = INT_MAX; 
        for (int i = 0; i < n; i++) { 
            if (at[i] <= time && rbt[i] > 0 && rbt[i] < min_time) { 
                min_time = rbt[i]; 
                smallest = i; 
            } 
        } 
 
        if (smallest == -1) {  
            time++; 
            continue; 
        } 
        rbt[smallest]--; 
        time++; 
 
        if (rbt[smallest] == 0) { 
            completed++; 
            tat[smallest] = time - at[smallest];          
            wt[smallest] = tat[smallest] - bt[smallest];  
        } 
    } 
    for (int i = 0; i < n; i++) { 
        totaltat += tat[i]; 
        totalwt += wt[i]; 
    } 
   printf("\nProcess\tAT\tBT\tTAT\tWT\n"); 
    for (int i = 0; i < n; i++) { 
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], tat[i], wt[i]); 
    } 
  printf("\nAverage Turnaround Time: %.2f\n", totaltat / n); 
    printf("Average Waiting Time: %.2f\n", totalwt / n); 
 
    return 0; 
}