cmake_minimum_required(VERSION 3.10)

project(base64 C)

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
