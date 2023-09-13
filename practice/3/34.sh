#!/bin/bash

read -r pattern

files=$(ls)

for file in $files; do

  # Check if the pattern is available in the file
  if grep -q "$pattern" "$file"; then
    echo "Pattern '$pattern' found in file '$file'"
  else
    echo "Pattern '$pattern' not found in file '$file'"
  fi
done
