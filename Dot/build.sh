#!/bin/bash

get_time_ms() {
    echo $(($(date +%s%N) / 1000000))
}

echo "Building Dot ... "

rm -rf ./library/libDot.a

# Record start time
start_time=$(get_time_ms)



g++ -c ./source/Dot/Application.cpp -o ./object/Dot/Application.o -I./Vendor/spdlog/include -I./source 
g++ -c ./source/Dot/Logger/Logger.cpp -o ./object/Dot/Logger/Logger.o -I./Vendor/spdlog/include -I./source 
g++ -c ./source/Dot/Window/Platforms/Ubundu/UbunduWindow.cpp -o ./object/Dot/Window/Window.o -I./Vendor/spdlog/include -I./source -I../Vendor/glfw/include

ar rcs ./library/libDot.a  ./object/Dot/Application.o ./object/Dot/Logger/Logger.o ./object/Dot/Window/Window.o # 
#ar rcs ./library/libDot.a ./object/Dot/Application.o ./object/Dot/Logger/Logger.o ./object/Dot/Window/Window.o ./Vendor/glfw/build/src/*.o

# Record end time
end_time=$(get_time_ms)
# Calculate time difference
time_diff=$((end_time - start_time))
# Output the result
echo "Building Dot Core library time: ${time_diff} ms"

rm -rf ./object/Dot/Application.o ./object/Dot/Logger/Logger.o ./object/Dot/Window/Window.o