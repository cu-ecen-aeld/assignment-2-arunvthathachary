#!/bin/bash
# bash script to get number of matches of str in given directory
# Author: Arun V Thathachary

#echo "script name:" $0
#echo "num of args:" $#
#### check num args
if [[ $# -eq 2 ]];
then
    filesdir="$1"
    searchstr="$2"
    #echo "$filesdir"
    #echo "$searchstr"
    #### check if directory
    if [ -d "$filesdir" ]
    then
        cd "$filesdir"
        numFiles=$(find . -type f | wc -l) # find all files in current dir and count lines and convert to variable
        numMatches=$(grep ${searchstr} * | wc -l) # search for string in all the files/sub-dirs and count lines
        echo "The number of files are $numFiles and the number of matching lines are $numMatches"
        exit 0
    else
        echo "$filesdir is not a directory"
        exit 1
    fi
else
    echo "ERROR, require 2 inputs: file dir path, search string"
    exit 1
fi