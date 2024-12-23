#!/bin/bash


echo "Building Dot ... "

rm -rf ./library/libDot.a

g++ -c ./source/Dot/Application.cpp -o ./object/Dot/Application.o

ar rcs ./library/libDot.a  ./object/Dot/Application.o 

rm -rf ./object/Dot/Application.o