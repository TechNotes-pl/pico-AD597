# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(pico-temperature C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/AD597.c
    src/leds.c
    src/one_wire.cpp
)

#target_sources(${PROJECT_NAME} INTERFACE
#    ${CMAKE_CURRENT_LIST_DIR}/src/one_wire.cpp
#)

target_include_directories(${PROJECT_NAME} 
    PUBLIC include
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
    hardware_adc
)

# Enable usb output, disable uart output
# By enabling the USB port and disabling the UART port, 
# we can send and receive serial data over USB.
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
