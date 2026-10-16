/*
 * Experiment 10A: First Come First Served (FCFS) Disk Scheduling Algorithm
 * Source: OS Lab Manual (Ex No: 10A)
 *
 * Description:
 * Simulates FCFS disk scheduling where disk I/O requests are serviced in the
 * exact order in which they arrive. Computes individual head movements, total head movement,
 * and average head movement.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int t[20], n, i, tohm[20], tot = 0;
    float avhm;

    printf("Enter the number of tracks: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n >= 20) return 1;

    printf("Enter the initial head position: ");
    if (scanf("%d", &t[0]) != 1) return 1;

    printf("Enter the tracks to be traversed:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &t[i]);

    for (i = 0; i < n; i++)
    {
        tohm[i] = abs(t[i + 1] - t[i]);
        tot += tohm[i];
    }

    avhm = (float)tot / n;

    printf("\nTrack Traversed\tHead Movement\n");
    for (i = 0; i < n; i++)
        printf("%d -> %d\t\t%d\n", t[i], t[i + 1], tohm[i]);

    printf("\nTotal Head Movement = %d\n", tot);
    printf("Average Head Movement = %.2f\n", avhm);

    return 0;
}
