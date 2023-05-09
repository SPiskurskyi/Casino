cmake_minimum_required(VERSION 3.0)

project(casino)

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
