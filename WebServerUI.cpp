// file: implementation for WebServerUI class
#include "WebServerUI.h"
WebServerUI::WebServerUI(
    WebServer& server,
    BME280& bme,
    GPS& gps,
    PMS7003& pms
)
: _server(server), _bme(bme), _gps(gps), _pms(pms) {}
void WebServerUI::begin() {
    _server.on("/", [this]() {
        this->handleRoot();
    });
}
void WebServerUI::handleRoot() {
    _server.send(200, "text/html", generatePage());
}
String WebServerUI::generatePage() {
// --- HTML structure ---
    String html = "<!DOCTYPE html><html><head>";
    html += "<meta charset='utf-8'>";
    html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
    html += "<meta http-equiv='refresh' content='4'>"; // Auto refresh every 4 secs
    html += "<style>";
    html += "body{font-family:Arial;background:#f2f2f2;text-align:center;font-size:14px;}";
    html += ".box{background:#fff;padding:10px 10px 20px 10px;margin:10px;border-radius:15px;}";
    html += "h1{color:#333;}";
    html += "</style></head><body>";
    html += "<h1>ESP32 Environmental Station</h1>";
    html += "<p>By students:</p>";
    html += "<p>Ho Huu Khanh An - 1357406<br>Dang Quynh Huong - 10223028<br>Le Nhan Anh Duong - 10222049</p>";
// --- BME280 ---
    html += "<div class='box'><h2>BME280 Module</h2>";
    html += "Temperature: " + String(_bme.temperature()) + " 'C<br>";
    html += "Humidity: " + String(_bme.humidity()) + " %<br>";
    html += "Pressure: " + String(_bme.pressure() / 100.0F) + " hPa</div>";
// --- PMS7003 ---
    html += "<h2>PMS7003 Air Quality</h2>";
    html += "<p>Unit of measurement:<br>microgram per cubic meter (ug/m^3)</p>";
    html += "PM1.0: " + String(_pms.pm1()) + " ug/m^3<br>";
    html += "PM2.5: " + String(_pms.pm25()) + " ug/m^3<br>";
    html += "PM10: " + String(_pms.pm10()) + " ug/m^3<br>";
// --- GPS NEO-M8N ---
    html += "<div class='box'><h2>GPS Module:</h2>";
    if (_gps.hasFix()) {
        html += "Lat: " + String(_gps.latitude(), 6) + "<br>";
        html += "Lng: " + String(_gps.longitude(), 6) + "<br>";

        html += "<a href='https://www.google.com/maps?q="
        + String(_gps.latitude(), 6) + ","
        + String(_gps.longitude(), 6) +
        "' target='_blank'>"
        "<button style='background-color:#4CAF50;color:white;font-size:14px;padding:10px 20px;border:none;border-radius:10px;cursor:pointer;'>View on Google Maps</button></a><br>";
    } else {
        html += "Waiting for GPS coordinates fix...<br>";
    }
    html += "Satellites: " + String(_gps.satellites()) + "</div>";
// --- End ---
    html += "</body></html>";
    return html;
}
