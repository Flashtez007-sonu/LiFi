#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "shubham";
const char* pass = "123456789";

const int LED1=13;
 const int LDR1=0;
  int level;
  const int threshold=150;  

  char host[] = "api.thingspeak.com";
String ApiKey = "LAGXRZINWG4RT7GM";
String path = "/update?key=" + ApiKey + "&field1=";

void setup()
{
  pinMode (LED1,OUTPUT); 
  Serial.begin(9600);
  Serial.println(“”);
  Serial.print(“Connecting to “);
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) 
{
  delay(500);
  Serial.print(“.”); 
}
  Serial.println(“”);
  Serial.print(“Connected to “);
  Serial.println(ssid);
  Serial.print(“IP address: “);
  Serial.println(WiFi.localIP());

  pinMode(LDR_PIN, INPUT);

}
void loop()
{
 while(1)
{
  digitalWrite(LED1, HIGH);
  level= analogRead(LDR1);
  if (level < threshold){
  Serial.println("NO DATA");
}
  else
{ 
  Serial.println("DATA IN"); 
}
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
  Serial.println(“connection failed”);
  return;
}
  client.print(String(“GET “) + path + ldr_value + ” HTTP/1.1\r\n” +“Host: ” + host + “\r\n” +“Connection: keep-alive\r\n\r\n”);
  delay(200);
}
}

