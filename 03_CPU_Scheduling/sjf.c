/*
 * Experiment 3B: Shortest Job First (SJF) CPU Scheduling (Non-preemptive)
 * Source: OS Lab Manual (Ex No: 3B)
 *
 * Description:
 * Implements SJF non-preemptive scheduling by sorting processes in ascending order
 * of their burst times. Computes Waiting Time, Turnaround Time, Gantt chart, and averages.
 */

#include <stdio.h>

int main(void)
{
    int i, j, n, t;
    int p[10], br[10], wt[10], tr[10];
    int ttr = 0, twt = 0;
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
        p[i] = i + 1;
    }

    /* Sort processes by burst time */
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (br[i] > br[j])
            {
                t = br[i]; br[i] = br[j]; br[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
        }
    }

    wt[0] = 0;
    for (i = 0; i < n; i++)
    {
        wt[i + 1] = wt[i] + br[i];
        tr[i] = wt[i] + br[i];
    }

    printf("\nPROCESS\tBURST TIME \t WAITING TIME \t TURN AROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], br[i], wt[i], tr[i]);
        ttr += tr[i];
        twt += wt[i];
    }

    printf("\nGANTT CHART\n\n");
    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n|");
    for (i = 0; i < n; i++)
        printf("  P%d  |", p[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n");
    for (i = 0; i <= n; i++)
        printf("%d\t", wt[i]);

    awat = (float)twt / n;
    atur = (float)ttr / n;

    printf("\n\nTotal waiting time : %d\n", twt);
    printf("Total turnaround time : %d\n", ttr);
    printf("Average waiting time : %.2f\n", awat);
    printf("Average turn around time : %.2f\n", atur);

    return 0;
}
