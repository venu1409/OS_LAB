#include <stdio.h>

int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], temp;
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Burst Time
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Sorting Burst Time (Ascending)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // First process waiting time
    wt[0] = 0;

    // Calculate Waiting Time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        total_wt += wt[i];
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_tat += tat[i];
    }

    // Display
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    return 0;
}
