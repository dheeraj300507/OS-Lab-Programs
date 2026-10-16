# OS-Lab-Programs

A complete, well-organized repository containing all Operating Systems laboratory experiments, programs, and Viva preparation materials based on the official Anna University / KTU Operating Systems Laboratory manual (`OS_RECORD REEBA updated.docx`).

---

## 📌 Repository Overview

This repository provides tested, standardized C implementations and Bash scripts for fundamental Operating Systems concepts, including UNIX commands simulation, Shell scripting, CPU scheduling, Process Synchronization using Semaphores, Inter-Process Communication (IPC), Deadlock avoidance and detection, Memory management, Page replacement, File allocation, and Disk scheduling.

All original program listings from the attached 61-page manual have been extracted, checked, syntax-corrected where OCR/transcription errors occurred, and compiled and verified with GCC and Bash. The original manual is preserved under `source_manual/` for cross-reference.

---

## 🚦 Important Semaphore Requirement Note

> **Mandatory Semaphore Specification:**  
> The required semaphore experiment for this laboratory is **Process Synchronization using Semaphores**, located at:  
> [`04_Process_Synchronization/process_sync_semaphore.c`](04_Process_Synchronization/process_sync_semaphore.c)  
>
> While the laboratory manual featured the Producer–Consumer Problem as Experiment 4, this repository implements **Process Synchronization using POSIX Semaphores** (`sem_init`, `sem_wait`, `sem_post`, `sem_destroy`) to enforce mutual exclusion among concurrent worker threads accessing a shared critical section. For fidelity with the manual, the original bounded-buffer simulation is also preserved as a supplementary reference in [`04_Process_Synchronization/producer_consumer_manual.c`](04_Process_Synchronization/producer_consumer_manual.c).

---

## 📂 Repository Structure & Experiment Index

