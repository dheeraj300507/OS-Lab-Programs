/*
 * Experiment 10C: Circular SCAN (C-SCAN) Disk Scheduling Algorithm
 * Source: OS Lab Manual (Ex No: 10C)
 *
 * Description:
 * Simulates C-SCAN disk scheduling. The head services requests towards the maximum
 * disk cylinder, jumps from the maximum cylinder to cylinder 0 without servicing
 * any requests during the jump, and then continues servicing remaining requests.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int queue[50], queue1[50], queue2[50];
    int head, max, n;
    int i, j, temp;
    int temp1 = 0, temp2 = 0;
    int seek = 0, diff;
    float avg;

    printf("Enter maximum disk range: ");
    if (scanf("%d", &max) != 1 || max <= 0) return 1;

    printf("Enter initial head position: ");
    if (scanf("%d", &head) != 1 || head < 0 || head > max) return 1;

    printf("Enter number of requests: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n >= 50) return 1;

    printf("Enter disk queue requests:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
            queue1[temp1++] = temp;
        else
            queue2[temp2++] = temp;
    }

    /* Sort requests >= head ascending */
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    /* Sort requests < head ascending */
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    int k = 0;
    queue[k++] = head;

    for (i = 0; i < temp1; i++)
        queue[k++] = queue1[i];

    queue[k++] = max;
    queue[k++] = 0;

    for (i = 0; i < temp2; i++)
        queue[k++] = queue2[i];

    printf("\nC-SCAN Disk Scheduling Order:\n");
    for (i = 0; i < k - 1; i++)
    {
        diff = abs(queue[i + 1] - queue[i]);
        seek += diff;
        printf("%d -> %d  (Seek = %d)\n", queue[i], queue[i + 1], diff);
    }

    printf("\nTotal Seek Time = %d\n", seek);
    avg = (float)seek / n;
    printf("Average Seek Time = %.2f\n", avg);

    return 0;
}
