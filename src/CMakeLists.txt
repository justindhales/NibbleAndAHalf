include_directories(.)

set(base64_sources base64.c)

add_library(base64 STATIC ${base64_sources})
