#!/bin/bash

PROGRAM=$1
PROGRAM_FOLDER=$2

if [ -z "$PROGRAM_FOLDER" ]
    then PROGRAM_FOLDER="./"    
fi

for i in ./test_data/$PROGRAM/*.txt
do
    echo "====== $i ======"
    SECONDS=0
    cat $i | $PROGRAM_FOLDER/$PROGRAM
    RUN_SECONDS=$SECONDS
    
    if [ -f $i.answer ] 
    then
        echo     "============== answer =============="
        cat $i.answer        
    fi
    
    printf "\n====================================\n"
    printf "run time: $RUN_SECONDS\n\n\n\n"
done    

