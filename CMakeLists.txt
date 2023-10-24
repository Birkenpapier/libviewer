cmake_minimum_required(VERSION 3.10)

project(PPMViewer)

set(CMAKE_CXX_STANDARD 14)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(PPMViewer csrc/main.cpp csrc/loadppm.cpp)

# Link against both GLFW and OpenGL
target_link_libraries(PPMViewer PRIVATE glfw OpenGL::GL)
