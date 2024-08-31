#define S1 A1
#define S2 A2
#define S3 A3

bool Leitura1 = 0;
bool Leitura2 = 0;
bool Leitura3 = 0;

void setup() {
  Serial.begin(9600); // Setup the Serial to a speed of 9600bps
  
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);   
  pinMode(S3, INPUT);
}

void loop() {
  // Print the sensors values

  if(analogRead(S1) <= 500){
    Leitura1 = 1; //1 = BRANCO (LINHA)
  }
  else{
    Leitura1 = 0;//0 = PRETO (FORA DA LINHA)
    }

  if(analogRead(S2) <= 500){
    Leitura2 = 1;    
  }
  else{
    Leitura2 = 0;
    }

  if(analogRead(S3) <= 500){
    Leitura3 = 1;    
  }
  else{
    Leitura3 = 0;
    }

  Serial.println(Leitura1);
  Serial.println("        ");
  Serial.println(Leitura2);
  Serial.println("        ");
  Serial.println(Leitura3);
  delay(500);
}