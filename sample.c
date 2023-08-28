#include "moisture_driver/moisture.h"
#include "pico/stdlib.h"

int main() {
  int adcPin = 0;
  init_sensor_adcnum(adcPin);

  int percentageMoisture = 0;
  int rawMoisture = 0;

  while (true)
    {
      sleep_ms(1000);
      percentageMoisture = get_moisture_percent(adcPin);
      rawMoisture = get_moisture_raw(adcPin);
      printf("\nMOISTURE RAW:%d\nMOISTURE PERCENT:%d", rawMoisture,percentageMoisture);
    }
}
