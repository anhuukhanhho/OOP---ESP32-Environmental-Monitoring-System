// file: implementation for PMS7003 class
#include "PMS7003.h"

PMS7003::PMS7003(HardwareSerial& serial)
    : _serial(serial), _pms(serial) {}

void PMS7003::begin(uint32_t baud) {
    _serial.begin(baud);
}
bool PMS7003::update() {
    PMS::DATA data;
    if (_pms.read(data)) {
        _pm1_0 = data.PM_AE_UG_1_0;
        _pm2_5 = data.PM_AE_UG_2_5;
        _pm10 = data.PM_AE_UG_10_0;
        return true;
    }
    return false;
}

uint16_t PMS7003::pm1() const {
    return _pm1_0;
}
uint16_t PMS7003::pm25() const {
    return _pm2_5;
}
uint16_t PMS7003::pm10() const {
    return _pm10;
}