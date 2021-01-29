cmake_minimum_required(VERSION 3.15)

project(ssl-client LANGUAGES CXX)

add_subdirectory(include ${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_subdirectory(src ${CMAKE_CURRENT_SOURCE_DIR}/bin)
