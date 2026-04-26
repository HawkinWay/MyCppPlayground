cmake_minimum_required(VERSION 3.10)

project(Runoob VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# error: add_library(MyLib src/mylib.cpp src/main.cpp)  多重定义main.cpp, 库里不该包含main.cpp

# g++ -c src/mylib.cpp -o mylib.o
# ar rcs libMyLib.a mylib.o
add_library(MyLib STATIC src/mylib.cpp) # create a static lib target named MyLib

# g++ -c src/main.cpp -o main.o
add_executable(main src/main.cpp) #create a executable file named main

# g++ main.o -L. -lMyLib -o main
target_link_libraries(main MyLib)


# g++ src/mylib.cpp src/main.cpp -o main
# ./main

