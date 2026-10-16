# Page Replacement Algorithms

This directory contains implementations of the three page replacement algorithms from Experiment 8 of the lab manual:

- `fifo.c` — Experiment 8A: First-In, First-Out (FIFO) Page Replacement
- `lru.c` — Experiment 8B: Least Recently Used (LRU) Page Replacement
- `optimal.c` — Experiment 8C: Optimal Page Replacement

The original manual excerpt is preserved in `manual_page_replacement_listings.txt`.

## Compilation and Execution

```bash
gcc fifo.c -o fifo
./fifo

gcc lru.c -o lru
./lru

gcc optimal.c -o optimal
./optimal
```

## Corrections Applied
- In `lru.c`: Fixed broken block nesting and syntax corruption from the manual listing, validated against the recorded output screenshot.
- In `optimal.c`: Fixed `intseq[30]` missing space typo and passed frame length parameter to `findmax()` cleanly.
- Added input bounds validation across all three programs.
