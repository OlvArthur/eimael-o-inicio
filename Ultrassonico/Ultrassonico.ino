 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5


int objeto = 0;
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  pinMode(7, INPUT); //Pino ligado ao coletor do fototransistor 
  Serial.println("Lendo dados dos sensores...");
}
 
void loop()
{
  objeto = digitalRead(7);
  if(objeto == 0)
  {  
    Serial.println("Objeto : Ta pegando fogo bicho");  
  }  
  
  else  
  {  
    Serial.println("Objeto : Ta frio !");  
  }
  delay(100);
    
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(100);
}
