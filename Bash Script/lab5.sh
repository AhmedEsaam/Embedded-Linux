#!/bin/bash

displayArgs()
{
    # arguments ($0: is always the 'script' name, $1: 'function' arg1, ...)
    echo $0 $1 $2 $3                  
}

# To pass script args to a function inside the script:
displayArgs $1 "Mostafa" "Tera"     # here, $1 is a script arg. not a function arg.
