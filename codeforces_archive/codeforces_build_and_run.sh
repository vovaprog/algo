#!/bin/bash

PROGRAM=$1

printf "\n\n\n\n\n\n\n\n"

mkdir -p ./bin

g++ -O0 -g -std=c++11 -I. -include stdc++.h ./$PROGRAM.cpp -o ./bin/$PROGRAM || exit 1
#g++ -std=c++11 -g -O2 ./$PROGRAM.cpp -o ./$PROGRAM || exit 1

printf "\n\nbuild time: $SECONDS\n\n"

bash ./codeforces_run_test.sh $PROGRAM ./bin

