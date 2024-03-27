/*
 *  Programa: Exemplo de uso do driver Ponte H L298N
 *  Autor: Gustavo Nery, Eletrogate. 
 *  Arduino 1.8.12
 */

// Iremos fazer uma classe para facilitar o uso da ponte H L298N na manipulação dos motores na função Setup e Loop.

class DCMotor {  
//Classe criada para conter todos os dados dos motores

//Definição de variáveis
  int spd = 255, pin1, pin2; //tipo inteiras, de 0 até 255

//parte aberta, todos no programa podem acessar
  public:  
  
    void Pinout(int in1, int in2){ // Pinout é o método para a declaração dos pinos que vão controlar o objeto motor
      pin1 = in1;
      pin2 = in2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      }   
    void Speed(int in1){ // Speed é o método que irá ser responsável por salvar a velocidade de atuação do motor
      spd = in1;
      }     
    void Forward(){ // Forward é o método para fazer o motor girar para frente
      analogWrite(pin1, spd);
      digitalWrite(pin2, LOW);
// IN1 = 1 e IN2 = 0, significa que o Motor girará para frente, nesse //caso como é spd no lugar de IN1 = 1, significa que ele girará com uma //certa velocidade para frente
      }   
    void Backward(){ // Backward é o método para fazer o motor girar para trás
      digitalWrite(pin1, LOW);
      analogWrite(pin2, spd);
// IN1 = 0 e IN2 = 1, significa que o Motor girará para trás, nesse caso //como é spd no lugar de IN2 = 1, significa que ele girará com uma certa //velocidade para trás

      }
    void Stop(){ // Stop é o metodo para fazer o motor ficar parado.
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
//IN1 = 0 e IN2 = 0, significa que o motor fica parado 
      }
   };

   DCMotor Motor1, Motor2; // Criação de dois objetos motores, já que usaremos dois motores, e eles já estão prontos para receber os comandos já configurados acima. 

//rotina padrão do sistema, só rodará 1 vez
void setup() {
// Seleciona os pinos que cada motor usará, como descrito na classe.
  Motor1.Pinout(5,6); 
  Motor2.Pinout(9,10); 
}

//rotina padrão do sistema, rodara infinitas vezes
void loop() {

// A velocidade do motor pode variar de 0 a 255, onde 255 é a velocidade //máxima, já que a variável para velocidade é uma variável inteira.

  Motor1.Speed(200); 
  Motor2.Speed(200);
  
  Motor1.Forward(); // Comando para o motor ir para frente
  Motor2.Forward();
  delay(1000);

  Motor1.Stop(); // Comando para o motor parar
  Motor2.Stop();
  delay(500);

  Motor1.Backward(); // Comando para o motor ir para trás
  Motor2.Backward();
  delay(1000);

  Motor1.Stop(); // Comando para o motor parar
  Motor2.Stop();
  delay(500);

}
