#!/bin/bash

PROGRAM=609e

printf "\n\n\n\n\n\n\n\n"

g++ -g -std=c++11 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1

bash ./codeforces_run_test.sh $PROGRAM

