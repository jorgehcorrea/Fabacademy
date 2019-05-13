#include <SoftwareSerial.h>
   #define RxD 1
   #define TxD 2
   #define DEBUG_ENABLED  1
   SoftwareSerial blueToothSerial(RxD,TxD);
   int state = 0;
   int led = 3;  // LED1 Pin
   void setup() {
       pinMode(led, OUTPUT);
     blueToothSerial.begin(9600);
   }
   void loop()
   {
   if(blueToothSerial.available() > 0){
    state = blueToothSerial.read();
   if(state == 1)
   {
     digitalWrite(led,HIGH);
     blueToothSerial.write("LED ON");
        }
   else if(state ==0)
   {
      digitalWrite(led,LOW);
     blueToothSerial.write("LED OFF");
   }
   }
