cmake_minimum_required(VERSION 4.3.1)

project(shits)

add_library(shits adder.cpp)

set_target_properties(shits PROPERTIES PUBLIC_HEADER adder.h)

install(TARGETS shits LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include/shits
	)
