int incomingByte = 0;   // for incoming serial da
byte Bytes[4] ;


void setup() {
        Serial.begin(9600);// opens serial port, sets data rate to 9600 bps
        pinMode(13, OUTPUT);
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:

                Serial.readBytes(Bytes,4);
                int pin = Bytes[2];  
                int val;             

                // say what you got:
                //Serial.print("I received: ");
                //Serial.print(Bytes[0]);
                //Serial.print(Bytes[1]);
                //Serial.print(Bytes[2]);
                //Serial.println(Bytes[3]);
                if (Bytes[0] == 2){
                  switch(Bytes[1]){
                    case 0: //read bit
                    val = digitalRead(pin);
                    if(val == HIGH){
                      Bytes[3] = 1;
                      }
                    if(val == LOW){
                      Bytes[3] = 0;
                      }
                    Serial.write(Bytes,4);
                    break;
                    case 2:
                    val = Bytes[3]; 
                    if(val == 0){ // 
                      digitalWrite(pin, LOW);                      
                      } 
                    else if(val == 1){ // write bits
                      digitalWrite(pin, HIGH);                      
                      } 
                    break;
                    }
                  }
        }
}