| Ex No. | Experiment Title | Directory | Source File(s) | Language |
| :---: | :--- | :--- | :--- | :---: |
| **1a** | Basics of UNIX Commands | `01_UNIX_Commands/` | [`README.md`](01_UNIX_Commands/README.md) | Shell / Reference |
| **1b** | Simulation of UNIX Commands (`ls`, `cp`, `grep`, `cat`) | `01_UNIX_Commands/` | [`ls_sim.c`](01_UNIX_Commands/ls_sim.c)<br>[`cp_sim.c`](01_UNIX_Commands/cp_sim.c)<br>[`grep_sim.c`](01_UNIX_Commands/grep_sim.c)<br>[`cat_sim.c`](01_UNIX_Commands/cat_sim.c) | C |
| **2a** | Shell Programming: Largest of N Numbers | `02_Shell_Programming/` | [`largest.sh`](02_Shell_Programming/largest.sh) | Bash |
| **2b** | Implementation of UNIX Commands using `case` | `02_Shell_Programming/` | [`unix_commands.sh`](02_Shell_Programming/unix_commands.sh) | Bash |
| **3A** | First-Come, First-Served (FCFS) Scheduling | `03_CPU_Scheduling/` | [`fcfs.c`](03_CPU_Scheduling/fcfs.c) | C |
| **3B** | Shortest Job First (SJF) Scheduling (Non-preemptive) | `03_CPU_Scheduling/` | [`sjf.c`](03_CPU_Scheduling/sjf.c) | C |
| **3C** | Priority Scheduling (Non-preemptive) | `03_CPU_Scheduling/` | [`priority.c`](03_CPU_Scheduling/priority.c) | C |
| **3D** | Round Robin (RR) Scheduling | `03_CPU_Scheduling/` | [`round_robin.c`](03_CPU_Scheduling/round_robin.c) | C |
| **4** | **Process Synchronization using Semaphores** *(Required)* | `04_Process_Synchronization/` | [`process_sync_semaphore.c`](04_Process_Synchronization/process_sync_semaphore.c) | C (POSIX) |
| **4 (Ref)** | Producer–Consumer Problem using Semaphores *(Manual)* | `04_Process_Synchronization/` | [`producer_consumer_manual.c`](04_Process_Synchronization/producer_consumer_manual.c) | C |
| **5** | Inter-Process Communication using Shared Memory | `05_IPC/` | [`shm_ipc.c`](05_IPC/shm_ipc.c) | C (POSIX / SysV) |
| **6A** | Deadlock Avoidance using Banker's Algorithm | `06_Deadlocks/` | [`bankers_avoidance.c`](06_Deadlocks/bankers_avoidance.c) | C |
| **6B** | Deadlock Detection using Banker's Algorithm | `06_Deadlocks/` | [`bankers_detection.c`](06_Deadlocks/bankers_detection.c) | C |
| **7 (1)** | First Fit Memory Allocation | `07_Memory_Allocation/` | [`first_fit.c`](07_Memory_Allocation/first_fit.c) | C |
| **7 (2)** | Best Fit Memory Allocation | `07_Memory_Allocation/` | [`best_fit.c`](07_Memory_Allocation/best_fit.c) | C |
| **7 (3)** | Worst Fit Memory Allocation | `07_Memory_Allocation/` | [`worst_fit.c`](07_Memory_Allocation/worst_fit.c) | C |
| **8A** | FIFO Page Replacement Algorithm | `08_Page_Replacement/` | [`fifo.c`](08_Page_Replacement/fifo.c) | C |
| **8B** | LRU Page Replacement Algorithm | `08_Page_Replacement/` | [`lru.c`](08_Page_Replacement/lru.c) | C |
| **8C** | Optimal Page Replacement Algorithm | `08_Page_Replacement/` | [`optimal.c`](08_Page_Replacement/optimal.c) | C |
| **9A** | Contiguous File Allocation Strategy | `09_File_Allocation/` | [`contiguous.c`](09_File_Allocation/contiguous.c) | C |
| **9B** | Linked List File Allocation Strategy | `09_File_Allocation/` | [`linked.c`](09_File_Allocation/linked.c) | C |
| **9C** | Indexed File Allocation Strategy | `09_File_Allocation/` | [`indexed.c`](09_File_Allocation/indexed.c) | C |
| **10A** | FCFS Disk Scheduling Algorithm | `10_Disk_Scheduling/` | [`fcfs_disk.c`](10_Disk_Scheduling/fcfs_disk.c) | C |
| **10B** | SCAN (Elevator) Disk Scheduling Algorithm | `10_Disk_Scheduling/` | [`scan_disk.c`](10_Disk_Scheduling/scan_disk.c) | C |
| **10C** | Circular SCAN (C-SCAN) Disk Scheduling Algorithm | `10_Disk_Scheduling/` | [`cscan_disk.c`](10_Disk_Scheduling/cscan_disk.c) | C |
| **Viva** | Lab Record Viva Questions & Answers (Pages 53–61) | `11_Viva_Questions/` | [`README.md`](11_Viva_Questions/README.md) | Markdown |
| **Ref** | Original Lab Manual Word Document | `source_manual/` | [`OS_Lab_Manual.docx`](source_manual/OS_Lab_Manual.docx) | DOCX |

---

## 🛠️ Compilation & Execution Guide

### C Programs (Standard)
Compile with GCC:
```bash
# General syntax
gcc <source_file>.c -o <executable_name>
./<executable_name>
```

### Process Synchronization using Semaphores
Link with POSIX pthread library:
```bash
gcc 04_Process_Synchronization/process_sync_semaphore.c -o process_sync -pthread
./process_sync
```

### Inter-Process Communication (Shared Memory)
Requires Linux/POSIX environment (Linux or WSL):
```bash
gcc 05_IPC/shm_ipc.c -o shm_ipc
./shm_ipc
```

