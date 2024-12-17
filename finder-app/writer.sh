#!/bin/bash

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments are required."
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

writefile=$1
writestr=$2

# Extract the directory path from writefile
directory=$(dirname "$writefile")

# Create the directory path if it does not exist
mkdir -p "$directory"
if [ $? -ne 0 ]; then
    echo "Error: Could not create the directory path '$directory'."
    exit 1
fi


echo "$writestr" > "$writefile"





echo "Successfully wrote to the file '$writefile'."

