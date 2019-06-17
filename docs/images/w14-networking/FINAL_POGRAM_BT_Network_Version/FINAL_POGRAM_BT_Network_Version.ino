#include <CapacitiveSensor.h>
/*
 * Paul Badger 2008
 */
CapacitiveSensor   cs_4_2 = CapacitiveSensor(13,11);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop()                    
{
    //long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);

//smothing code
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = total1;
  // add the reading to the total:
  total = total + readings[readIndex];   //readIndex variable to imput
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits

  if (average > 50) 
  {
    Serial.print('R'); // ln solo para humanos
    
  } 
  else
  {
    Serial.print('O'); //
  }
    delay(10);                             // arbitrary delay to limit data to serial port 
}
