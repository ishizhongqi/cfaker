# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Define the project name and language (C)
project(cfaker C)

# Set C standard to C11 and make it required
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include header files from the 'include' directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Collect source files from specified directories
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE_LIST)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/providers SOURCE_PROVIDER_LIST)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/providers/data SOURCE_DATA_LIST)

# Set compiler flags based on the platform/compiler
if(MSVC)
    add_compile_options(/W4 /DEBUG)
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -g)
endif()

# Create a static library from the collected source files
add_library(cfaker STATIC 
    ${SOURCE_LIST} 
    ${SOURCE_PROVIDER_LIST} 
    ${SOURCE_DATA_LIST}
)