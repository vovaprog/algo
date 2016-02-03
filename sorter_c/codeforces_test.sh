#!/bin/bash

PROGRAM=609e

g++ -g -std=c++11 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1

for i in ./test_data/$PROGRAM/*
do
    echo $i
    cat $i | ./$PROGRAM
    echo
done    
