#!/bin/bash

mkdir -p ~/myDirectory/secondDirectory/
touch ~/myDirectory/secondDirectory/myNotePaper
cd ~/myDirectory/
cp secondDirectory/myNotePaper .
mv myNotePaper myoldNotePaper