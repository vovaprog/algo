#!/bin/bash

PROGRAM=$1

for i in ./test_data/$PROGRAM/*.txt
do
    echo "====== $i ======"
    SECONDS=0
    cat $i | ./$PROGRAM
    RUN_SECONDS=$SECONDS
    
    if [ -f $i.answer ] 
    then
        echo     "============== answer =============="
        cat $i.answer        
    fi
    
    printf "\n====================================\n"
    printf "run time: $RUN_SECONDS\n\n\n\n"
done    

