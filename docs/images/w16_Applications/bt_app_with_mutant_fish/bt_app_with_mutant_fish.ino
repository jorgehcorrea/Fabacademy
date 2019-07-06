#include <SoftwareSerial.h>

SoftwareSerial BT(PD0, PD1); // RX, TX  BLUE

char dato;
void setup() 

{
    pinMode(A0, OUTPUT);
    digitalWrite(A0, LOW);
    BT.begin(9600); //VELOCIDAD DE COMUNICACION  
   pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  delay(5000);
 
}

void loop() 
{
  if (BT.available())
  {
    dato=BT.read();
    BT.print(dato);
  }
  
  if(dato=='1')
  {
    digitalWrite(A0,HIGH);
  }

  if(dato=='0')
  {
    digitalWrite(A0,LOW);
  }
} 