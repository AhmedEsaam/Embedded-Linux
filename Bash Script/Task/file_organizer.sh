#!/bin/bash

if [ -d $1 ]; then

    dir=$1


    mkdir -p $dir/images/
    mkdir -p $dir/documents/
    mkdir -p $dir/others/

    cd $dir

    image_files=($(ls *.jpg 2>/dev/null) $(ls *.png 2>/dev/null) $(ls *.gif 2>/dev/null))
    document_files=($(ls *.txt 2>/dev/null) $(ls *.doc 2>/dev/null) $(ls *.pdf 2>/dev/null 2>/dev/null))
    other_files=($(ls -I '*.jpg' -I '*.png' -I '*.gif' -I '*.txt' -I '*.doc' -I '*.pdf' 2>/dev/null))

    for file in ${image_files[@]}; do
        if [ -f $file ]; then
            mv $file ./images/$file
        fi    
    done

    for file in ${document_files[@]}; do
        if [ -f $file ]; then
            mv $file ./documents/$file
        fi    
    done

    for file in ${other_files[@]}; do
        if [ -f $file ]; then
            mv $file ./others/$file
        fi
    done

fi