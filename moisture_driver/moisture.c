#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "moisture.h"
#include <stdio.h>

#define MAX_RAW_HUMIDITY 4095
#define MIN_RAW_HUMIDITY 0

static const float conversionFactor = 3.3f / (1 << 12);
static bool adcInıtted = false;

void init_sensor_gpionum(int gpioPin) {
    // Set up the pin as an output
    if(adcInıtted == false)
    {
      adc_init();
      adcInıtted = true;
    }

    adc_gpio_init(gpioPin);
}

void init_sensor_adcnum(int pin) {
    // Set up the pin as an output

    if(adcInıtted == false)
    {
      adc_init();
      adcInıtted = true;
    }

    int gpioPin = 26;
    switch (pin)
      {
      case 0:
        gpioPin = 26;
      break;

      case 1:
        gpioPin = 27;
      break;

      case 2:
        gpioPin = 28;
      break;

      default:
        printf("\n\nWARNING: WRONG ADC PIN SELECTED, INITTING ADC0 FOR SENSOR\n\n");
      break;
      }

    adc_gpio_init(gpioPin);
}

int get_moisture_raw(int adcPin) { //SELECTS ADC PIN AND READS VALUE BE AWARE OF IT
  // Read the data from sensor

  adc_select_input(adcPin);

  unsigned int data[40];
  for (int i = 0; i < 40; i++) {
    sleep_us(2);
    data[i] = adc_read() * conversionFactor;

  }

  // Get mean of the moisture datas

  unsigned int moistureValue = 0;
  int length = 40;

  for (int i = 0; i < length; i++) {
      moistureValue += data[i];
  }

  moistureValue /= length;

  return moistureValue;
}

// Function to read the humidity sensor
// Returns the humidity in percent

int get_moisture_percent(int adcPin) {
  // Raw moisture
  int rawMoisture = get_moisture_raw(adcPin);

  // Convert to percent
  unsigned int moisturePercent = (rawMoisture - MIN_RAW_HUMIDITY) * 100 / (MAX_RAW_HUMIDITY - MIN_RAW_HUMIDITY);

  // Return the moisture
  return moisturePercent;
}

