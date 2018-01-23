//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger1 4
#define pino_echo1 5
#define pino_trigger2 6
#define pino_echo2 7
#define sensorPin1 8
#define sensorPin2 9
#define sensorPin3 10
float limiar_sonic=20.0;
int limiar_linha=850;
float cmMsec;
long microsec;
float estado;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin1,INPUT);
  pinMode(sensorPin2,INPUT);
  pinMode(sensorPin3,INPUT);
}

void loop(){
sonic_frente();
sonic_tras();
detecta_linha_frenteE();
detecta_linha_frenteD();
detecta_linha_tras();
}





bool sonic_frente()
{
  microsec = ultrasonic1.timing();
  cmMsec = ultrasonic1.convert(microsec, Ultrasonic::CM);
  if(cmMsec<limiar_sonic){
    return true;
    }
  else{
    return false;
    }
}
bool sonic_tras()
{
  microsec = ultrasonic2.timing();
  cmMsec = ultrasonic2.convert(microsec, Ultrasonic::CM);
  if(cmMsec<limiar_sonic){
    return true;
    }
  else{
    return false;
    }
}
bool detecta_linha_frenteE()
{
  estado=analogRead(sensorPin1);
  if(estado>limiar_linha){
    return true;
  }
  else{
    return false;
    }
}
bool detecta_linha_frenteD()
{
  estado=analogRead(sensorPin2);
  if(estado>limiar_linha){
    return true;
  }
  else{
    return false;
    }
}
bool detecta_linha_tras()
{
  estado=analogRead(sensorPin3);
  if(estado>limiar_linha){
    return true;
  }
  else{
    return false;
    }
}
