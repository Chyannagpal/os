#include<stdio.h>  
void main() { 
    int i, j, k, f, pf = 0, rs[25], m[10], n, least, index, found; 
     printf("\n Enter the length of reference string -- ");  
    scanf("%d", &n); 
    printf("\n Enter the reference string -- ");  
    for(i = 0; i < n; i++)  
        scanf("%d", &rs[i]); 
     
    printf("\n Enter number of frames -- ");  
    scanf("%d", &f);  
     
    for(i = 0; i < f; i++)  
        m[i] = -1; // Initialize frames 
     
    printf("\n The Page Replacement Process is -- \n"); 
     
    for(i = 0; i < n; i++) { 
        found = 0; 
        for(k = 0; k < f; k++) { 
            if(m[k] == rs[i]) { 
                found = 1;  
                break; 
            } 
        } 
         
        if(found == 0) { // Page fault 
            pf++; 
            int least_used = 0; 
            for(j = 1; j < f; j++) { 
                int is_recent = 0; 
                for(k = i - 1; k >= 0; k--) { 
                    if(m[j] == rs[k]) { 
                        is_recent = 1; 
                        break; 
                    } 
                } 
                if(is_recent == 0) { 
                    least_used = j; 
                    break; 
                } 
            } 
 
            m[least_used] = rs[i]; // Replace LRU page 
        } 
        for(j = 0; j < f; j++)  
            printf("\t%d", m[j]); 
         
        if(found == 0)  
            printf("\tPF No. %d", pf);  
         
        printf("\n"); 
    } 
    printf("\n The number of Page Faults using LRU are %d", pf);  
} 
