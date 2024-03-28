cmake_minimum_required(VERSION 3.20)

project(fixedcapbimap)

# include_directories(include)

add_compile_options(-Wall -g)

FILE(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include/)
