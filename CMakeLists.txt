cmake_minimum_required(VERSION 3.26)
project(betterShell C)

set(CMAKE_C_STANDARD 11)

add_executable(betterShell main.c
        lib/colors.h
        lib/shell.h
        lib/utils.h
        lib/customCommands.h
)
