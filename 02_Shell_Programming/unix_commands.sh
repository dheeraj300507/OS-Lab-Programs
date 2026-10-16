#!/bin/bash
while true; do
  echo "1. Today's date"; echo "2. Logged-in users"; echo "3. Home directory"; echo "w. Quit"
  read -rp "Choice: " choice
  case "$choice" in
    1) date;;
    2) who;;
    3) echo "$HOME";;
    w|W) break;;
    *) echo "Invalid choice";;
  esac
done
