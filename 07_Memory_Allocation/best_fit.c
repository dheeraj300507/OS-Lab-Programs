/*
 * Experiment 7 (Part 2): Best Fit Memory Allocation Algorithm
 * Source: OS Lab Manual (Ex No: 7)
 *
 * Description:
 * Implements the Best Fit memory allocation scheme.
 * Allocates each process to the smallest free block that is large enough,
 * minimizing leftover fragmentation per allocated block.
 */

#include <stdio.h>

int main(void)
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];

    printf("\n\t\t\tMemory Management Scheme - Best Fit\n");
    printf("Enter the number of blocks: ");
    if (scanf("%d", &nb) != 1 || nb <= 0 || nb >= 20) return 1;

    printf("Enter the number of processes: ");
    if (scanf("%d", &np) != 1 || np <= 0 || np >= 20) return 1;

    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block no.%d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the processes:-\n");
    for (i = 1; i <= np; i++)
    {
        printf("Process no.%d: ", i);
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                {
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        fragment[i] = lowest;
        if (parray[i] != 0)
            barray[parray[i]] = 1;
        lowest = 10000;
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
    for (i = 1; i <= np && parray[i] != 0; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }

    return 0;
}
