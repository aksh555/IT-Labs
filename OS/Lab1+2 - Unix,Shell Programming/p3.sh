# !/bin/sh
echo "Enter a number to check even/odd"
read n
rem=$((n%2))
if [ $rem  == 1 ]
then
	echo "$n is odd"
else
	echo "$n is even"
fi


