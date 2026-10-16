/*
 * Experiment 8A: First In First Out (FIFO) Page Replacement Algorithm
 * Source: OS Lab Manual (Ex No: 8A)
 *
 * Description:
 * Implements FIFO page replacement using a circular pointer `j` to replace
 * the oldest resident page when a page fault occurs.
 */

#include <stdio.h>

int main(void)
{
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;

    printf("ENTER THE NUMBER OF PAGES: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) return 1;

    printf("ENTER THE PAGE NUMBERS:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    printf("ENTER THE NUMBER OF FRAMES: ");
    if (scanf("%d", &no) != 1 || no <= 0 || no > 10) return 1;

    for (i = 0; i < no; i++)
        frame[i] = -1;

    j = 0;
    printf("\nRef String\tPage Frames\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;
        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
            {
                avail = 1;
                break;
            }
        }
        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
            for (k = 0; k < no; k++)
            {
                if (frame[k] != -1)
                    printf("%d\t", frame[k]);
                else
                    printf("-\t");
            }
        }
        printf("\n");
    }

    printf("\nPage Fault Is %d\n", count);
    return 0;
}
