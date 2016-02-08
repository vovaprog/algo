#!/bin/bash

PROGRAM=613d_2

printf "\n\n\n\n\n\n\n\n"

g++ -g -std=c++11 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1

bash ./codeforces_run_test.sh $PROGRAM

