#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
 
 
const char* ssid     = "Dev";
const char* password = "87654321";

unsigned long myChannelNumber = 957916;
const char * myReadAPIKey = "30YY1MYOXEF5M45Y";

 
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
  int var;
  var = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);
  Serial.println("Variable= " + var);
  delay(5000);
}
