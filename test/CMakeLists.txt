set(LIBS ${LIBS} base64)

set(base64_test_SRCS main.c testbase64.c Timer.c)

include_directories(. ../src)

add_executable(base64_test ${base64_test_SRCS})
target_link_libraries(base64_test ${LIBS})
