#!/bin/bash

get_time_ms() {
    echo $(($(date +%s%N) / 1000000))
}

# Record start time
start_time=$(get_time_ms)


rm -rf ./executable/SandBox
echo "Building SandBox ... "
g++ -o ./executable/SandBox ./source/*.cpp -L./../Dot/library -lDot -I./../Dot/include/ -I../Dot/Vendor/spdlog/include  -L../Vendor/glfw/build/src/ -lglfw3

# Record end time
end_time=$(get_time_ms)
# Calculate time difference
time_diff=$((end_time - start_time))
# Output the result
echo "Building Application time: ${time_diff} ms"
