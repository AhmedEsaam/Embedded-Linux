#!/bin/bash

# Check if the .bashrc file is in the user's home
if [ -f ~/.bashrc ]
then

    # Append new environment variable 'HELLO' with the HOSTNAME value 
    echo "export HELLO=${HOSTNAME}" >> ~/.bashrc
    # Append local variable LOCAL with the value of the 'whoami' command
    echo "LOCAL=$(whoami)" >> ~/.bashrc

    # Open another terminal
    gnome-terminal

else
    echo ".bashrc is not found"
fi