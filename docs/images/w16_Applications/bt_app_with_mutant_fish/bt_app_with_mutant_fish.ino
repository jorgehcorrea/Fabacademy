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
  BT.println("AT");
  delay(1000);
  BT.println("AT+ROLE=0");
  delay(1000);
  BT.println("AT+UART=9600");
  delay(1000);
  BT.println("AT+RESET");
  delay(1000);
  BT.begin(8600); 
 
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