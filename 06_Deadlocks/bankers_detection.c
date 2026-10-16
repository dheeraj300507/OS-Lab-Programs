/*
 * Experiment 6B: Deadlock Detection Using Banker's Algorithm
 * Source: OS Lab Manual (Ex No: 6B)
 *
 * Description:
 * Implements deadlock detection by checking whether all processes can finish
 * with the available resource instances and current requests.
 * Identifies any deadlocked processes if a safe execution sequence cannot be completed.
 */

#include <stdio.h>

int main(void)
{
    int alloc[10][10], req[10][10], ins[10], avail[10];
    int tp, tr, i, j;
    int tmp[10] = {0}, finish[10] = {0};
    int done, flag;

    printf("Enter total no of processes: ");
    if (scanf("%d", &tp) != 1 || tp <= 0 || tp > 10) return 1;

    printf("Enter total no of resources: ");
    if (scanf("%d", &tr) != 1 || tr <= 0 || tr > 10) return 1;

    printf("\nAllocation Matrix:\n");
    for (i = 0; i < tp; i++)
    {
        for (j = 0; j < tr; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nRequest Matrix:\n");
    for (i = 0; i < tp; i++)
    {
        for (j = 0; j < tr; j++)
        {
            scanf("%d", &req[i][j]);
        }
    }

    printf("\nResource Instance Vector:\n");
    for (i = 0; i < tr; i++)
    {
        scanf("%d", &ins[i]);
    }

    /* Calculate Availability Vector = Total Instances - Sum of Allocated */
    for (j = 0; j < tr; j++)
    {
        tmp[j] = 0;
        for (i = 0; i < tp; i++)
        {
            tmp[j] += alloc[i][j];
        }
        avail[j] = ins[j] - tmp[j];
    }

    printf("\nCalculated Availability Vector:\n");
    for (j = 0; j < tr; j++)
    {
        printf("%d ", avail[j]);
    }
    printf("\n");

    /* Deadlock Detection Algorithm */
    done = 0;
    while (done == 0)
    {
        flag = 0;
        for (i = 0; i < tp; i++)
        {
            if (finish[i] == 0)
            {
                int canFinish = 1;
                for (j = 0; j < tr; j++)
                {
                    if (req[i][j] > avail[j])
                    {
                        canFinish = 0;
                        break;
                    }
                }
                if (canFinish)
                {
                    printf("\nProcess %d is transferred to running state and assumed finished", i + 1);
                    for (j = 0; j < tr; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0)
            break;
    }

    /* Deadlock Check */
    int deadlock = 0;
    for (i = 0; i < tp; i++)
    {
        if (finish[i] == 0)
        {
            printf("\nOops! Deadlock detected. Causing process: %d", i + 1);
            deadlock = 1;
        }
    }

    if (!deadlock)
    {
        printf("\n\nHurray! Deadlock not detected :-)\n");
    }
    else
    {
        printf("\n");
    }

    return 0;
}
