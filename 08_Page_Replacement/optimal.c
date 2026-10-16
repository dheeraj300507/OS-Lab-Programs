/*
 * Experiment 8C: Optimal Page Replacement Algorithm
 * Source: OS Lab Manual (Ex No: 8C)
 *
 * Description:
 * Implements Optimal Page Replacement by replacing the resident page that
 * will not be used for the longest period of time in future requests.
 * Fixes syntax typos from the manual listing and calculates page faults and fault rate.
 */

#include <stdio.h>

int findmax(int a[], int n);

int main(void)
{
    int seq[30], fr[5], pos[5], flag, max, i, j, m, k, s, pf = 0;
    int count = 1, p = 0, n;
    float pfr;

    printf("Enter max limit of the sequence: ");
    if (scanf("%d", &max) != 1 || max <= 0 || max > 30) return 1;

    printf("Enter the sequence:\n");
    for (i = 0; i < max; i++)
        scanf("%d", &seq[i]);

    printf("Enter the no of frames: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 5) return 1;

    fr[0] = seq[0];
    pf++;
    printf("\n%d\t", fr[0]);
    i = 1;

    while (count < n && i < max)
    {
        flag = 1;
        p++;
        for (j = 0; j < i; j++)
        {
            if (seq[i] == seq[j])
                flag = 0;
        }
        if (flag != 0)
        {
            fr[count] = seq[i];
            printf("%d\t", fr[count]);
            count++;
            pf++;
        }
        i++;
    }
    printf("\n");

    for (i = p + 1; i < max; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
        {
            if (seq[i] == fr[j])
                flag = 0;
        }
        if (flag != 0)
        {
            for (j = 0; j < n; j++)
            {
                m = fr[j];
                pos[j] = -1;
                for (k = i; k < max; k++)
                {
                    if (seq[k] == m)
                    {
                        pos[j] = k;
                        break;
                    }
                }
            }

            flag = 1;
            for (k = 0; k < n; k++)
            {
                if (pos[k] == -1)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag != 0)
            {
                s = findmax(pos, n);
            }
            else
            {
                for (k = 0; k < n; k++)
                {
                    if (pos[k] == -1)
                    {
                        s = k;
                        break;
                    }
                }
            }

            pf++;
            fr[s] = seq[i];
            for (k = 0; k < n; k++)
                printf("%d\t", fr[k]);
            printf("\n");
        }
    }

    pfr = (float)pf / (float)max;
    printf("\nThe no of page faults are: %d\n", pf);
    printf("Page fault rate: %.4f\n", pfr);

    return 0;
}

int findmax(int a[], int n)
{
    int max_val = a[0];
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (max_val < a[i])
        {
            max_val = a[i];
            k = i;
        }
    }
    return k;
}
