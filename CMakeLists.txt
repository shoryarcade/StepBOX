cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(stepbox)

pico_sdk_init()
add_subdirectory(drivers/encoder)
add_subdirectory(src)
