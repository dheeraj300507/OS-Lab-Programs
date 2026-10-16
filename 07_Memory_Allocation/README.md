# Memory Allocation Methods

This directory contains implementations of the contiguous memory allocation algorithms from Experiment 7 of the lab manual:

- `first_fit.c` — First Fit Allocation
- `best_fit.c` — Best Fit Allocation
- `worst_fit.c` — Worst Fit Allocation

The original manual excerpt is preserved in `manual_memory_allocation_listings.txt`.

## Compilation and Execution

```bash
gcc first_fit.c -o first_fit
./first_fit

gcc best_fit.c -o best_fit
./best_fit

gcc worst_fit.c -o worst_fit
./worst_fit
```

## Corrections Applied
- In `best_fit.c`: Replaced `void main()` with `int main(void)` and resolved the broken `fragment[i` newline split.
- Added input bounds validation across all programs to prevent buffer overruns.
