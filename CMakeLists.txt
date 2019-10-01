cmake_minimum_required(VERSION 3.14)
project(fillit C)

file(GLOB LIBFT
        "*.c"
        "libft/*.c"
        "libft/libft.h")

set(CMAKE_C_STANDARD 99)

add_executable(fillit  ${LIBFT})