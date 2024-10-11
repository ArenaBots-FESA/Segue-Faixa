#include <Arduino.h>

#define IN1 13
#define IN2 12
#define IN3 11
#define IN4 10
#define ENA 9
#define ENB 5

//Entradas do Arduino.
int S[] = {A1, A0, A2};
bool leitura[5];

//constantes
int Vrap = 90, Vlento = 90;
int ValorPreto = 500;//abaixo desse valor ele considera branco, que seria 1



void ConfigPlaca()//Método responsável pelas configurações iniciais.
{
//Declarando/Definindo as Saídas

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
 
//Declarando/Definindo as Entradas
  for(int j=0; j<3; j++)
  {
  pinMode(S[j], INPUT);
  }
//Limpeza das saídas por questão de segurança.

  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  digitalWrite(ENA,0);
  digitalWrite(ENB,0);
}

void ControlePonteH()//método para o controle da Ponte H, permitindo a rotina dos
//motores em relação ao funcionamento.
{
 for(int i = 0; i<3; i++)
 {
  if(analogRead(S[i])>500)//caso sensor leia preto
  {
    leitura[i]=0;
  }
  else if(analogRead(S[i]<=500)){
    leitura[i]=1;
  };
 }


  
 if(leitura[0]== 0 && leitura[2]== 0)//ambos os sensores na pista//ambos lendo preto
 {  
  digitalWrite(IN1,0);// motor 1 frente;
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);//motor 2 frente;
  digitalWrite(IN4,1);
  analogWrite(ENA, Vrap);
  analogWrite(ENB, Vrap);
 }
 if(leitura[0] == 1 && leitura[2] == 0)// SA na FAIXA
 {
  digitalWrite(IN1,0);// motor corrige esquerda;
  digitalWrite(IN2,1);
  digitalWrite(IN3,1);//motor corrige esquerda;
  digitalWrite(IN4,0);
  analogWrite(ENA, Vlento);
  analogWrite(ENB, Vlento);
 }
 if(leitura[0] == 0 && leitura[2] == 1)//SB na FAIXA
 {
  digitalWrite(IN1,1);// motor corrige direita;
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);//motor corrige direita;
  digitalWrite(IN4,1);
  
  analogWrite(ENA, Vlento);
  analogWrite(ENB, Vlento);
 }
 
 if(leitura[0] == 1 && leitura[2] == 1)// SA e SB Faixa
 {
  analogWrite(ENA, Vlento);
  analogWrite(ENB, Vlento);
 }
 
}

void setup()// só será executada uma vez
{
  ConfigPlaca(); //Chamada do método “ConfigPlaca” responsável pela configuração
  //das entradas e saídas
}

void loop()// executada infinitamente
{
  ControlePonteH(); //Chamada do método “ControlePonteH” responsável pela rotina
  //do funcionamento do programa.
}
