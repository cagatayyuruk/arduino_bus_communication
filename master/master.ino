/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //[node_id][function_id][data][parity]
  //[function_id] 0 read bits - 2 write bits 
  //node 1 led yak
  byte Bytes[]= {1,2,13,1};
  Serial.write(Bytes,4);
  delay(1000);
  //node 1 led söndür
  Bytes[3]= 0 ;
  Serial.write(Bytes,4);
  delay(1000);
  //node 2 led yak
  Bytes[0]=2;
  Bytes[3]=1;  
  Serial.write(Bytes,4);
  delay(1000);
  //node 2 led söndür
  Bytes[3] = 0;
  Serial.write(Bytes,4);
  delay(1000);  
}
