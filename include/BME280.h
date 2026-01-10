// file: header for BME280 class
#ifndef BME280_H
#define BME280_H
#include <Adafruit_BME280.h>
// BME280 classes
// Encapsulates temperature, humidity, pressure readings
class BME280 {
public:
    bool begin(uint8_t address = 0x76); // Initialize via I2C
    void update(); // Update measurements
    // Access methods
    float temperature() const;
    float humidity() const;
    float pressure() const;
private:
    Adafruit_BME280 _bme; // Hardware library object
    float _temperature = 0; // Cached values
    float _humidity = 0;
    float _pressure = 0;
};
#endif
