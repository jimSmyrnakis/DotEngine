#!/bin/bash

# all nesecery installs
echo "Install nesecery packages for ubundu ..."
sudo apt update 
sudo apt install libglfw3 libglfw3-dev
sudo apt install build-essential libgl1-mesa-dev xorg-dev
sudo apt install libwayland-dev libxkbcommon-dev 

#create static libraries files for glfw
echo "compile , build and generate glfw project library ..."
cmake -S ./Vendor/glfw/ -B ./Vendor/glfw/build
cd ./Vendor/glfw/build
make
cd ../../../

#compile glad 
echo "Compile and build glad object file ..."
g++ -c ./Vendor/glad/src/glad.c -o ./Vendor/glad/obj/glad.o -I./Vendor/glad/include

#compile linked and create static library for imgui
echo "compile linked and create static library for imgui ..."
cd ./Vendor/imgui
./build.sh
cd ../..

echo "SUCCESSFULL !!!"

