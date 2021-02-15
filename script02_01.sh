#!/bin/bash

argc=$#
one=1
if [[ $# != $one ]]; then
    echo "usage: ./script02.sh <path>"
else
    echo "Looking for files with extension .txt in folder:"
    dir=$1
    echo "  $dir"
    cd $dir
    count=0

    for file in $dir/*.txt; do
        if [[ -e "$file" ]]; then
        ar=$(($count +1))
        fi
    done
    if [[ $count != 0 ]];then
        echo "$count files found:"
        for file in $dir/*.txt; do
            base=${file##*/}
            echo -e "\t$base"
        done
    else
        echo "No file found."
    fi
fi
