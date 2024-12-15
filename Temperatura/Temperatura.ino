const int termistorPin = A0;    
const int ledPin = 9;           
const float referenceResistance = 10000.0;  // Resistor usado para o divisor de tensão (10K)
const float BETA = 3950;  // Constante beta para o termistor NTC (ajuste de acordo com o modelo)

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Leitura analógica do termistor
  int analogValue = analogRead(termistorPin);

  // Conversão para resistência
  float resistance = referenceResistance * (1023.0 / analogValue - 1.0);

  // Cálculo da temperatura em Celsius
  float celcius = 1.0 / (log(resistance / referenceResistance) / BETA + 1.0 / 298.15) - 273.15;

  Serial.print("Temperatura: ");
  Serial.print(celcius);
  Serial.println(" °C");

  if (celcius >= 30.0) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }

  delay(1000);
}