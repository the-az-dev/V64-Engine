cmake_minimum_required(VERSION 3.28)
project(V64_Engine)

set(CMAKE_CXX_STANDARD 17)

# Set path to the `include` directory
include_directories(${CMAKE_SOURCE_DIR}/Libraries/include)

# Set path to the `lib` directory
link_directories(${CMAKE_SOURCE_DIR}/Libraries/lib)

add_library(V64_Engine STATIC v64engine.cpp
        core/window.cpp
        include/window.h
        core/event.cpp
        include/event.h
        game/object.cpp
        include/object.h
        core/render.cpp
        include/render.h)
