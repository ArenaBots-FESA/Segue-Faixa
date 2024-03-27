#define sensor A2
int leitura = 0;
void setup() {
  Serial.begin(9600); // Setup the Serial to a speed of 9600bps
}

void loop() {
  // Print the sensors values
  Serial.print("Leituras: ");
  leitura = analogRead(sensor);
  Serial.println(leitura);
  delay(100);
  Serial.println("\n");
}
