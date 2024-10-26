int vermelho = 10;
int amarelo = 9;
int verde = 8;
 
void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
}
 
void loop() {

  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);
 
  delay(2000);

  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);

  delay(5000);  

  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);

  delay(5000);
}