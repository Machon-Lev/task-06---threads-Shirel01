
cmake_minimum_required(VERSION 3.15)
project (Ex6_Threads) 
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
add_compile_options ()
endif ()


add_executable(Ex6_Threads
    src/main.cpp
    src/Colors.cpp
    src/Producer.cpp
    src/Consumer.cpp
)
add_subdirectory (include)
add_subdirectory (src)