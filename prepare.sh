#!/bin/bash

# all nesecery installs
sudo apt update 
sudo apt install libglfw3 libglfw3-dev
sudo apt install build-essential libgl1-mesa-dev xorg-dev
sudo apt install libwayland-dev libxkbcommon-dev 

#create static libraries files for glfw
cmake -S ./Vendor/glfw/ -B ./Vendor/glfw/build
cd ./Vendor/glfw/build
make
cd ../../../

echo "SUCCESSFULL !!!"

