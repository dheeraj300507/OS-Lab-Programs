/*
 * Experiment 4: Producer Consumer Problem Using Semaphores (Manual Listing)
 * Source: OS Lab Manual (Ex No: 4)
 *
 * NOTE: As per lab requirements, the primary experiment is Process Synchronization
 * using Semaphores (implemented in process_sync_semaphore.c).
 * This file preserves the exact bounded-buffer simulation program extracted
 * from Experiment 4 of the manual for reference and completeness.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

struct process {
    char a[5];
} buffer[SIZE];

int mutex = 1, full = 0, empty = SIZE;

/* Function prototypes using _op suffix to avoid collision with POSIX symbols */
int wait_op(int s);
int signal_op(int s);

int main(void)
{
    int ch, i;
    char item[5];

    printf("\n\tProducer Consumer Problem\n");
    while (1)
    {
        printf("\n1. Producer");
        printf("\n2. Consumer");
        printf("\n3. Buffer Contents");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        if (scanf("%d", &ch) != 1)
            break;

        switch (ch)
        {
        case 1: /* Producer */
            if (empty == 0)
            {
                printf("\nBuffer is Full\n");
                break;
            }
            empty = wait_op(empty);
            mutex = wait_op(mutex);
            printf("Enter item to produce: ");
            scanf("%4s", item);
            strcpy(buffer[full].a, item);
            full++;
            printf("Item Produced Successfully\n");
            mutex = signal_op(mutex);
            break;

        case 2: /* Consumer */
            if (full == 0)
            {
                printf("\nBuffer is Empty\n");
                break;
            }
            full = wait_op(full);
            mutex = wait_op(mutex);
            printf("Consumed item: %s\n", buffer[0].a);
            /* Shift buffer */
            for (i = 0; i < full - 1; i++)
                strcpy(buffer[i].a, buffer[i + 1].a);
            full--;
            empty = signal_op(empty);
            mutex = signal_op(mutex);
            break;

        case 3: /* Display */
            if (full == 0)
            {
                printf("\nBuffer is Empty\n");
            }
            else
            {
                printf("\nBuffer Contents:\n");
                for (i = 0; i < full; i++)
                    printf("%s\n", buffer[i].a);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}

/* Semaphore operations */
int wait_op(int s)
{
    return --s;
}

int signal_op(int s)
{
    return ++s;
}
