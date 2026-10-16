/*
 * Experiment 5: Inter Process Communication (IPC) Using Shared Memory
 * Source: OS Lab Manual (Ex No: 5)
 *
 * Description:
 * Implements IPC between a parent process and child process using System V Shared Memory.
 * The child process writes characters 'a' through 'z' to shared memory, and the parent
 * reads and prints the memory contents after the child terminates.
 *
 * Requirements:
 * Must be compiled and run in a POSIX/Linux environment (Linux, WSL, or macOS)
 * that supports <sys/ipc.h>, <sys/shm.h>, and fork().
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 27

int main(void)
{
    char c;
    int shmid;
    pid_t childpid;
    key_t key = 5679;
    char *shm, *s;

    /* Create the shared memory segment */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    /* Attach the shared memory segment to our data space */
    if ((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    s = shm;

    /* Create child process */
    if ((childpid = fork()) < 0)
    {
        perror("Fork Failed");
        exit(1);
    }
    else if (childpid == 0)
    {
        /* Child process: write lowercase alphabet to shared memory */
        for (c = 'a'; c <= 'z'; c++)
            *s++ = c;
        *s = '\0';
        exit(0);
    }
    else
    {
        /* Parent process: wait for child, then read from shared memory */
        wait(NULL);
        for (s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        /* Detach and remove shared memory segment */
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
