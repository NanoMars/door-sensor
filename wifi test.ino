#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include <ESP_Google_Sheet_Client.h>

#include <GS_SDHelper.h>
#include <FirebaseJson.h>

#define WIFI_SSID ""
#define WIFI_PASSWORD ""

#define PROJECT_ID ""
#define CLIENT_EMAIL ""
const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----\b\n-----END PRIVATE KEY-----\n";
const char spreadsheetId[] = "";

// Token Callback function
void tokenStatusCallback(TokenInfo info);

// NTP server to request epoch time
//const char* ntpServer = "pool.ntp.org";

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


    GSheet.printf("ESP Google Sheet Client v%s\n\n", ESP_GOOGLE_SHEET_CLIENT_VERSION);

    // Set the callback for Google API access token generation status (for debug only)
    GSheet.setTokenCallback(tokenStatusCallback);

    // Set the seconds to refresh the auth token before expire (60 to 3540, default is 300 seconds)
    GSheet.setPrerefreshSeconds(10 * 60);

    // Begin the access token generation for Google API authentication
    GSheet.begin(CLIENT_EMAIL, PROJECT_ID, PRIVATE_KEY);
}


void loop(){

}