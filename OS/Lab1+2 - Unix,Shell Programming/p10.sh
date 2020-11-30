#! /bin/sh
echo Enter the filename:
read fname
echo Enter the word to be deleted:

read word
sed -ie /$word/d $fname
cat $fname