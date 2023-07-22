cmake_minimum_required(VERSION 3.12)

project(casino)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#configure_file(${CMAKE_SOURCE_DIR}/assortment.txt ${CMAKE_BINARY_DIR}/assortment.txt COPYONLY)
file(COPY ${CMAKE_SOURCE_DIR}/assortment.txt DESTINATION ${CMAKE_BINARY_DIR}/)

add_executable(${PROJECT_NAME}
src/Bar.cpp
src/Bar.h
src/Casino.cpp
src/Casino.h
src/Constants.h
src/Funcs.cpp
src/Funcs.h
src/Guest.cpp
src/Guest.h
src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  src
)   
