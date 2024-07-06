#!/bin/bash
options=("display date and time" "List files in the current directory" "Display current disk usage" "Exit")

PS3="Please enter your choice: "

select option in "${options[@]}"
do
    case $option in
    "display date and time")
        date
        ;;
    "List files in the current directory")
        ls
        ;;
    "Display current disk usage")
        df -h
        ;;
    "Exit")
        echo "Goodbye!"
        exit
        ;;
    *)
        echo "Invalid input"
        ;;
    esac    
    break
done