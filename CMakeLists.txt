cmake_minimum_required(VERSION 3.28)
project(malkmusl_engine_cpp)

set(CMAKE_CXX_STANDARD 20)

# Find and link X11 and OpenGL libraries
find_package(X11 REQUIRED)
find_package(OpenGL REQUIRED)

# Set the path to Wayland and EGL headers
set(WAYLAND_INCLUDE_DIR /usr/include)
set(EGL_INCLUDE_DIR /usr/include)

# Find Wayland and EGL libraries
find_library(EGL_LIBRARIES EGL)
find_library(WAYLAND_CLIENT_LIBRARIES wayland-client)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/run/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/run/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/run/)

# Add the main executable
add_executable(malkmusl_engine_cpp
    src/main.cpp
)

add_library(_system SHARED
    src/system/system.hpp
    src/system/system.cpp
    src/system/utils/system_manager.hpp
    src/system/utils/system_manager.cpp
    src/system/utils/system_factory.hpp
    src/system/utils/system_factory.cpp
    src/system/utils/state_name.hpp
    src/system/utils/state_name.cpp
)

add_library(_logger SHARED
    src/logger/logger.cpp
    src/logger/logger.hpp
)

add_library(_hot_reload SHARED
    src/system/core/hot_reload_system.hpp
    src/system/core/hot_reload_system.cpp
)


# Include directories
target_include_directories(malkmusl_engine_cpp PRIVATE 
    src
)

target_include_directories(_system PRIVATE src)
target_include_directories(_logger PRIVATE src)
target_include_directories(_hot_reload PRIVATE src)

# Link libraries
target_link_libraries(malkmusl_engine_cpp 
    dl 
    pthread
    _system
    _logger
    _hot_reload
)
