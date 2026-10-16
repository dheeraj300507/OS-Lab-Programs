/*
 * Experiment 10B: SCAN (Elevator) Disk Scheduling Algorithm
 * Source: OS Lab Manual (Ex No: 10B)
 *
 * Description:
 * Simulates SCAN disk scheduling where the disk head moves in one direction (towards 0),
 * servicing all requests encountered, reaches cylinder 0, reverses direction, and
 * services the remaining requests towards the maximum cylinder.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n;
    int d[25];
    int disk;          /* Initial head position */
    int temp, max;
    int dloc = -1;
    int sum;

    printf("Enter number of disk requests: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n >= 20) return 1;

    printf("Enter initial head position: ");
    if (scanf("%d", &disk) != 1) return 1;

    printf("Enter disk queue elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }

    /* Insert head position into array */
    d[n] = disk;
    n++;

    /* Sort disk queue in ascending order */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (d[i] > d[j])
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    max = d[n - 1];

    /* Find head position in sorted array */
    for (i = 0; i < n; i++)
    {
        if (d[i] == disk)
        {
            dloc = i;
            break;
        }
    }

    printf("\nSCAN Service Order:\n");

    /* Move towards 0 */
    for (i = dloc; i >= 0; i--)
    {
        printf("%d", d[i]);
        if (i > 0)
            printf(" --> ");
    }

    printf(" --> 0");

    /* Reverse direction towards max */
    for (i = dloc + 1; i < n; i++)
    {
        printf(" --> %d", d[i]);
    }

    /* Total head movement: (disk - 0) + (max - 0) = disk + max */
    sum = disk + max;

    printf("\n\nTotal Head Movement = %d cylinders\n", sum);

    return 0;
}
