#!/bin/bash


if [ $# -ne 2 ]; then
    echo "Error: Two arguments are required."
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

filesdir=$1
searchstr=$2


if [ ! -d "$filesdir" ]; then
    echo "Error: The specified path '$filesdir' is not a directory."
    exit 1
fi

# Find the number of files in the directory and subdirectories
file_count=$(find "$filesdir" -type f | wc -l)

# Find the number of matching lines containing searchstr
match_count=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)


echo "The number of files are $file_count and the number of matching lines are $match_count"

