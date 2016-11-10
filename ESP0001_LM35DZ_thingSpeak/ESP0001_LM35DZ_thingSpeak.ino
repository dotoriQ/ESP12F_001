/*
 *  Reference :
 *  http://www.seeedstudio.com/recipe/377-esp8266-iot-energy-monitor.html
 */

#include <ESP8266WiFi.h>
#include "myprivate.h"			  // Api Key, AP name, Ap password define!!

const int pinLED = 2;              // Internal pin of ESP-12F (GPIO-02)

String apiKey = MY_APIKEY;         // your ThingSpeak API key
const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, HIGH);

  WiFi.begin(MY_AP, MY_AP_PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  int readValue = analogRead(A0);
  float temperature = (float) readValue * 100.0 / 1024.0;

  digitalWrite(pinLED, LOW);
  delay(100);
  digitalWrite(pinLED, HIGH);

  if (client.connect(server,80)) {
    String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(temperature);
           postStr += "\r\n\r\n";

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(postStr.length());
     client.print("\n\n");
     client.print(postStr);
  }
  client.stop();
  delay(16000);    // ThingSpeak needs minimum 15 sec delay between updates
}
