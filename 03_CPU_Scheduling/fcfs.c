/*
 * Experiment 3A: First Come First Served (FCFS) CPU Scheduling
 * Source: OS Lab Manual (Ex No: 3A)
 *
 * Description:
 * Implements FCFS scheduling where processes are executed in the order of their arrival.
 * Calculates Waiting Time (WT), Turnaround Time (TAT), Average WT, and Average TAT,
 * and displays the Gantt Chart.
 */

#include <stdio.h>

int main(void)
{
    int i, n;
    int br[10], wt[10], tr[10];
    int ttr = 0, twat = 0;
    float awat, atur;

    printf("Enter no. of process: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10)
    {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", (i + 1));
        scanf("%d", &br[i]);
    }

    wt[0] = 0;
    for (i = 0; i < n; i++)
    {
        wt[i + 1] = wt[i] + br[i];
        tr[i] = wt[i] + br[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, br[i], wt[i], tr[i]);
        ttr += tr[i];
        twat += wt[i];
    }

    printf("\nGANTT CHART\n\n");
    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n|");
    for (i = 0; i < n; i++)
        printf("  P%d  |", i + 1);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n");
    for (i = 0; i <= n; i++)
        printf("%d\t", wt[i]);

    awat = (float)twat / n;
    atur = (float)ttr / n;

    printf("\n\nTotal waiting time : %d", twat);
    printf("\nTotal turn around time : %d", ttr);
    printf("\n\nAverage waiting time : %.2f", awat);
    printf("\nAverage turn around time : %.2f\n", atur);

    return 0;
}
