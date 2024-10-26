#include"sMQTTBroker.h"

sMQTTBroker broker;

IPAddress local_IP(192, 168, 75, 218); //Defina o IP de acordo com a sua rede
IPAddress gateway(192, 168, 75, 254);
IPAddress subnet(255, 255, 0, 0);

void setup()
{
 Serial.begin(9600);

 if (!WiFi.config(local_IP, gateway, subnet)) {
   Serial.println("STA Failed to configure");
 }

const char* ssid = "Galaxy A22 41FF";         // The SSID (name) of the Wi-Fi network you want to connect
const char* password = "123123123"; // The password of the Wi-Fi network
 
WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
   delay(1000);
 }
 Serial.println("Connection established!");
 Serial.print("IP address:\t");
 Serial.println(WiFi.localIP());

 const unsigned short mqttPort = 1883;
 broker.init(mqttPort);
 // all done
}
void loop()
{
 broker.update();
}
