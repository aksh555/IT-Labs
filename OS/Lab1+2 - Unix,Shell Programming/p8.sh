#!/bin/sh
# prints length of longest line in given line
read -p "Enter the path of the file: " file
 
length=$(wc -L $file)
echo "$length is the length of the longest line in the file"

echo "Following lines duplicated:"
sort $file | sed '$!N; s/^\(.*\)\n\1$/\1/; t; D'
#sort $file|uniq -c -d 