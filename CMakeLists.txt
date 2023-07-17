cmake_minimum_required(VERSION 3.12)

project(casino)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#configure_file(${CMAKE_SOURCE_DIR}/assortment.txt ${CMAKE_BINARY_DIR}/assortment.txt COPYONLY)
file(COPY ${CMAKE_SOURCE_DIR}/assortment.txt DESTINATION ${CMAKE_BINARY_DIR}/)

add_executable(${PROJECT_NAME}
${CMAKE_SOURCE_DIR}/src/Bar.cpp
${CMAKE_SOURCE_DIR}/src/Bar.h
${CMAKE_SOURCE_DIR}/src/Casino.cpp
${CMAKE_SOURCE_DIR}/src/Casino.h
${CMAKE_SOURCE_DIR}/src/Funcs.cpp
${CMAKE_SOURCE_DIR}/src/Funcs.h
${CMAKE_SOURCE_DIR}/src/Guest.cpp
${CMAKE_SOURCE_DIR}/src/Guest.h
${CMAKE_SOURCE_DIR}/src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  src
)   
