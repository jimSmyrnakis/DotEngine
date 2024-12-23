#!/bin/bash

echo "./build.sh --do={Build,Rebuild} [--execute] , where Build is for Building only the SandBox and Rebuild for Building the hole project "

if test $# -lt 1 ; then 
    echo "Error : at least one parameter must exist , more precise the parameter --do={Build,Rebuild} must exist "; 
    exit 1;
fi;

if test $# -gt 2 ; then 
    echo "Error : Too many parameters "
    exit 1
fi 

if test $1 == "--do=Build" ; then 
    
    echo "Building ... "
    cd ./SandBox/
    ./build.sh
    cd ./../

elif test $1 == "--do=Rebuild" ; then 
    
    echo "Rebuilding ..."
    cd ./Dot/
    ./build.sh
    cd ./../SandBox
    ./build.sh
    cd ./../
    
else 

    echo  "Error first parameter must be --do={Build,Rebuild} or more precise --do=Build or --do=Rebuild "
    exit 1

fi;

if test $# -eq 2 ; then 
    if test $2 == "--execute" ; then 
        echo "Execute... "
        ./SandBox/executable/Application
    else
        
        echo "Error : undefined parameter "
        exit 1

    fi;
fi;

