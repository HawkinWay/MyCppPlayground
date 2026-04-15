cmake_minimum_required(VERSION 3.10)

project(Runoob VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(MyLib src/mylib.cpp src/main.cpp) # create a lib target named MyLib
add_executable(main src/main.cpp) #create a executable file named main

target_link_libraries(main MyLib)


# g++ src/mylib.cpp src/main.cpp -o main
# ./main

