/*
 * Experiment 8B: Least Recently Used (LRU) Page Replacement Algorithm
 * Source: OS Lab Manual (Ex No: 8B)
 *
 * Description:
 * Implements LRU page replacement algorithm.
 * Replaces the page in memory that has not been used for the longest period of time.
 * Fixes formatting and brace alignment corruption present in the manual's listing,
 * matching the verified execution trace in the manual's screenshot.
 */

#include <stdio.h>

int main(void)
{
    int q[20], p[50], c = 0, c1, f, i, j, k = 0, n, r, t, b[20], c2[20];

    printf("Enter no of pages: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) return 1;

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter no of frames: ");
    if (scanf("%d", &f) != 1 || f <= 0 || f > 20) return 1;

    /* First page allocation */
    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;

    for (i = 1; i < n; i++)
    {
        c1 = 0;
        for (j = 0; j < (k < f ? k : f); j++)
        {
            if (p[i] != q[j])
                c1++;
        }

        /* Page fault condition */
        if (c1 == (k < f ? k : f))
        {
            c++;
            if (k < f)
            {
                q[k] = p[i];
                k++;
                for (j = 0; j < k; j++)
                    printf("\t%d", q[j]);
                printf("\n");
            }
            else
            {
                /* Calculate distance since last reference for each resident page */
                for (r = 0; r < f; r++)
                {
                    c2[r] = 0;
                    for (j = i - 1; j >= 0; j--)
                    {
                        if (q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }

                /* Sort distances to find maximum distance (LRU page) */
                for (r = 0; r < f; r++)
                    b[r] = c2[r];

                for (r = 0; r < f; r++)
                {
                    for (j = r + 1; j < f; j++)
                    {
                        if (b[r] < b[j])
                        {
                            t = b[r]; b[r] = b[j]; b[j] = t;
                        }
                    }
                }

                /* Replace the page with the highest distance */
                for (r = 0; r < f; r++)
                {
                    if (c2[r] == b[0])
                    {
                        q[r] = p[i];
                        break;
                    }
                }

                for (r = 0; r < f; r++)
                    printf("\t%d", q[r]);
                printf("\n");
            }
        }
    }

    printf("\nThe no of page faults is %d\n", c);
    return 0;
}
