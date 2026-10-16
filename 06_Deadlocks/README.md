# Deadlock Avoidance and Detection

This directory contains implementations for Experiment 6 of the lab manual:

- `bankers_avoidance.c` — Experiment 6A: Deadlock Avoidance using Banker's Algorithm
- `bankers_detection.c` — Experiment 6B: Deadlock Detection using Banker's Algorithm

The manual listings are referenced in `manual_bankers_and_detection_listings.txt`.

## Compilation and Execution

```bash
gcc bankers_avoidance.c -o bankers_avoidance
./bankers_avoidance

gcc bankers_detection.c -o bankers_detection
./bankers_detection
```

## Corrections Applied
- Fixed multiline string literal split error in `bankers_avoidance.c` where `printf("\n---------------IT'S AN UNSAFE STATE---------------` was abruptly split across two lines in the manual text.
- Replaced non-standard return signatures with standard `int main(void)` and added input validation.
