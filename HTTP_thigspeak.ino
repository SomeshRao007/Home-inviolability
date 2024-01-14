#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#define ldrPin A0          // Analog Pin connected to LDR

char ssid[] = "xxxxxxx";   // your network SSID (name) 
char pass[] = "xxxxxxx";   // your network password
 
WiFiClient  client;

unsigned long myChannelNumber = xxxxxx;           // Write your Channel ID
const char * myWriteAPIKey = "xxxxxxxxxxxxxxxx";   // Write your API Write Key

int value = 0;            //Variable to store value

void setup() {
  Serial.begin(9600);  // Initialize serial
  pinMode(ldrPin,INPUT);
  WiFi.mode(WIFI_STA);  //Start WiFi in Station Mode
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Connecting");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
  int x = ThingSpeak.writeField(myChannelNumber, 1, value, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  // change the value
  value = analogRead(ldrPin);
  
  delay(15000); // Wait 15 seconds to update the channel again
}
