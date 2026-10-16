# Disk Scheduling Algorithms

This directory contains implementations of the disk arm scheduling algorithms from Experiment 10 of the lab manual:

- `fcfs_disk.c` — Experiment 10A: First-Come, First-Served (FCFS) Disk Scheduling
- `scan_disk.c` — Experiment 10B: SCAN (Elevator) Disk Scheduling
- `cscan_disk.c` — Experiment 10C: Circular SCAN (C-SCAN) Disk Scheduling

The manual excerpt is preserved in `manual_disk_scheduling_listings.txt`.

## Compilation and Execution

```bash
gcc fcfs_disk.c -o fcfs_disk
./fcfs_disk

gcc scan_disk.c -o scan_disk
./scan_disk

gcc cscan_disk.c -o cscan_disk
./cscan_disk
```

## Details
- `fcfs_disk.c` tracks head transitions between sequential requested cylinders, computing total and average head movement.
- `scan_disk.c` services requests towards track 0, reverses to the maximum requested cylinder, and outputs seek trajectory.
- `cscan_disk.c` services towards max cylinder, jumps to track 0 without service, and services remaining lower cylinder requests.
