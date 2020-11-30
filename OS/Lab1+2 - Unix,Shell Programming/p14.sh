! #/bin/sh
echo "Enter a number"
read n
fact=1
if [ $n -eq 0 ]
then
    echo "Factorial is 1"
else
    for(( i=1 ; i<=$n ; i++ ))
    do
        fact=$((fact*i))
    done

    echo "Factorial is $fact"
fi