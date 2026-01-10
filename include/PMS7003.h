// file: header for PMS7003 class
#ifndef PMS7003_H
#define PMS7003_H

#include <HardwareSerial.h> // For serial logging and display
#include <PMS.h> // PMS-master Library from https://github.com/fu-hsi/PMS
class PMS7003 {
public:
    PMS7003(HardwareSerial& serial);
    void begin(uint32_t baud = 9600);
    bool update();
    uint16_t pm1() const;
    uint16_t pm25() const;
    uint16_t pm10() const;
private:
    HardwareSerial& _serial;
    PMS _pms;
    uint16_t _pm1_0 = 0;
    uint16_t _pm2_5 = 0;
    uint16_t _pm10 = 0;
};
#endif
