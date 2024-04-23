#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3
#define S5 A4

bool Leitura1 = 0;
bool Leitura2 = 0;
bool Leitura3 = 0;
bool Leitura4 = 0;
bool Leitura5 = 0;

void setup() {
  Serial.begin(9600); // Setup the Serial to a speed of 9600bps
  
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);   
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

void loop() {
  // Print the sensors values
  
  if(analogRead(S1) <= 699){
    Leitura1 = 1;    
  }
  else{
    Leitura1 = 0;
    }

  if(analogRead(S2) <= 699){
    Leitura2 = 1;    
  }
  else{
    Leitura2 = 0;
    }

  if(analogRead(S3) <= 699){
    Leitura3 = 1;    
  }
  else{
    Leitura3 = 0;
    }

  if(analogRead(S4) <= 699){
    Leitura4 = 1;    
  }
  else{
    Leitura4 = 0;
    }

  if(analogRead(S5) <= 699){
    Leitura5 = 1;    
  }
  else{
    Leitura5 = 0;
    }
    
  Serial.println(Leitura1);
  Serial.println("\n");
  Serial.println(Leitura2);
  Serial.println("\n");
  Serial.println(Leitura3);
  Serial.println("\n");
  Serial.println(Leitura4);
  Serial.println("\n");
  Serial.println(Leitura5);
  delay(100);
  Serial.println("\n");
}
