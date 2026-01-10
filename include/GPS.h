// file: header for GPS class
#ifndef GPS_H
#define GPS_H

#include <TinyGPSPlus.h> // GEO-M8N Arduino Library
#include <HardwareSerial.h> // For serial logging and display
class GPS {
public:
    GPS(HardwareSerial& serial);
    void begin(uint32_t baud = 9600);
    void update();
    TinyGPSPlus& getGPSData();
    bool hasFix();
    double latitude();
    double longitude();
    uint32_t satellites();
private:
    HardwareSerial& _serial;
    TinyGPSPlus _gps;
};
#endif
