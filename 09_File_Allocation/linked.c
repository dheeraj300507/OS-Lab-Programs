/*
 * Experiment 9B: Linked List File Allocation Strategy
 * Source: OS Lab Manual (Ex No: 9B)
 *
 * Description:
 * Simulates linked list file allocation where blocks belonging to a file are linked.
 * Pre-marks already allocated blocks and allocates available contiguous or chained blocks.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int f[50], i, p, a, st, len, c;
    int flag;

    /* Initialize all 50 disk blocks as free */
    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks are already allocated: ");
    if (scanf("%d", &p) != 1 || p < 0 || p > 50) return 1;

    if (p > 0)
    {
        printf("Enter the block numbers (0-49): ");
        for (i = 0; i < p; i++)
        {
            scanf("%d", &a);
            if (a >= 0 && a < 50)
                f[a] = 1;
        }
    }

    do
    {
        printf("\nEnter starting block and length: ");
        if (scanf("%d %d", &st, &len) != 2 || st < 0 || st + len > 50)
        {
            printf("Invalid block range.\n");
            break;
        }

        flag = 0;
        for (i = st; i < st + len; i++)
        {
            if (f[i] == 1)
            {
                printf("Block %d is already allocated.\n", i);
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("File allocated at blocks:\n");
            for (i = st; i < st + len; i++)
            {
                f[i] = 1;
                printf("%d -> %d\n", i, f[i]);
            }
        }
        else
        {
            printf("Cannot allocate due to previously allocated block(s).\n");
        }

        printf("\nDo you want to enter another file? (1 for Yes / 0 for No): ");
        if (scanf("%d", &c) != 1)
            break;

    } while (c == 1);

    return 0;
}
