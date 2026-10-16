# Lab Viva Questions and Answers

This document preserves the Viva Questions from the final section of the lab manual (pages 53–61) along with comprehensive, concise answers for exam and practical preparation.

---

### Operating Systems & Fundamentals

1. **What is an Operating System?**
   An Operating System (OS) is system software that acts as an intermediary between computer hardware and computer users. It manages hardware resources (CPU, memory, I/O devices, storage) and provides a convenient platform for executing application programs.

2. **What are the primary functions of an Operating System?**
   - Processor Management (CPU Scheduling)
   - Memory Management (Allocation, Paging, Segmentation)
   - File System Management (Creation, Access, Allocation)
   - Device/I/O Management (Buffering, Caching, Device Drivers)
   - Security and Protection (Access control, user isolation)

3. **What is the difference between Preemptive and Non-Preemptive scheduling?**
   - **Preemptive:** The CPU can be taken away from a running process before it completes its CPU burst (e.g., Round Robin, Shortest Remaining Time First).
   - **Non-Preemptive:** Once the CPU has been allocated to a process, the process keeps the CPU until it terminates or switches to a waiting state (e.g., FCFS, standard SJF).

4. **What is a Semaphore?**
   A semaphore is a synchronization tool introduced by Edsger Dijkstra. It is an integer variable accessed only through two standard atomic operations: `wait()` (or `P()`) and `signal()` (or `V()`). A binary semaphore takes values 0 or 1 and acts as a mutex lock, whereas a counting semaphore takes unrestricted non-negative values to control access to a finite set of resources.

5. **What is a Critical Section?**
   A critical section is a portion of code that accesses shared resources (such as shared variables, files, or memory) that must not be accessed concurrently by more than one process or thread. Any valid critical section solution must satisfy:
   - Mutual Exclusion
   - Progress
   - Bounded Waiting

6. **What is Deadlock and what are the four necessary conditions for Deadlock?**
   A deadlock is a situation where a set of processes are blocked because each process is holding a resource and waiting for another resource acquired by some other process.
   Four Coffman conditions:
   1. **Mutual Exclusion:** At least one resource must be held in a non-shareable mode.
   2. **Hold and Wait:** A process must be holding at least one resource and waiting to acquire additional resources held by others.
   3. **No Preemption:** Resources cannot be forcibly preempted from a process; they can only be released voluntarily.
   4. **Circular Wait:** A closed chain of processes exists such that each process holds at least one resource needed by the next process in the chain.

7. **Explain Banker's Algorithm.**
   Banker's Algorithm is a deadlock avoidance algorithm developed by Edsger Dijkstra. When a process requests resources, the system checks whether allocating them leaves the system in a **safe state** (a state where there exists at least one sequence of process executions that allows all processes to complete without deadlock). If safe, allocation proceeds; if unsafe, the process must wait.

8. **What is Internal vs. External Fragmentation?**
   - **Internal Fragmentation:** Memory that is internal to an allocated partition but is not used (occurs in fixed partitioning / paging when allocated blocks are larger than requested size).
   - **External Fragmentation:** Total free memory space exists to satisfy a request, but the available space is not contiguous and cannot be allocated.

9. **Compare First Fit, Best Fit, and Worst Fit memory allocation.**
   - **First Fit:** Allocates the first hole that is big enough. Fast search.
   - **Best Fit:** Allocates the smallest hole that is big enough. Minimizes leftover hole size, but produces tiny unusable fragments.
   - **Worst Fit:** Allocates the largest available hole. Leaves the largest remaining hole which may be usable for subsequent requests.

10. **What is Page Fault and Page Replacement?**
    A page fault occurs when a program attempts to access a page that is mapped in the virtual address space but is not currently loaded in physical memory (RAM). The operating system handles the fault by reading the required page from disk swap/backing store into a free frame. If no frames are free, a page replacement algorithm (FIFO, LRU, Optimal) selects a victim page to swap out.

11. **Compare FIFO, LRU, and Optimal Page Replacement.**
    - **FIFO:** Replaces the page that was brought into memory earliest. May suffer from Belady's Anomaly.
    - **LRU:** Replaces the page that has not been referenced for the longest period in the past. Approximates optimal without future knowledge.
    - **Optimal:** Replaces the page that will not be used for the longest period of time in the future. Theoretical benchmark (cannot be implemented practically without future clairvoyance).

12. **What are the common File Allocation Methods?**
    - **Contiguous Allocation:** Each file occupies a set of contiguous blocks on disk. Fast sequential and direct access, but suffers from external fragmentation and difficult file growth.
    - **Linked List Allocation:** Each file is a linked list of disk blocks. No external fragmentation, but slow direct/random access.
    - **Indexed Allocation:** All block pointers for a file are gathered together into an index block. Supports efficient direct access without external fragmentation, but introduces index block overhead.

13. **Compare FCFS, SCAN, and C-SCAN Disk Scheduling.**
    - **FCFS:** Services I/O requests in arrival order. Fair, but high average seek time.
    - **SCAN (Elevator):** The disk arm starts at one end and moves toward the other end, servicing requests along the way, then reverses direction at the boundary.
    - **C-SCAN (Circular SCAN):** The disk arm moves in only one direction servicing requests until it reaches the end, then immediately jumps back to the beginning without servicing requests on the return trip, providing a more uniform wait time.

---

### Questions from Lab Record (Artificial Intelligence & Search Strategies)

The record manual concludes with supplementary Viva questions on AI search algorithms and agents:

14. **Define Artificial Intelligence (AI).**
    Artificial Intelligence is the branch of computer science devoted to creating systems capable of performing tasks that typically require human intelligence, such as visual perception, speech recognition, decision-making, and problem solving.

15. **What is a Rational Agent?**
    A rational agent is one that acts so as to achieve the best outcome or, when there is uncertainty, the best expected outcome based on its percept sequence and built-in knowledge.

16. **What is PEAS description?**
    PEAS stands for Performance measure, Environment, Actuators, and Sensors. It specifies the task environment for designing an intelligent agent.

17. **Differentiate Uninformed Search and Informed Search.**
    - **Uninformed (Blind) Search:** Searches state space using only problem definitions and transition rules without domain-specific hints (e.g., BFS, DFS, Uniform Cost Search).
    - **Informed (Heuristic) Search:** Uses a heuristic evaluation function $h(n)$ to estimate closeness to the goal (e.g., Greedy Best-First Search, A* Search).

18. **What is A\* Search?**
    A* Search evaluates nodes by combining the path cost from the start node $g(n)$ and the estimated heuristic cost to goal $h(n)$:
    $$f(n) = g(n) + h(n)$$
    It is complete and optimal if the heuristic function $h(n)$ is admissible (never overestimates the true cost to reach the goal) and consistent.
