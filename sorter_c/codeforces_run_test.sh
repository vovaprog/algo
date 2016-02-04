#!/bin/bash

PROGRAM=$1

for i in ./test_data/$PROGRAM/*
do
    echo $i
    cat $i | ./$PROGRAM
    echo
done    
