/*
 * Experiment 3C: Priority CPU Scheduling (Non-preemptive)
 * Source: OS Lab Manual (Ex No: 3C)
 *
 * Description:
 * Implements Priority scheduling by ordering processes according to assigned priority values.
 * Fixes the transcription typo from the manual where `tur[I ]` appeared with uppercase I.
 * Displays waiting time, turnaround time, Gantt chart, and averages.
 */

#include <stdio.h>

int main(void)
{
    int i, j, n, t;
    int p[10], pri[10], bur[10], wat[10], tur[10];
    int ttur = 0, twat = 0;
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
        scanf("%d", &bur[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the priority for process %d: ", (i + 1));
        scanf("%d", &pri[i]);
    }

    /* Sort processes by priority (lower numerical value = higher priority) */
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pri[i] > pri[j])
            {
                t = bur[i]; bur[i] = bur[j]; bur[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
                t = pri[i]; pri[i] = pri[j]; pri[j] = t;
            }
        }
    }

    wat[0] = 0;
    for (i = 0; i < n; i++)
    {
        wat[i + 1] = wat[i] + bur[i];
        tur[i] = wat[i] + bur[i];
    }

    printf("\nPROCESS\tBURST TIME \t PRIORITY \t WAITING TIME \t TURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bur[i], pri[i], wat[i], tur[i]);
        ttur += tur[i];
        twat += wat[i];
    }

    printf("\nGANTT CHART\n\n");
    for (i = 0; i < n; i++)
        printf(" --------");
    printf("\n|");
    for (i = 0; i < n; i++)
        printf("  P%d  |", p[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf(" --------");
    printf("\n");
    for (i = 0; i <= n; i++)
        printf("%d\t", wat[i]);

    awat = (float)twat / n;
    atur = (float)ttur / n;

    printf("\n\nTotal waiting time : %d\n", twat);
    printf("Total turnaround time : %d\n", ttur);
    printf("Average waiting time : %.2f\n", awat);
    printf("Average turn around time : %.2f\n", atur);

    return 0;
}
