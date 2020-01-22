#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
 
const char* ssid     = "nodemcu";
const char* password = "12345678";
unsigned long myChannelNumber = 957916;
const char * myWriteAPIKey = "J9Q9B1G1ZEJ6M6TC";
 
WiFiClient WiFiclient;

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
  for(int i=0;i<10;i++)
  {
  ThingSpeak.setField(1,i);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(17000);
  }
}