### Shell Scripts
Run with Bash:
```bash
bash 02_Shell_Programming/largest.sh
bash 02_Shell_Programming/unix_commands.sh
```

---

## 🔧 Corrections & Quality Enhancements Made

1. **Modern Standard C Compliance:**
   - Replaced non-standard `void main()` with `int main(void)` and added `return 0;` across all programs.
   - Cleaned up header imports to include `<stdlib.h>`, `<string.h>`, `<fcntl.h>`, and `<unistd.h>`.

2. **Critical OCR & Transcription Fixes:**
   - **`09_File_Allocation/contiguous.c`:** The manual listing contained a critical OCR typo where the block length variable `len` was misprinted as digit `1` in `(st+1)`, causing multi-block files to only allocate a single block. Corrected to `(st + len)`.
   - **`03_CPU_Scheduling/priority.c`:** Fixed typo where `tur[I ]` was printed with uppercase `I` and extra space instead of `tur[i]`.
   - **`06_Deadlocks/bankers_avoidance.c`:** Resolved an unterminated multiline string literal where `printf("\n---------------IT'S AN UNSAFE STATE---------------` was split across lines.
   - **`07_Memory_Allocation/best_fit.c`:** Fixed syntax break where `fragment[i` was split by a newline before `]);`.
   - **`08_Page_Replacement/lru.c`:** Restored corrupted brace nesting and loop conditions (`j- break; -) }`) using the verified screenshot trace from `image19.jpeg` in the manual.
   - **`08_Page_Replacement/optimal.c`:** Fixed missing space in variable declaration `intseq[30]` -> `int seq[30]`.
   - **`04_Process_Synchronization/producer_consumer_manual.c`:** Renamed simulated semaphore helper functions to `wait_op()` and `signal_op()` to avoid linker conflicts with standard POSIX `wait()` in `<sys/wait.h>`.

3. **Input Validation:**
   - Added array boundary and input checks to prevent segmentation faults and buffer overruns.

---

## 🧪 Testing Status Summary

A comprehensive automated test suite was executed across all programs:

| Category | Total Programs | Compiled Successfully | Test Passed | Notes |
| :--- | :---: | :---: | :---: | :--- |
| **UNIX Commands Simulation** | 4 | 4 / 4 | 4 / 4 | Tested `cat`, `cp`, `grep`, `ls` on sample test files. |
| **Shell Programming** | 2 | 2 / 2 (`bash -n`) | 2 / 2 | Verified syntax and interactive execution. |
| **CPU Scheduling** | 4 | 4 / 4 | 4 / 4 | Tested FCFS, SJF, Priority, Round Robin with sample burst times. |
| **Process Synchronization** | 2 | 2 / 2 | 2 / 2 | Tested `process_sync_semaphore` with POSIX threads & `producer_consumer`. |
| **Inter-Process Communication** | 1 | Linux / WSL Only | Linux / WSL Only | Uses `<sys/ipc.h>` and `fork()`; documented environment requirements. |
| **Deadlock Handling** | 2 | 2 / 2 | 2 / 2 | Tested safety check and deadlock detection vectors. |
| **Memory Allocation** | 3 | 3 / 3 | 3 / 3 | Tested First Fit, Best Fit, Worst Fit partition allocation. |
| **Page Replacement** | 3 | 3 / 3 | 3 / 3 | Tested FIFO, LRU (verified 7 faults), Optimal algorithms. |
| **File Allocation** | 3 | 3 / 3 | 3 / 3 | Tested Contiguous, Linked, and Indexed allocation schemes. |
| **Disk Scheduling** | 3 | 3 / 3 | 3 / 3 | Tested FCFS, SCAN, C-SCAN head movement calculations. |
| **TOTAL** | **27 items** | **26 / 27** | **26 / 27** | **100% of portable C & Bash programs compiled & passed.** |

---

## 📜 License
Educational laboratory repository for academic learning and Operating Systems coursework.
