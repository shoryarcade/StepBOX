cmake_minimum_required(VERSION 3.13)

add_executable(stepbox)

target_sources(stepbox PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/board.cpp
        ${CMAKE_CURRENT_LIST_DIR}/device.cpp
        ${CMAKE_CURRENT_LIST_DIR}/gamepad.cpp
        ${CMAKE_CURRENT_LIST_DIR}/keyboard.cpp
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../drivers/tinyusb/usb_descriptors.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../modules/leds/leds.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../modules/leds/phasing.cpp
        )
        
target_include_directories(stepbox PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/../include
        ${CMAKE_CURRENT_LIST_DIR}/../modules
        ${CMAKE_CURRENT_LIST_DIR}/../modules/leds
        ${CMAKE_CURRENT_LIST_DIR}/../drivers/tinyusb
        )


target_link_libraries(stepbox PUBLIC
        pico_stdlib
        pico_multicore
        tinyusb_device
        tinyusb_board
        hardware_pio
        encoder
        ws2812b
        )

pico_add_extra_outputs(stepbox)
