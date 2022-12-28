# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.13)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

# Set name of project (as PROJECT_NAME) and C/C%2B%2B standards
project (Monitor-Control-Firmware_V2 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()     

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME} 
    monitorcontrol.c
    PGA2310/PGA2310.c 
    VUmeter/VUmeter.c 
    VUmeter/display.c
    VUmeter/ssd1306.c


    
)
# Allows for asm to be linked with other obj files
set_property(SOURCE PGA2310data.S APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

# Enable serial usb communication 
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})



# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
    hardware_spi
    hardware_gpio
    hardware_i2c
    hardware_adc
    pico_time

)


# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)