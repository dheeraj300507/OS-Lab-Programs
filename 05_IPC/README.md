# Inter-Process Communication (IPC) Using Shared Memory

This directory contains the implementation of Experiment 5 from the lab manual:

- `shm_ipc.c` — IPC using System V Shared Memory (`shmget`, `shmat`, `shmdt`, `shmctl`) and `fork()`.

## Compilation and Execution (Linux / WSL)

This program uses POSIX/System V IPC calls and must be compiled on Linux or WSL:

```bash
gcc shm_ipc.c -o shm_ipc
./shm_ipc
```

### Expected Output
```
abcdefghijklmnopqrstuvwxyz
```

## Note for Windows Users
Windows native compilers (MSVC / standard MinGW) do not include `<sys/shm.h>` or `fork()`. Use WSL (Windows Subsystem for Linux), a Linux VM, or a POSIX compatibility environment to compile and run this program.
