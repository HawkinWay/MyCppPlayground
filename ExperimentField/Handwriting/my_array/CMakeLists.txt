cmake_minimum_required(VERSION 4.2.3)

project(my_array)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(arrayExc source/main.cpp)

# target_include_directories(arrayExc PUBLIC include)

# add_library(arrayLib STATIC include/my_array.h)
 
# target_link_libraries(arrayExc arrayLib)

