! #/bin/sh
echo "Enter a directory name"
read dir
n="$(find $dir -type f | wc -l)"
echo "There are $n files in $dir"