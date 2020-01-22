#include "dht.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
 
const char* ssid     = "Dev";
const char* password = "aaaaaaaa";
unsigned long myChannelNumber = 581362;
const char * myWriteAPIKey = "IE51C8R28948DT3V";
 
WiFiClient WiFiclient;
dht DHT;

void setup() {
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
 
void loop() {
  DHT.read11(D2);
  String temp = (String)DHT.temperature;
  String humidity = (String)DHT.humidity; 
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(17000);
}

