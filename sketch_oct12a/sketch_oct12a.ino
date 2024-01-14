int pirSensor  = D6;
//int realyInput = 7;

void setup() 
{
pinMode(pirSensor,INPUT);
pinMode(LED_BUILTIN,OUTPUT);
}
 
void loop()
{
int sensorValue = digitalRead(pirSensor);

if (sensorValue == 1)
{
digitalWrite(LED_BUILTIN, LOW);
}else 
{
  digitalWrite(LED_BUILTIN, HIGH);
 }
}
