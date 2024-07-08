#!/bin/bash

if [ -f /home/ahmed-essam/.bashrc ]
then
    echo "export HELLO=${HOSTNAME}" >> /home/ahmed-essam/.bashrc
    echo "LOCAL=$(whoami)" >> /home/ahmed-essam/.bashrc

    gnome-terminal
else
    echo ".bashrc is not found"
fi