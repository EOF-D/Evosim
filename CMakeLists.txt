cmake_minimum_required(VERSION 3.26)
include(FetchContent)
project(Evosim)

set(CMAKE_CXX_STANDARD 20)

# https://alandefreitas.github.io/moderncpp/guis/opengl-glfw/ Thanks!
find_package(OpenGL)

FetchContent_Declare(glad GIT_REPOSITORY https://github.com/Dav1dde/glad.git GIT_TAG df8e9e16110b305479a875399cee13daa0ccadd9)
FetchContent_MakeAvailable(glad)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.3.2)
FetchContent_MakeAvailable(glfw)

include_directories(lib/imgui)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "include/*.hpp")
file(GLOB_RECURSE IMGUI_FILES "lib/imgui/*.cpp")
file(GLOB_RECURSE IMGUI_HEADERS "lib/imgui/*.h")

add_executable(Evosim src/main.cpp ${SOURCE_FILES} ${HEADER_FILES} ${IMGUI_FILES} ${IMGUI_HEADERS})
target_link_libraries(Evosim PUBLIC glad glfw)