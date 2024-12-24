#!/bin/bash


echo "Building Dot ... "

rm -rf ./library/libDot.a

g++ -c ./source/Dot/Application.cpp -o ./object/Dot/Application.o -I./Vendor/spdlog/include -I./source
g++ -c ./source/Dot/Logger.cpp      -o ./object/Dot/Logger.o      -I./Vendor/spdlog/include -I./source

ar rcs ./library/libDot.a  ./object/Dot/Application.o ./object/Dot/Logger.o

rm -rf ./object/Dot/Application.o ./object/Dot/Logger.o