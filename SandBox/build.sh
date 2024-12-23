#!/bin/bash

rm -rf ./executable/Application
echo "Building SandBox ... "
g++ -o ./executable/SandBox ./source/*.cpp -L./../Dot/library -I./../Dot/include/ -lDot 
