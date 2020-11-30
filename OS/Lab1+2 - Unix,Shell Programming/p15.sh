#!/bin/sh
echo “enter range”
read st 
read en
echo "guess a number between $st and $en"
read num
rand=$(( (RANDOM%en) + st ))
if [ $rand -eq $num ]
then
   echo "Your guess $rand was correct!"
else
   echo "Your guess was wrong $rand was the right answer!"
fi