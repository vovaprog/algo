#!/bin/bash

if [ -z "$1" ]
then
    echo "USAGE: build_and_run.sh task_name"
    exit -1
fi

cd ./build && cmake .. && make && cd ..

bash ./run_test.sh $1

