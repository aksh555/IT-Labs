#!/bin/sh
while read line
do
if [ -d $line ]
    then
       echo directory
    elif [ "$line"="exit" ]
    then
    break
    else
       echo file
    fi
done