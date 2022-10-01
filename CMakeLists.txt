cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# include(pico-sdk/pico_sdk_init.cmake)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(stepbox)

pico_sdk_init()
add_subdirectory(src)
