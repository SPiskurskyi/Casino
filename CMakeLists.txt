cmake_minimum_required(VERSION 3.12)

project(casino)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


configure_file(${CMAKE_SOURCE_DIR}/assortment.txt ${CMAKE_BINARY_DIR}/assortment.txt COPYONLY)

add_executable(${PROJECT_NAME}
${CMAKE_SOURCE_DIR}/src/main.cpp
${CMAKE_SOURCE_DIR}/src/Funcs.cpp
${CMAKE_SOURCE_DIR}/src/Guest.cpp
${CMAKE_SOURCE_DIR}/src/Bar.cpp
${CMAKE_SOURCE_DIR}/headers/Casino.hpp
${CMAKE_SOURCE_DIR}/headers/Funcs.h
${CMAKE_SOURCE_DIR}/headers/Guest.h
${CMAKE_SOURCE_DIR}/headers/Bar.h 
)

target_include_directories(${PROJECT_NAME} PRIVATE
  src
  headers
)   
