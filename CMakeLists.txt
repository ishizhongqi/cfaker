cmake_minimum_required(VERSION 3.10)
project(cfaker C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 头文件目录
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# 源文件列表
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SOURCE_LIST)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/providers SOURCE_PROVIDER_LIST)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/providers/data SOURCE_DATA_LIST)

add_definitions("-Wall -g")

# 生成静态库
add_library(cfaker STATIC ${SOURCE_LIST} ${SOURCE_PROVIDER_LIST} ${SOURCE_DATA_LIST})

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})
