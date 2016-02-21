#!/bin/bash

PROGRAM=343a

printf "\n\n\n\n\n\n\n\n"

g++ -std=c++11 -I. -include stdc++.h  -H -g -O2 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1

bash ./codeforces_run_test.sh $PROGRAM

