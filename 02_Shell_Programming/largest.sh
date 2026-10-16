#!/bin/bash
read -rp "Enter number of elements: " n
if (( n <= 0 )); then echo "Enter a positive count."; exit 1; fi
read -rp "Enter $n numbers separated by spaces: " -a a
if (( ${#a[@]} < n )); then echo "Not enough numbers entered."; exit 1; fi
largest=${a[0]}
for ((i=1; i<n; i++)); do
  if (( a[i] > largest )); then largest=${a[i]}; fi
done
echo "Largest number: $largest"
