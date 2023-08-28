#ifndef MOISTURE_H
#define MOISTURE_H

void init_sensor(int gpioPin);
int get_moisture_raw(int gpioPin);//SELECTS ADC PIN AND READS VALUE BE AWARE OF IT
int get_moisture_percent(int adcPin);//SELECTS ADC PIN AND READS VALUE BE AWARE OF IT

#endif
