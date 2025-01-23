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



g++ -std=c++17 -c ./source/Dot/Application.cpp                             -o ./object/Dot/Application.o                               -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Logger/Logger.cpp                           -o ./object/Dot/Logger/Logger.o                             -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Window/Platforms/Ubundu/UbunduWindow.cpp    -o ./object/Dot/Window/Window.o                             -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Window/Platforms/Ubundu/UbunduInput.cpp     -o ./object/Dot/Window/Input.o                              -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Layer/Layer.cpp                             -o ./object/Dot/Layer/Layer.o                               -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Layer/LayerStack.cpp                        -o ./object/Dot/Layer/LayerStack.o                          -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Layers/ImguiLayer/ImguiLayer.cpp            -o ./object/Dot/Layers/ImguiLayer/ImguiLayer.o              -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderApi/GraphicsContext.cpp      -o ./object/Dot/Renderer/RenderApi/GraphicsContext.o        -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderApi/OpenGL/OpenGLContext.cpp -o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLContext.o   -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderApi/OpenGL/OpenGLShader.cpp  -o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLShader.o    -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderApi/Buffer.cpp               -o ./object/Dot/Renderer/RenderApi/Buffer.o                 -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderApi/OpenGL/OpenGLBuffer.cpp  -o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLBuffer.o    -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderApi/RendererApi.cpp          -o ./object/Dot/Renderer/RenderApi/RendererApi.o            -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/Renderer.cpp                       -o ./object/Dot/Renderer/Renderer.o                         -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderCommand.cpp                  -o ./object/Dot/Renderer/RenderCommand.o                    -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/RenderApi/OpenGL/OpenGLRendererApi.cpp  -o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLRendererApi.o    -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD
g++ -std=c++17 -c ./source/Dot/Renderer/Camera.cpp                          -o ./object/Dot/Renderer/Camera.o                          -I./source/Dot/Pch  -include dotpch.h -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include -I../Vendor/glad/include -I./../Vendor/imgui/include -I../Vendor/glm -DIMGUI_IMPL_OPENGL_LOADER_CUSTOM -DIMGUI_IMPL_OPENGL_LOADER_GLAD

ar rcs ./library/libDot.a ./object/Dot/Renderer/Camera.o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLRendererApi.o ./object/Dot/Renderer/RenderCommand.o ./object/Dot/Renderer/Renderer.o ./object/Dot/Renderer/RenderApi/RendererApi.o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLBuffer.o ./object/Dot/Renderer/RenderApi/Buffer.o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLShader.o ./object/Dot/Renderer/RenderApi/GraphicsContext.o ./object/Dot/Application.o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLContext.o ./object/Dot/Window/Input.o ./object/Dot/Logger/Logger.o ./object/Dot/Window/Window.o  ./object/Dot/Layer/Layer.o ./object/Dot/Layer/LayerStack.o  ./../Vendor/glad/obj/glad.o ./object/Dot/Layers/ImguiLayer/ImguiLayer.o


# Record end time
end_time=$(get_time_ms)
# Calculate time difference
time_diff=$((end_time - start_time))
# Output the result
echo "Building Dot Core library time: ${time_diff} ms"

rm -rf ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLRendererApi.o ./object/Dot/Renderer/RenderCommand.o ./object/Dot/Renderer/Renderer.o ./object/Dot/Renderer/RenderApi/RendererApi.o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLBuffer.o ./object/Dot/Renderer/RenderApi/Buffer.o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLShader.o ./object/Dot/Renderer/RenderApi/GraphicsContext.o ./object/Dot/Application.o ./object/Dot/Renderer/RenderApi/OpenGL/OpenGLContext.o ./object/Dot/Window/Input.o ./object/Dot/Logger/Logger.o ./object/Dot/Window/Window.o  ./object/Dot/Layer/Layer.o ./object/Dot/Layer/LayerStack.o ./object/Dot/Layers/ImguiLayer/ImguiLayer.o