/*
 * Experiment 7 (Part 1): First Fit Memory Allocation Algorithm
 * Source: OS Lab Manual (Ex No: 7)
 *
 * Description:
 * Implements the First Fit contiguous memory allocation method for fixed partitions.
 * Allocates each process to the first memory block that is large enough to accommodate it.
 */

#include <stdio.h>

#define MAX 10

int main(void)
{
    int bsize[MAX], psize[MAX], bno, pno;
    int flags[MAX], allocation[MAX];
    int i, j;

    for (i = 0; i < MAX; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }

    printf("Enter no. of blocks: ");
    if (scanf("%d", &bno) != 1 || bno <= 0 || bno > MAX) return 1;

    printf("Enter size of each block:\n");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter no. of processes: ");
    if (scanf("%d", &pno) != 1 || pno <= 0 || pno > MAX) return 1;

    printf("Enter size of each process:\n");
    for (i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    /* First Fit Allocation */
    for (i = 0; i < pno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }

    printf("\nBlock No\tBlock Size\tProcess No\tProcess Size");
    for (i = 0; i < bno; i++)
    {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i]);
        if (flags[i] == 1)
            printf("%d\t\t\t%d", allocation[i] + 1, psize[allocation[i]]);
        else
            printf("Not Allocated");
    }
    printf("\n");

    return 0;
}
