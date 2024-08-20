#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include <ESP_Google_Sheet_Client.h>


#define WIFI_SSID "Armand's_Wifi"
#define WIFI_PASSWORD "littleFish"

void setup() {
    Serial.begin(115200);
    WiFi.setAutoReconnect(true);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(1000);
    }
    
    Serial.println();
    Serial.print("Connected with IP: ");
    
    Serial.println(WiFi.localIP());
    Serial.println();
}


void loop(){

}