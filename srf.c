#include <stdio.h> 
int main() { 
    int n, p[10], bt[10], wt[10], tat[10], ct[10], sum, i, j, temp; 
    float totaltat = 0, totalwt = 0; 
    printf("Enter the total number of processes: "); 
    scanf("%d", &n); 
    printf("\nEnter the Process IDs\n"); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &p[i]); 
    } 
    printf("\nEnter the burst times of the processes\n"); 
    for (i = 0; i < n; i++) { 
        printf("Enter Burst Time of Process[%d]: ", p[i]); 
        scanf("%d", &bt[i]); 
    } 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            if (bt[j] > bt[j + 1]) {  
                temp = bt[j]; 
                bt[j] = bt[j + 1]; 
                bt[j + 1] = temp; 
                temp = p[j]; 
                p[j] = p[j + 1]; 
                p[j + 1] = temp; 
            } 
        } 
    } 
    sum = 0; 
    for (j = 0; j < n; j++) { 
        sum += bt[j]; 
        ct[j] = sum; 
    } 
 
    for (i = 0; i < n; i++) { 
        tat[i] = ct[i];   
        totaltat += tat[i]; 
        wt[i] = tat[i] - bt[i];   
        totalwt += wt[i]; 
    } 
    printf("\nProcess\tBT\tTAT\tWT\n"); 
    for (i = 0; i < n; i++) { 
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], tat[i], wt[i]); 
    } 
 printf("\nAverage Turnaround Time: %.2f\n", totaltat / n); 
    printf("Average Waiting Time: %.2f\n", totalwt / n); 
 
    return 0; 
} 
 
