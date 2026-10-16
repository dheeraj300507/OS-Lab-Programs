/*
 * Experiment 7 (Part 3): Worst Fit Memory Allocation Algorithm
 * Source: OS Lab Manual (Ex No: 7)
 *
 * Description:
 * Implements the Worst Fit memory allocation scheme.
 * Sorts partitions in descending order of size and allocates each process to the
 * largest available partition that can accommodate it.
 */

#include <stdio.h>

int main(void)
{
    int i, j, temp;
    int f[10], fp[10];
    int no, p[10], part[10];
    int pno, pr[10], prmem[10];

    printf("\n*******************************************");
    printf("\n IMPLEMENTATION OF WORST-FIT ALGORITHM");
    printf("\n*******************************************\n");

    printf("Enter the number of partitions: ");
    if (scanf("%d", &no) != 1 || no <= 0 || no > 10) return 1;

    for (i = 1; i <= no; i++)
    {
        p[i] = i;
        printf("Enter the memory for partition %d: ", i);
        scanf("%d", &part[i]);
    }

    /* Sort partitions in descending order */
    for (i = 1; i <= no; i++)
    {
        for (j = i + 1; j <= no; j++)
        {
            if (part[i] < part[j])
            {
                temp = part[i]; part[i] = part[j]; part[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    printf("\nFree memory partitions (sorted descending):");
    for (i = 1; i <= no; i++)
    {
        printf("\nPartition %d: %d", p[i], part[i]);
        f[i] = 0;
    }

    printf("\n\nEnter the number of processes: ");
    if (scanf("%d", &pno) != 1 || pno <= 0 || pno > 10) return 1;

    for (i = 1; i <= pno; i++)
    {
        pr[i] = i;
        printf("Enter the size for process %d: ", i);
        scanf("%d", &prmem[i]);
        fp[i] = 0;
    }

    printf("\nPROCESS\t\tPARTITION\tFREE_MEMORY\n");
    j = 1;
    for (i = 1; i <= no && j <= pno; i++)
    {
        if (part[i] >= prmem[j])
        {
            part[i] -= prmem[j];
            f[i] = 1;
            fp[j] = 1;
            printf("%d\t\t%d\t\t%d\n", pr[j], p[i], part[i]);
            j++;
        }
    }

    printf("\nThe following processes could not be allocated:\n");
    int unallocated = 0;
    for (i = 1; i <= pno; i++)
    {
        if (fp[i] == 0)
        {
            printf("Process %d ", pr[i]);
            unallocated = 1;
        }
    }
    if (!unallocated)
        printf("None (all processes allocated successfully)");
    printf("\n");

    return 0;
}
