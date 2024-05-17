#!bin/bash

state="Done"
badstate="is unreachable"
ping -c 12 $1
if (( $? == 0 ))
then
    echo $state
else
    echo $1 $badstate 
fi


