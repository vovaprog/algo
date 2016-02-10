#!/bin/bash

PROGRAM=623a

printf "\n\n\n\n\n\n\n\n"

g++ -g -std=c++11 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1

bash ./codeforces_run_test.sh $PROGRAM

