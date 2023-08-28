#ifndef MOISTURE_H
#define MOISTURE_H

void init_sensor_gpionum(int gpioPin);
void init_sensor_adcnum(int pin);
int get_moisture_raw(int gpioPin);//SELECTS ADC PIN AND READS VALUE BE AWARE OF IT
int get_moisture_percent(int adcPin);//SELECTS ADC PIN AND READS VALUE BE AWARE OF IT

#endif
