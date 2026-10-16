/*
 * Experiment 3D: Round Robin (RR) CPU Scheduling
 * Source: OS Lab Manual (Ex No: 3D)
 *
 * Description:
 * Implements Round Robin CPU scheduling with a fixed time slice (quantum).
 * Simulates cyclic execution of ready processes and computes Waiting Time,
 * Turnaround Time, Response Time, and displays the Gantt chart.
 */

#include <stdio.h>

int main(void)
{
    int i, x = -1, k[10], m = 0, n, t, s = 0;
    int a[50], temp, b[50], p[10], bur[10], bur1[10];
    int wat[10], tur[10], ttur = 0, twat = 0, tres = 0, j = 0;
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
        bur1[i] = bur[i];
    }

    printf("Enter the slicing time: ");
    if (scanf("%d", &t) != 1 || t <= 0)
    {
        printf("Invalid time slice.\n");
        return 1;
    }

    /* Calculate total number of execution slices */
    for (i = 0; i < n; i++)
    {
        b[i] = bur[i] / t;
        if ((bur[i] % t) != 0)
            b[i] += 1;
        m += b[i];
    }

    printf("\nGAANT CHART\n\n");
    for (i = 0; i < m; i++)
        printf("-------");
    printf("\n|");

    a[0] = 0;
    while (j < m)
    {
        if (x == n - 1)
            x = 0;
        else
            x++;

        if (bur[x] >= t)
        {
            bur[x] -= t;
            a[j + 1] = a[j] + t;
            if (b[x] == 1)
            {
                p[s] = x;
                k[s] = a[j + 1];
                s++;
            }
            j++;
            b[x]--;
            printf(" P%d |", x + 1);
        }
        else if (bur[x] != 0)
        {
            a[j + 1] = a[j] + bur[x];
            bur[x] = 0;
            if (b[x] == 1)
            {
                p[s] = x;
                k[s] = a[j + 1];
                s++;
            }
            j++;
            b[x]--;
            printf(" P%d |", x + 1);
        }
    }

    printf("\n");
    for (i = 0; i < m; i++)
        printf("-------");
    printf("\n");
    for (j = 0; j <= m; j++)
        printf("%d\t", a[j]);

    /* Sort completion times by process ID */
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i]; p[i] = p[j]; p[j] = temp;
                temp = k[i]; k[i] = k[j]; k[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        wat[i] = k[i] - bur1[i];
        tur[i] = k[i];
    }

    printf("\n\nPROCESS\tBURST TIME \t WAITING TIME \t TURN AROUND TIME\tRESPONSE TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i] + 1, bur1[i], wat[i], tur[i], a[i]);
        ttur += tur[i];
        twat += wat[i];
        tres += a[i];
    }

    awat = (float)twat / n;
    atur = (float)ttur / n;

    printf("\nTotal waiting time: %d", twat);
    printf("\nTotal turnaround time: %d", ttur);
    printf("\nAverage waiting time : %.2f", awat);
    printf("\nAverage turn around time : %.2f\n", atur);

    return 0;
}
