cmake_minimum_required(VERSION 3.12) # minimum cmake version

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake) # import the pico sdk


project(moisture-sample C CXX ASM)

#DONT CHNAGE THINGS BELOW THIS LINE
#ALTTAKİ SATIRLARI DEĞİŞTİRMEYİN

set(CMAKE_C_STANDARD 11) # set the C standard
set(CMAKE_CXX_STANDARD 17) # set the C++ standard

pico_sdk_init() # initialize the sdk

add_subdirectory(moisture_driver) # add the nrf24l01 communication library

add_executable(${PROJECT_NAME} # create the executable
    sample.c
)

target_link_libraries(${PROJECT_NAME} # link the libraries to the executable
    hardware_adc
    hardware_gpio
    pico_stdlib
    moisture
)

# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME}) # add extra outputs like map/bin/hex/uf2 files
