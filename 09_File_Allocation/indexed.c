/*
 * Experiment 9C: Indexed File Allocation Strategy
 * Source: OS Lab Manual (Ex No: 9C)
 *
 * Description:
 * Simulates indexed file allocation where all disk block pointers belonging to a file
 * are stored together in an index block.
 */

#include <stdio.h>

int main(void)
{
    int f[50], index[50];
    int indblk, n, i, j, c;
    int count;

    /* Initialize all 50 disk blocks as free */
    for (i = 0; i < 50; i++)
        f[i] = 0;

    do
    {
        count = 0;
        printf("Enter index block (0-49): ");
        if (scanf("%d", &indblk) != 1 || indblk < 0 || indblk >= 50)
            break;

        if (f[indblk] == 1)
        {
            printf("Index block %d is already allocated.\n", indblk);
        }
        else
        {
            printf("Enter number of files/blocks on index: ");
            if (scanf("%d", &n) != 1 || n <= 0 || n >= 50)
                break;

            printf("Enter file blocks (0-49): ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &index[i]);
                if (index[i] >= 0 && index[i] < 50 && f[index[i]] == 0)
                    count++;
            }

            if (count == n)
            {
                printf("\nAllocated\nFile Indexed successfully:\n");
                f[indblk] = 1;
                for (j = 0; j < n; j++)
                {
                    f[index[j]] = 1;
                    printf("Index Block %d -> Block %d : Allocated\n", indblk, index[j]);
                }
            }
            else
            {
                printf("\nFile block(s) already allocated or invalid. Allocation failed.\n");
            }
        }

        printf("\nDo you want to enter another index block? (1 for Yes / 0 for No): ");
        if (scanf("%d", &c) != 1)
            break;

    } while (c == 1);

    return 0;
}
