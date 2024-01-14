#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <SimpleTimer.h>
 
 
 
char auth[] = "DyWieVh9EKgPbrDQAapbwWVFBJXN_Bqv";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ZONG MBB-E8231-6E63";
char pass[] = "electroniclinic";
 
SimpleTimer timer;
 
 
 
// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
  
}
 
int pir_s = D0; // pir sensor
int ir_s = D1;  // infrared sensor
 
 
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pir_s, INPUT_PULLUP); 
  pinMode(ir_s, INPUT); 
  timer.setInterval(1000L,sensorvalue1); 
 
}
 
void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer   
}
 
void sensorvalue1()
{
 
if(digitalRead(pir_s) == HIGH)
{
  Blynk.virtualWrite(V2,255 ); // turns on the led
  Blynk.virtualWrite(V4,"Intruder detected on PIR Sensor!!!" ); 
  Blynk.notify("Intruder detected on PIR Sensor!!!"); 
}
 
if(digitalRead(pir_s) == LOW)
{
  Blynk.virtualWrite(V2,0 ); //turns off the led
  Blynk.virtualWrite(V4,"PIR Normal" ); 
}
 
 
    if( digitalRead(ir_s) == LOW)
{
  Blynk.virtualWrite(V3,255 ); // turns on the led
  Blynk.virtualWrite(V4,"Intruder detected on IR Sensor!!!" );
  Blynk.notify("Intruder detected on IR Sensor!!!"); 
} 
 
 if( digitalRead(ir_s) == HIGH)
{
  Blynk.virtualWrite(V3,0 ); // turns off the led
 
}
 
 
}
