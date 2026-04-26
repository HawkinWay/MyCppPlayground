cmake_minimum_required(VERSION 4.3.1)

project(NoID VERSION 0.0.1)

add_subdirectory(modules/JUCE)

set(CMAKE_CXX_STANDARD 20)

if(APPLE)
	#
	#
	#
	#
	#
endif()

if(UNIX AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
	find_package(PkgConfig REQUIRED)
	#

	include_directories(${WEBKIT2_INCLUDE_DIRS})
	#
	#
	#
endif()

# Disable all warnings
add_definitions(-w)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules/cmake-include/sudara-cmake")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE INTERNAL "")
endif()

# Define the plugin
juce_add_plugin("${PROJECT_NAME}"
	#
	#
	#
	#
)


add_compile_definitions(JUCE_PROJECT_NAME="${PROJECT_NAME}")


file(GLOB_RECURSE SourceFiles CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/source/*.h"
)


target_sources("${PROJECT_NAME}" PRIVATE ${SourceFiles})


file(GLOB_RECURSE Assets "${CMAKE_CURRENT_SOURCE_DIR}/assets/*.*")

juce_add_binary_data(AudioPluginData SOURCES ${Assets})


# Ensure AudioPluginData is built before the main project
add_dependencies(${PROJECT_NAME} AudioPluginData)

target_link_libraries("${PROJECT_NAME}" PRIVATE
	Sharedcode
	AudioPluginData
	juce::juce_audio_basics
	#
	#
	#
	PUBLIC
	juce:juce_recommended_config_flags
	#
	#
	#
)



