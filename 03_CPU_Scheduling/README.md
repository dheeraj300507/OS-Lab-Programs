# CPU Scheduling Algorithms

This directory contains C implementations for the four CPU scheduling algorithms from Experiment 3 of the lab manual:

- `fcfs.c` — Experiment 3A: First Come First Served (FCFS) Scheduling
- `sjf.c` — Experiment 3B: Shortest Job First (SJF) Scheduling (Non-preemptive)
- `priority.c` — Experiment 3C: Priority Scheduling (Non-preemptive)
- `round_robin.c` — Experiment 3D: Round Robin (RR) Scheduling

The original manual excerpt is preserved in `manual_cpu_scheduling_listings.txt`.

## Compilation and Execution

Compile with GCC:

```bash
gcc fcfs.c -o fcfs
./fcfs

gcc sjf.c -o sjf
./sjf

gcc priority.c -o priority
./priority

gcc round_robin.c -o round_robin
./round_robin
```

## Corrections Applied
- Changed obsolete `void main()` signatures to standard `int main(void)` with proper return codes.
- Fixed typo in `priority.c` where `tur[I ]` had an uppercase `I` with whitespace instead of `tur[i]`.
- Added input bounds checks to prevent array index out-of-bounds.
- Cleaned up Gantt chart line alignment formatting.
