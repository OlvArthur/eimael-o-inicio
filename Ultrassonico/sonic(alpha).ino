//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define sensorPin1 8
float limiar_sonic=20.0;
int limiar_linha=850;
float cmMsec;
long microsec;
float estado;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin1,INPUT);
}

void loop()
{
//  retorna_dist();
//  if(cmMsec<limiar_sonic){
//  Serial.print("Atacar em : ");
//  Serial.println(cmMsec);
//  delay(1000);
//  }
//  else{
//    Serial.println("Nada em 20cm");
//    delay(1000);
//    }
if(detecta_linha()){
Serial.println("linha");}
delay(100);

}





float retorna_dist()
{
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  return cmMsec;
}
bool detecta_linha()
{
  estado=analogRead(sensorPin1);
  if(estado>limiar_linha){
    return true;
  }
  else{
    return false;
    }
}
