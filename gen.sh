#!/bin/bash

# Check if both arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <target_directory> <number_of_files>"
    exit 1
fi

TARGET_DIR=$1
NUM_FILES=$2
TEMPLATE="template.cpp"

# Check if template file exists
if [ ! -f "$TEMPLATE" ]; then
    echo "Error: $TEMPLATE not found in the current directory."
    exit 1
fi

# Create the directory if it doesn't exist
mkdir -p "$TARGET_DIR"

# Loop to create files based on the alphabet
for ((i=0; i<NUM_FILES; i++)); do
    # Convert index to ASCII character (65 is 'A')
    CHAR=$(printf "\\$(printf '%03o' $((65 + i)))")
    
    FILENAME="${TARGET_DIR}/${CHAR}.cpp"
    
    cp "$TEMPLATE" "$FILENAME"
done

echo "Successfully generated $NUM_FILES .cpp files in '$TARGET_DIR/'"