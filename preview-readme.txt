# Object-Oriented Programming: An IoT ESP32 Environmental Monitoring System

This project implements a low-cost, student-friendly IoT-based environmental monitoring system that uses an ESP32 devkit V1 (2.4GHz WiFi) and measures the air particulate matter data (PM1, PM2.5, PM10), temperature, humidity, pressure, and geographic location via GPS tracking.

The collected data is displayed locally via a web interface and uploaded to a public ThingSpeak page for remote monitoring.
-  Link: https://thingspeak.mathworks.com/channels/3218864

## Hardware Components
- ESP32 Devkit V1 Module
- ESP32 expansion board with 30 pins
- PMS7003 Air Quality Sensor
- BME280 Environmental Sensor
- NEO-M8N GPS Module

## Software Architecture
-  ESP32 firmware written in C++ (Visual Studio Code PlatformIO)
-  Local 2.4GHz web server for real-time monitoring
-  ThingSpeak cloud integration for data logging and visualization
-  ThingSpeak cloud can still stored logged data eventhough the circuit is disconnected from power. It will reboot and continue logging when the system is powered up again.

## Replication and Deployment
1.  Configure the WiFi credentials in the areas noted in main.cpp
2.  Upload firmware to ESP32 with PlatformIO
3.  Open Serial Monitor to see the ESP32 local web address
4.  Access the local web interface
5.  Create ThingSpeak account and create New Channel
6.  Insert the information for the channel similar to our channel
5.  Monitor historical data via ThingSpeak

## Limitations
-  GPS requires outdoor line-of-sight for satellite lock
-  Local web interface requires ESP32 to be powered
-  Using CloudFlare server for a limited duration to view the website design for this system. The HTML layout is provided in WebServerUI.cpp
-  CloudFlare server is disconnect when the PC turns off -> Lose access to the viewing link and has to set it up again

## License
MIT License. This is an open-source project, feel free to replicate and improve upon the source codes. Good luck!
