#!/bin/sh
echo Enter the filename:
read filename
echo Enter the starting number:
read s
echo Enter the ending line number:
read e
sed -n $s,$e\p filename | cat>new
cat new