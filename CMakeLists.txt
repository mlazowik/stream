cmake_minimum_required(VERSION 2.8)
project(stream)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/line_reader.cpp
    src/line_reader.h
    src/primitive_type_reader.cpp
    src/primitive_type_reader.h
    src/reader.h
    src/stream.h
    src/stream_reader.cpp
    src/stream_reader.h
    src/string_reader.cpp
    src/string_reader.h)

add_library(stream ${SOURCE_FILES})

target_include_directories(stream PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})