#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Dados da sua rede 

const char* ssid = "";
const char* password = "";
const char* mqtt_server = "192.168.0.8"; // IP do broker

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() { // Conectando-se a rede

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Liga o led caso o topico receba 1
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Desliga o led
  }

}

void reconnect() { // Essa função serve para fazer reconectar o subscriber 
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Cria um ID aleatorio para o cliente
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Conectando...
    if (client.connect(clientId.c_str())) {
      client.subscribe("outTopic");
      Serial.print("Conected!!!");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
