# Raspberry-Pi-Pico-Soil-Moisture-Driver
A generic soil moisture driver for the ones selled in the web

## How To Use ?
Connect your moisture unit to GND 3v3 and any ADC (analog to digital converter) pin
![PINS](https://github.com/MertKalkanci/Raspberry-Pi-Pico-Soil-Moisture-Driver/blob/main/pins.png)
copy ```moisture_driver``` folder to your project folder
in main projects cmake file add these:
```cmake
add_subdirectory(moisture_driver) # add the soil moisture library

target_link_libraries(${PROJECT_NAME} # add these libraries there to link to the executable
    hardware_adc
    pico_stdlib
    moisture
)
```

in c file import them with:

```c
#include "moisture_driver/moisture.h"
```

Inıt with ADC pin number
```c
init_sensor_adcnum(0);// you can define or make a variable for your pin
```
or use GPIO pin number
```c
init_sensor_gpionum(26);// you can define or make a variable for your pin
```
Get raw data with:
```c
int raw =  get_moisture_raw(0); //you have to select pin with ADC pin number 
```

Get percentage data with:
```c
int percentage = get_moisture_percent(0); //you have to select pin with ADC pin number 
```
