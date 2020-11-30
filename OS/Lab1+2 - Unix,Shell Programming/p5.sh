#!/bin/sh
echo "Enter a file/directory name"
read inp
 [ -d "$inp" ] && echo "is a directory"
 [ -f "$inp" ] && echo "is a file"