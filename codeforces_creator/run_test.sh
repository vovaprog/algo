#!/bin/bash

if [ -z "$1" ]
then
    echo "USAGE: run_test.sh task_name"
    exit -1
fi

TASK=$1

for i in ./test_data/$TASK/*.txt
do
    echo "====== $i ======"
    SECONDS=0
    cat $i | ./build/codeforces
    RUN_SECONDS=$SECONDS

    if [ -f $i.answer ] 
    then
        echo     "============== answer =============="
        cat $i.answer
    fi

    printf "\n====================================\n"
    printf "run time: $RUN_SECONDS\n\n\n\n"
done

