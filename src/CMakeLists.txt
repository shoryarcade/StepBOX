cmake_minimum_required(VERSION 3.13)

add_executable(stepbox)

target_sources(stepbox PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/device.cpp
        ${CMAKE_CURRENT_LIST_DIR}/gamepad.cpp
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/usb_descriptors.cpp
        )

# Make sure TinyUSB can find tusb_config.h
target_include_directories(stepbox PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/../include
        )

target_link_libraries(stepbox PUBLIC
        pico_stdlib
        tinyusb_device
        tinyusb_board
        )


pico_add_extra_outputs(stepbox)
