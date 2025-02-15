#!/bin/bash

get_time_ms() {
    echo $(($(date +%s%N) / 1000000))
}

# Record start time
start_time=$(get_time_ms)


rm -rf ./executable/SandBox
echo "Building SandBox ... "
g++ -g -std=c++17 -o ./executable/SandBox ./source/*.cpp -I./../Vendor/stb_image/include -L./../Vendor/stb_image/library -lstb_image -L./../Dot/library -lDot -L../Vendor/glfw/build/src/ -lglfw3 -L../Vendor/imgui/library/ -limgui -I./../Dot/include/ -I../Dot/Vendor/spdlog/include  

# Record end time
end_time=$(get_time_ms)
# Calculate time difference
time_diff=$((end_time - start_time))
# Output the result
echo "Building Application time: ${time_diff} ms"
