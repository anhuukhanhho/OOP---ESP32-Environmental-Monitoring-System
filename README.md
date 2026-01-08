# OOP---ESP32-Environmental-Monitoring-System
This ESP32-based IoT system contains a PMS7003 sensor, a BME280 sensor, NEO-M8N GPS, and with ThingSpeak integration. This is an open-source project for the OOP class at Vietnamese-German University.

## **OVERVIEW**
This project implements a low-cost, modular environmental monitoring system using an ESP32 DevKit V1. The system measures particulate matter (PM1, PM2.5, PM10), temperature, humidity, atmospheric pressure, and geographic location, and provides real-time data visualization through both a local web server and a cloud-based platform. The project was developed as part of an Object-Oriented Programming (OOP) course, emphasizing modular software design, sensor integration, and practical IoT deployment.

## **AUTHORS**
→ Mr. _**Ho Huu Khanh An**_ | Ms. _**Dang Quynh Huong**_ | Mr. _**Le Nhan Anh Duong**_
→ VGU ECE class of 2023

## Repository Structure
- src/ → Main firmware source files
- lib/ → Sensor libraries
- include/ → Header files
- report/ → The pdf report for our project
- .github/workflows → C/C++ CI workflow configuration
- test/ → build programs to test out sensors operation and integration
- platformio.ini

-------

## **SYSTEM ARCHITECTURE**
The ESP32 acts as the central microcontroller, interfacing with multiple digital sensors via UART and I2C communication protocols. This dual-output design enables both real-time local monitoring and long-term remote data analysis. Sensor data are processed locally and transmitted to two independent outputs:
- A lightweight local web server (LAN access)
- A ThingSpeak cloud dashboard (remote access)

-------

## **HARDWARE**
- **ESP32 DevKit V1 (30-pin)** – Main controller with integrated Wi-Fi
- **PMS7003** – Optical particulate matter sensor (PM1 / PM2.5 / PM10)
- **BME280** – Temperature, humidity, and pressure sensor
- **NEO-M8N GPS module** – Location and time reference
- **30-pin ESP32 breakout shield** – Structured wiring and modular expansion
- **5V USB power supply / power bank** – Indoor and portable operation
- (optional) **tplink EC120-F5 router** – Public-to-Private WiFi configuration

-------

## **SOFTWARE DESIGN**
The firmware is written in C/C++ using Visual Studio Code and PlatformIO and follows object-oriented programming principles. Each sensor is encapsulated within its own class, enabling modular initialization, data acquisition, and error handling. It manages sensor polling, data formatting, and communication with both local and cloud-based servers. Key libraries used in this project:
- PMS7003 sensor library (courtesy of https://github.com/fu-hsi/PMS)
- Adafruit BME280 library
- TinyGPSPlus library
- ESP32 WebServer.h library

-------

## **DATA VISUALIZATION**
### **Local Web Server**
- Hosted directly on the ESP32
- Accessible via local IP on a 2.4 GHz Wi-Fi network
- Displays live sensor readings and GPS coordinates
- Includes a Google Maps shortcut for deployment location
- Auto-refresh interval: 4 seconds

### **ThingSpeak Cloud Platform**
- Data uploaded via HTTP REST API
- Public dashboard with time-series graphs
- Auto-update interval: 15 seconds
- Supports long-term data storage and export

-------

## **POWER REQUIREMENT**
The system operates from a regulated 5V 2A supply and is also suitable for power bank operation. Average current consumption allows several hours of continuous monitoring depending on battery capacity. Basic power estimation formulas are provided in the project report folder for deployment planning.

-------

## **KNOWN LIMITATIONS**
- Limited to 2.4 GHz Wi-Fi networks
- No onboard data storage when offline
- Manual Wi-Fi credential update required for new networks
- GPS signal loss possible in indoor environments
- Weather protection and airflow depend on enclosure design
- Low-cost sensors may require periodic calibration or replacement
- Extended power loss periods might requires accessing Serial Terminal on PlatformIO to identify new local URL
