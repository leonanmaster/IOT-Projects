#include"sMQTTBroker.h"

sMQTTBroker broker;

IPAddress local_IP(xxx, xxx, xxx, xxx); //Defina o IP de acordo com a sua rede
IPAddress gateway(xxx, xxx, xxx, xxx);
IPAddress subnet(255, 255, 0, 0);

void setup()
{
 Serial.begin(9600);

 if (!WiFi.config(local_IP, gateway, subnet)) {
   Serial.println("STA Failed to configure");
 }

const char* ssid = ""; // O SSID (nome) da rede wifi que você quer conectar
const char* password = ""; // A senha da rede escolhida
 
WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) { // Espere a internet conectar
   delay(1000);
 }
 Serial.println("Connection established!");
 Serial.print("IP address:\t");
 Serial.println(WiFi.localIP());

 const unsigned short mqttPort = 1883;
 broker.init(mqttPort);
 // feito
}
void loop()
{
 broker.update();
}
