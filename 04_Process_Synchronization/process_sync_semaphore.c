/* Process/thread synchronization using a POSIX semaphore: one worker enters a critical section at a time. */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define WORKERS 3
sem_t mutex;

void *worker(void *arg) {
    int id = *(int *)arg;
    sem_wait(&mutex);
    printf("Process/thread %d entered critical section\n", id);
    sleep(1);
    printf("Process/thread %d leaving critical section\n", id);
    sem_post(&mutex);
    return NULL;
}

int main(void) {
    pthread_t threads[WORKERS];
    int ids[WORKERS];
    if (sem_init(&mutex, 0, 1) != 0) { perror("sem_init"); return 1; }
    for (int i = 0; i < WORKERS; i++) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, worker, &ids[i]) != 0) { perror("pthread_create"); return 1; }
    }
    for (int i = 0; i < WORKERS; i++) pthread_join(threads[i], NULL);
    sem_destroy(&mutex);
    return 0;
}
