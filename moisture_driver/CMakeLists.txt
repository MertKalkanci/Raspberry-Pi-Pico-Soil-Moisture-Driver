add_library(moisture INTERFACE)

target_sources(moisture
    INTERFACE
      ${CMAKE_CURRENT_LIST_DIR}/moisture.c
      )
target_link_libraries(moisture # link the libraries to the executable
	INTERFACE
    	hardware_adc
	hardware_gpio
    	pico_stdlib
    )
