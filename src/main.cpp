// file: main application file for ESP32 Air Quality Station with Web UI
#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <HTTPClient.h>
#include "WebServerUI.h"
#include "GPS.h"
#include "BME280.h"
#include "PMS7003.h"

// ---- Local 2.4GHz WiFi only !! ----
const char* ssid = " ---------- ";
const char* password = " ---------- ";
const char* THINGSPEAK_API_KEY = " ---------- ";
const char* THINGSPEAK_SERVER  = "http://api.thingspeak.com/update";

// ---- Objects ----
WebServer server(80);
HardwareSerial GPSSerial(2);  // UART2
HardwareSerial PMSSerial(1);  // UART1
BME280 bme;
GPS gps(GPSSerial);
PMS7003 pms(PMSSerial);
WebServerUI webUI(server, bme, gps, pms);

void setup() {
  Serial.begin(115200);
// --- PMS7003 UART 1 ---
  PMSSerial.begin(9600, SERIAL_8N1, 26, 27);
// --- I2C ---
  Wire.begin(21, 22);
  if (!bme.begin(0x76)) {
    Serial.println("❌ BME280 not found");
  } else {
    Serial.println("✅ BME280 detected");
  }
// --- GPS UART 2 ---
  GPSSerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.println("GPS UART started");
// --- Wi-Fi connection loop ---
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(1000);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
// --- For the Wi-fi to work properly: --- 
// Feedback with timeout
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
    if (millis() - startAttemptTime > 15000) {
      Serial.println("\n❌ WiFi FAILED, restarting...");
      ESP.restart();
    }
  }
  Serial.println("\n✅ WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
// Web server: URL handlers
  webUI.begin();
  server.begin();
  Serial.println("🌐 Web server started");
}

void sendToThingSpeak(
    float temp,
    float hum,
    float pres,
    uint16_t pm1,
    uint16_t pm25,
    uint16_t pm10,
    double lat,
    double lng  ) {
    if (WiFi.status() != WL_CONNECTED) return;
    HTTPClient http;

    String url = String(THINGSPEAK_SERVER) +
        "?api_key=" + THINGSPEAK_API_KEY +
        "&field1=" + String(temp) +
        "&field2=" + String(hum) +
        "&field3=" + String(pres) +
        "&field4=" + String(pm1) +
        "&field5=" + String(pm25) +
        "&field6=" + String(pm10) +
        "&field7=" + String(lat, 6) +
        "&field8=" + String(lng, 6);

    http.begin(url);
    http.GET();
    http.end();
}
void loop() {
  gps.update();
  bme.update();
  pms.update();

// Send data to ThingSpeak every 15 seconds
unsigned long lastThingSpeakUpdate = 0;
  if (millis() - lastThingSpeakUpdate > 15000) {
    lastThingSpeakUpdate = millis();
    sendToThingSpeak(
        bme.temperature(),
        bme.humidity(),
        bme.pressure(),
        pms.pm1(),
        pms.pm25(),
        pms.pm10(),
        gps.latitude(),
        gps.longitude()
    );
  }
  static unsigned long lastPMS = 0;
  if (millis() - lastPMS >= 1000) {
    lastPMS = millis();
    if (pms.update()) {}
  }
  server.handleClient();
}