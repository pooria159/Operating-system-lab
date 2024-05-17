#!bin/bash

n=0
t=0
if (( $1 < $2 ))
then
    for ((a=$1 + 1 ; a < $2 ; a++))
    do
        n=$(( $n + a ))
    done
    echo $(($n / $(( $2- $1 - 1 ))))
elif (( $2 < $1 ))
then
    for ((b=$2 + 1 ; b < $1 ; b++))
    do
        t=$(( $t + b))
    done
    echo $(($t / $(( $1 - $2 - 1 ))))
else
    echo "0"
fi

