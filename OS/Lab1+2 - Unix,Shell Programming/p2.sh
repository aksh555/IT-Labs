# !/bin/sh
echo "Enter Two numbers : "
read a 
read b
echo "Enter an operator:"
echo "+ for addition"
echo "- for subtraction"
echo "x for multiplication"
echo "/ for division"
echo "% for modulus"

read ch

case $ch in
+)res=$((a+b)) 
;;
-)res=$((a-b))
;;
x)res=$((a*b))
;;
/)res=$((a/b))
;;
%)res=$((a%b))
;;
esac
echo "$a $ch $b = $res"
