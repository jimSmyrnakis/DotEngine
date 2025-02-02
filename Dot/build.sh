#!/bin/bash

get_time_ms() {
    echo $(($(date +%s%N) / 1000000))
}

echo "Building Dot ... "

rm -rf ./library/libDot.a

# Record start time
start_time=$(get_time_ms)

# Ορισμός του αρχείου header και του αντίστοιχου precompiled header (.gch)
HEADER_FILE="../../dotpch.h"
PCH_FILE="../../dotpch.h.gch"

# Έλεγχος αν το αρχείο .gch υπάρχει
if [ ! -f "./source/Dot/Pch/dotpch.h.gch" ]; then
    echo "File PCH ./source/Dot/Pch/dotpch.h.gch not exists . Creating File..."
    # Δημιουργία του PCH με την εντολή g++ -c++header
    g++ -std=c++17 -x c++-header ./source/Dot/Pch/dotpch.h -o ./source/Dot/Pch/dotpch.h.gch  -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM #-DIMGUI_IMPL_OPENGL_LOADER_GLAD
    if [ $? -eq 0 ]; then
        echo "File PCH ./source/Dot/Pch/dotpch.h.gch generated succesfully!"
    else
        echo "File PCH ./source/Dot/Pch/dotpch.h.gch failed to generated."
    fi
else
    echo "File PCH ./source/Dot/Pch/dotpch.h.gch exists"
fi


g++  -std=c++17 -c ./source/Dot/Application.cpp                           -o ./object/Dot/Application.o                            -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++  -std=c++17 -c ./source/Dot/Logger/Logger.cpp                         -o ./object/Dot/Logger/Logger.o                          -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++  -std=c++17 -c ./source/Dot/Window/Platforms/Ubundu/UbunduComp.cpp    -o ./object/Dot/Window/UbunduComp.o                      -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++  -std=c++17 -c ./source/Dot/Layer/LayerComp.cpp                       -o ./object/Dot/Layer/LayerComp.o                        -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++  -std=c++17 -c ./source/Dot/Layers/ImguiLayer/ImguiLayer.cpp          -o ./object/Dot/Layers/ImguiLayer/ImguiLayer.o           -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++  -std=c++17 -c ./source/Dot/Renderer/RenderApi/OpenGL/OpenGLComp.cpp  -o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLComp.o   -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++  -std=c++17 -c ./source/Dot/Renderer/RenderApi/RenderApiComp.cpp      -o ./object/Dot/Renderer/RenderApi/RenderApiComp.o       -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++  -std=c++17 -c ./source/Dot/Renderer/RendererComp.cpp                 -o ./object/Dot/Renderer/RendererComp.o                  -I./source/Dot/Pch   -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD


ar rcs ./library/libDot.a ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLComp.o ./object/Dot/Renderer/RenderApi/RenderApiComp.o ./object/Dot/Renderer/RendererComp.o ./object/Dot/Application.o ./object/Dot/Logger/Logger.o ./object/Dot/Window/UbunduComp.o  ./object/Dot/Layer/LayerComp.o  ./../Vendor/glad/obj/glad.o ./object/Dot/Layers/ImguiLayer/ImguiLayer.o


# Record end time
end_time=$(get_time_ms)
# Calculate time difference
time_diff=$((end_time - start_time))
# Output the result
echo "Building Dot Core library time: ${time_diff} ms"
