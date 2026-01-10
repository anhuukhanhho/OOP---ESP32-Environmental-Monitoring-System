// file: header for WebServerUI class
#ifndef WEB_SERVER_UI_H
#define WEB_SERVER_UI_H
#include <WebServer.h>
#include "BME280.h"
#include "GPS.h"
#include "PMS7003.h"
// Web interface classes
// Handles HTTP routing and HTML generation
class WebServerUI {
public:
    WebServerUI(
        WebServer& server, BME280& bme,
        GPS& gps, PMS7003& pms
    );
    void begin(); // Register web routes
private:
    WebServer& _server; // HTTP server instance
    BME280& _bme; GPS& _gps; PMS7003& _pms;
    String generatePage(); // HTML page builder
    void handleRoot(); // Root URL handler
};
#endif
