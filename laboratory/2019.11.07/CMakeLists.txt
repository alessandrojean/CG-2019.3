cmake_minimum_required(VERSION 3.15.5)
project(2019-11-07)

set(EXECUTABLE_OUTPUT_PATH "bin")

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(matrices ${SOURCES})

target_link_libraries(matrices glfw GLEW::GLEW OpenGL::OpenGL)
