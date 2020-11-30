# !/bin/sh

echo "Enter a file name to get word frequency and type exit to quit"

while read line
do
    if [ "$line" = "exit" ]
    then break
    else
        echo "Words in $line"
        cat $line|tr -d '[:punct:]'|tr '[:upper:]' '[:lower:]'|tr -s ' ' '\n'|sort|uniq -c|sort -rn
    fi
done
