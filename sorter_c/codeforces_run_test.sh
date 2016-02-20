#!/bin/bash

PROGRAM=$1

for i in ./test_data/$PROGRAM/*.txt
do
    echo "====== $i ======"
    cat $i | ./$PROGRAM
    
    if [ -f $i.answer ] 
    then
        echo     "============== answer =============="
        cat $i.answer        
    fi
    
    printf "\n====================================\n\n\n\n"
done    

