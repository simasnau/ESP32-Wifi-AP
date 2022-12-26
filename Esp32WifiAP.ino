#include "WiFi.h"

const char* ssid = "TEST_AP_1";
const char* password = "TEST_AP_1";

void WifiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Someone connected to AP successfully!");
}

void WifiStationDisConnected(WiFiEvent_t event, WiFiEventInfo_t info){
  Serial.println("Someone disconnected from AP successfully!");
}


void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_AP);
    WiFi.disconnect();
    delay(100);
    WiFi.softAP(ssid, password);
    if (strlen(ssid) < 8) {
      Serial.println("SSID is shorter than 8. Default will be used.");
    }

    if (strlen(password) < 8) {
      Serial.println("Password is shorter than 8. Default will be used.");
    }

    WiFi.onEvent(WifiStationConnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_AP_STACONNECTED);
    WiFi.onEvent(WifiStationDisConnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_AP_STADISCONNECTED);

    Serial.println("Setup done");

}


void loop()
{

}
