// file: implementation for BME280 class
#include "BME280.h"

bool BME280::begin(uint8_t address) {
    return _bme.begin(address);
}
void BME280::update() {
    _temperature = _bme.readTemperature();
    _humidity = _bme.readHumidity();
    _pressure = _bme.readPressure() / 100.0F;
}
float BME280::temperature() const {
    return _temperature;
}
float BME280::humidity() const {
    return _humidity;
}
float BME280::pressure() const {
    return _pressure;
}