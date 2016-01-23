#!/bin/bash

PROGRAM=615a

g++ -DMAIN ./$PROGRAM.cpp -o ./$PROGRAM

for i in ./test_data/$PROGRAM/*
do
    echo $i
    cat $i | ./$PROGRAM
    echo
done    
