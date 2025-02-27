cmake_minimum_required(VERSION 3.5)
project("GPS")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES 
    "estructuras/*.cpp" 
    "clases/*.cpp"
    "prueba.cpp"
)
add_executable(GPS ${SRC_FILES})
