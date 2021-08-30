#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#define RELAY 5
//slave
const char* ssid = "GG";
const char* password = "LANCE001";

uint32_t chipId = 0;

WiFiServer server(80); 

void open() {
  digitalWrite(RELAY, HIGH);
  delay(1000);
  digitalWrite(RELAY, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
  chipId = ESP.getChipId();
  WiFi.softAP(ssid, password);
  Serial.print("!!!");
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  Serial.print(".");
  delay(500);
  if (client) {
    // delay();
    client.println(String(chipId));
    client.stop();
    open();
  }
}