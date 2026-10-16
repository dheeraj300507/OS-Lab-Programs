# File Allocation Strategies

This directory contains implementations of the file allocation methods from Experiment 9 of the lab manual:

- `contiguous.c` — Experiment 9A: Contiguous File Allocation
- `linked.c` — Experiment 9B: Linked List File Allocation
- `indexed.c` — Experiment 9C: Indexed File Allocation

The original manual excerpt is preserved in `manual_file_allocation_listings.txt`.

## Compilation and Execution

```bash
gcc contiguous.c -o contiguous
./contiguous

gcc linked.c -o linked
./linked

gcc indexed.c -o indexed
./indexed
```

## Corrections Applied
- In `contiguous.c`: Fixed critical transcription/OCR error in the manual where the file length variable `len` was misprinted as `1` in `(st+1)`, which previously caused multi-block files to only allocate a single block. Corrected loop condition to `st + len` to allocate all requested blocks.
- Replaced label collision and obsolete `void main()` signatures with standard `int main(void)`.
