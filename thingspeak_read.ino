#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
 
 
const char* ssid     = "Dev";
const char* password = "87654321";

unsigned long myChannelNumber = 518154;
const char * myReadAPIKey = "8E4YHZ98YA8VODNL";

 
WiFiClient WiFiclient;

void setup(){
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(WiFiclient);
}
 
void loop(){
  String temp;
  String humidity;
  temp = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);
  Serial.println("Temperature= " + temp + "*C");
  humidity = ThingSpeak.readFloatField(myChannelNumber, 2, myReadAPIKey);
  Serial.println("Humidity= " + humidity + "%");
  delay(5000);
}
