#!/bin/bash

echo "script name: $0"

echo "Total number of element values: $@"

# example of using the exit status variable '$?'
ls -23124               # $? = 2
if [ $? -eq 0 ]; then   # the condition evaluated to 1 => $? became 1 
    echo "all good"
else
    echo "error $?"     # prints error 1
fi