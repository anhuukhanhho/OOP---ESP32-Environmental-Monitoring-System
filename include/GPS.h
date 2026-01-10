// file: header for GPS class
#ifndef GPS_H
#define GPS_H
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>
// NEO-M8N classes
// Handles UART communication and GPS parsing
class GPS {
public:
    GPS(HardwareSerial& serial); // Bind GPS to serial port
    void begin(uint32_t baud = 9600); // Initialize
    void update(); // Update from serial stream
    TinyGPSPlus& getGPSData(); // Raw GPS data access
    // Status and position access
    bool hasFix();
    double latitude();
    double longitude();
    uint32_t satellites();
private:
    HardwareSerial& _serial; TinyGPSPlus _gps;
};
#endif
