#!/bin/bash

cpp_files = (
    "./Source/vec.cpp" ,
    "./Source/mat.cpp" , 
    "./Source/common.cpp" );

obj_files =[
    "./Object/vec.o" ,
    "./Object/mat.o" ,
    "./Object/common.o"
];

for i in range(cpp_files) loop 
    g++ -g -std=c++17 -c $cpp_files[$i] -o $obj_files[$i]

#g++ -g -std=c++17 -c ./Source/vec.cpp -o ./Object/vec.o
#g++ -g -std=c++17 -c ./Source/mat.cpp -o ./Object/mat.o
#g++ -g -std=c++17 -c ./Source/common.cpp -o ./Object/common.o


ar rcs ./Library/libDotMath.a $obj_files