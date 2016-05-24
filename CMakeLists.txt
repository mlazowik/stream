cmake_minimum_required(VERSION 2.8)
project(stream)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        stream/line_reader.cpp
        stream/line_reader.h
        stream/primitive_type_reader.h
        stream/reader.h
        stream/stream.h
        stream/stream_reader.cpp
        stream/stream_reader.h
        stream/string_reader.cpp
        stream/string_reader.h)

add_library(stream ${SOURCE_FILES})

target_include_directories(stream PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})