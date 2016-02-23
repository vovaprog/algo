#!/bin/bash

PROGRAM=613d_3

printf "\n\n\n\n\n\n\n\n"

g++ -std=c++11 -I. -include stdc++.h -g -O2 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1
#g++ -std=c++11 -g -O2 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1

printf "\n\nbuild time: $SECONDS\n\n"

bash ./codeforces_run_test.sh $PROGRAM

