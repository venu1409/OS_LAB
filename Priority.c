#include <stdio.h>

int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], pr[20];
    int temp, temp2;
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Burst Time and Priority
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        printf("Enter Priority for P%d: ", i+1);
        scanf("%d", &pr[i]);
    }

    // Sorting based on Priority (Ascending)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                // swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // swap burst time
                temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
            }
        }
    }

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
    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%d\t%d\n", i+1, pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    return 0;
}
