! #/bin/sh

echo "Enter the source file"
read f1
echo "Enter the destination file"
read f2

cp $f1 $f2
echo "$f1 was copied to $f2"