cmake_minimum_required(VERSION 3.10)

project(CppFundamentals_ VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all source files
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

# Create executable with all sources
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Compiler flags
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -O2)
endif()

# Include current directory
target_include_directories(${PROJECT_NAME} PRIVATE .)