cmake_minimum_required(VERSION 3.10)

project(base64)

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
