// file: implementation for GPS class
#include "GPS.h"
GPS::GPS(HardwareSerial& serial)
    : _serial(serial) {}
void GPS::begin(uint32_t baud) {
    _serial.begin(baud);
}

void GPS::update() {
    while (_serial.available() > 0) {
        _gps.encode(_serial.read());
    }
}
bool GPS::hasFix() {
    return _gps.location.isValid();
}
double GPS::latitude(){
    return _gps.location.lat();
}
double GPS::longitude() {
    return _gps.location.lng();
}
uint32_t GPS::satellites() {
    return _gps.satellites.value();
}