# !/bin/sh

echo "Enter number of elements"
read n

declare -a arr
echo "Enter array elements"
for(( i=0 ; i<$n ; i++))
do
	read ele
	arr[$i]=$ele
done
echo "Array contents:"
echo -e "${arr[@]}"
echo "Enter a search element"
read sele
f=0
for(( i=0 ; i<$n ; i++))
do
	if [ $sele -eq $((arr[$i])) ]
		then  
			echo "$sele found at $(( i+1 ))"
			f=1
			break
	fi
done
if [ $f -eq 0 ]
	then 
		echo "$sele not found"
fi		