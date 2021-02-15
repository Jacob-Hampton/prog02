#!/bin/bash

argc=$#
one=1
argv=$@
extens=[]
i=1
outF=$1
inF=$2
for args in $argv;do
    if [[ i > 2 ]];then
        extens=("${exens[$i]}" "$args")
    fi
    i=$(( i + 1))
done

for exten in "${extens[@]}";do
    newDir=$inF/$exten
    echo `mkdir $newDir`
    echo $exten 
    echo $newDir

    for file in $outF/*.$exten;do
        echo `mv $file $inF/$exten`
     done
done
