/*
 * Experiment 6A: Deadlock Avoidance Using Banker's Algorithm
 * Source: OS Lab Manual (Ex No: 6A)
 *
 * Description:
 * Implements Banker's safety algorithm to check if a system is in a safe state.
 * Inputs allocation matrix, maximum matrix, and available instances.
 * Computes the Need matrix and determines if a safe sequence exists.
 */

#include <stdio.h>

int main(void)
{
    int allocation[10][5], max[10][5], need[10][5], available[5], flag[10], sq[10];
    int n, r, i, j, k, count, count1 = 0;

    printf("Input the number of processes running (<10): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10) return 1;

    printf("Input the number of resources (<5): ");
    if (scanf("%d", &r) != 1 || r <= 0 || r > 5) return 1;

    for (i = 0; i < 10; i++)
        flag[i] = 0;

    printf("\nInput the allocation matrix for the processes (row-wise):\n");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i);
        for (j = 0; j < r; j++)
        {
            printf("Resource %d: ", j);
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nInput the maximum matrix for the processes:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i);
        for (j = 0; j < r; j++)
        {
            printf("Resource %d: ", j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nInput the number of available instances of each resource:\n");
    for (i = 0; i < r; i++)
    {
        printf("Resource %d: ", i);
        scanf("%d", &available[i]);
    }

    /* Calculate need matrix */
    printf("\nThe need matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("\t%d", need[i][j]);
        }
        printf("\n");
    }

    /* Banker's Safety Algorithm */
    do
    {
        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                if (flag[i] == 0)
                {
                    count = 0;
                    for (j = 0; j < r; j++)
                    {
                        if (available[j] >= need[i][j])
                            count++;
                    }
                    if (count == r)
                    {
                        count1++;
                        flag[i] = 1;
                        sq[count1 - 1] = i;
                        for (j = 0; j < r; j++)
                            available[j] += allocation[i][j];
                        break;
                    }
                }
            }
        }
        if (count1 != n && k == n - 1)
        {
            printf("\n---------------IT'S AN UNSAFE STATE---------------\n");
            return 0;
        }
    } while (count1 != n);

    printf("\n*******************IT'S A SAFE STATE*******************\n");
    printf("The safe sequence is: ");
    for (i = 0; i < n; i++)
        printf("P%d ", sq[i]);

    printf("\nThe available resources after execution: ");
    for (i = 0; i < r; i++)
        printf("%d ", available[i]);
    printf("\n");

    return 0;
}
