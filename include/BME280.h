// file: header for BME280 class
#ifndef BME280_H
#define BME280_H

#include <Adafruit_BME280.h> // Adafruit’s BME280 Library
class BME280 {
public:
    bool begin(uint8_t address = 0x76);
    void update();
    float temperature() const;
    float humidity() const;
    float pressure() const;
private:
    Adafruit_BME280 _bme;
    float _temperature = 0;
    float _humidity = 0;
    float _pressure = 0;
};
#endif
