#!/bin/bash
echo "Subdirectories"
directories=$(ls -d */)
for directory in $directories;do
    echo "$directory"
done
