#!/bin/bash

rm -rf ./executable/Application
echo "Building SandBox ... "
g++ -o ./executable/SandBox ./source/*.cpp -L./../Dot/library -lDot -I./../Dot/include/ #-I../Dot/Vendor/spdlog/include 
