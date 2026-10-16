/*
 * Experiment 9A: Contiguous File Allocation Strategy
 * Source: OS Lab Manual (Ex No: 9A)
 *
 * Description:
 * Simulates contiguous/sequential allocation of files in disk memory blocks.
 * Maintains a file descriptor table recording File ID, Starting Address, and Length.
 * Displays memory state before and after allocation.
 *
 * Correction:
 * Fixed transcription error where length variable `l` was mistakenly transcribed as digit `1`
 * in `(st+1)`, which previously prevented multi-block allocation from being recorded properly.
 */

#include <stdio.h>
#include <stdlib.h>

int a[20], num = 0;
int fid[10], length[10], start[10];

void filedescriptor(void)
{
    int i;
    printf("\nFile ID \t Starting Address \t Length\n");
    for (i = 0; i < num; i++)
        printf("%d\t\t\t %d\t\t\t%d\n", fid[i], start[i], length[i]);
}

void display(void)
{
    int i;
    for (i = 0; i < 20; i++)
        printf("%2d ", i);
    printf("\n");
    for (i = 0; i < 20; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

int main(void)
{
    int i, st, len, id, flag = 0, cho;

    for (i = 0; i < 20; i++)
        a[i] = 0;

    printf("\nMemory before allocation:\n");
    display();

    while (1)
    {
        printf("\nEnter the file id: ");
        if (scanf("%d", &id) != 1) break;

        printf("Enter the number of blocks the file occupies: ");
        if (scanf("%d", &len) != 1 || len <= 0) break;

        fid[num] = id;
        length[num] = len;

    retry:
        printf("Enter the starting address (0-19): ");
        if (scanf("%d", &st) != 1) break;

        flag = 0;
        if ((st + len) > 20)
        {
            printf("\nSorry, the given memory goes out of space.\n");
            goto retry;
        }

        for (i = st; i < (st + len); i++)
        {
            if (a[i] != 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            start[num] = st;
            for (i = st; i < (st + len); i++)
                a[i] = id;
        }
        else
        {
            printf("\nSorry, the given blocks are already occupied. Enter new starting address:\n");
            goto retry;
        }

        flag = 0;
        num++;
        filedescriptor();

        printf("\nMemory after allocation:\n");
        display();

        printf("\nWant to continue? (1 for Yes / 2 for No): ");
        if (scanf("%d", &cho) != 1 || cho == 2)
            break;
    }

    return 0;
}
