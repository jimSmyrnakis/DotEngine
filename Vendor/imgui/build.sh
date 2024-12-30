#!/bin/bash

g++ -c ./src/imgui_demo.cpp         -o ./obj/imgui_demo.o         -I./../glfw/include -I./include -include ./../glad/include/glad/glad.h -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM
g++ -c ./src/imgui_draw.cpp         -o ./obj/imgui_draw.o         -I./../glfw/include -I./include -include ./../glad/include/glad/glad.h -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM
g++ -c ./src/imgui_impl_glfw.cpp    -o ./obj/imgui_impl_glfw.o    -I./../glfw/include -I./include -include ./../glad/include/glad/glad.h -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM
g++ -c ./src/imgui_impl_opengl3.cpp -o ./obj/imgui_impl_opengl3.o -I./../glfw/include -I./include -include ./../glad/include/glad/glad.h -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM
g++ -c ./src/imgui_tables.cpp       -o ./obj/imgui_tables.o       -I./../glfw/include -I./include -include ./../glad/include/glad/glad.h -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM
g++ -c ./src/imgui_widgets.cpp      -o ./obj/imgui_widgets.o      -I./../glfw/include -I./include -include ./../glad/include/glad/glad.h -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM
g++ -c ./src/imgui.cpp              -o ./obj/imgui.o              -I./../glfw/include -I./include -include ./../glad/include/glad/glad.h -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM

ar rcs ./library/libimgui.a ./obj/imgui.o ./obj/imgui_widgets.o ./obj/imgui_tables.o ./obj/imgui_demo.o ./obj/imgui_draw.o  ./obj/imgui_impl_glfw.o ./obj/imgui_impl_opengl3.o

rm -rf ./obj/imgui.o ./obj/imgui_widgets.o ./obj/imgui_tables.o ./obj/imgui_demo.o ./obj/imgui_draw.o  ./obj/imgui_impl_glfw.o ./obj/imgui_impl_opengl3.o
