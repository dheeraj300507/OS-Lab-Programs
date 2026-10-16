# Process Synchronization using Semaphores

## Required Experiment
**Program:** `process_sync_semaphore.c`

This program fulfills the mandatory requirement for **Process Synchronization using Semaphores**.
It demonstrates mutual exclusion across concurrent worker threads accessing a shared critical section using POSIX semaphores (`sem_init`, `sem_wait`, `sem_post`, `sem_destroy`).

### Compilation and Execution (Linux / WSL / MinGW)

```bash
gcc process_sync_semaphore.c -o process_sync -pthread
./process_sync
```

### Expected Output
```
Process/thread 1 entered critical section
Process/thread 1 leaving critical section
Process/thread 2 entered critical section
Process/thread 2 leaving critical section
Process/thread 3 entered critical section
Process/thread 3 leaving critical section
```

## Manual Listing (Supplementary)
**Program:** `producer_consumer_manual.c`

The attached lab manual listed the bounded-buffer Producer–Consumer problem as Experiment 4. For full fidelity and cross-referencing with the manual, that program is preserved here in `producer_consumer_manual.c`. Note that per repository requirements, `process_sync_semaphore.c` is the primary and official experiment for this lab.

Compile and run:
```bash
gcc producer_consumer_manual.c -o producer_consumer
./producer_consumer
```
