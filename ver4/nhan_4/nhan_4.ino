#include <SoftwareSerial.h>
SoftwareSerial mySerial(4,5); // RX, TX

#define M0 6
#define M1 7
 
void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600); 
  pinMode(M1, OUTPUT);
  pinMode(M0, OUTPUT);
  normal();
}

void normal()
{
  digitalWrite(M0, 0);
  digitalWrite(M1, 0);
}

void loop() 
{
//   while (Serial.available()) {
//      char com = Serial.read(); 
//      mySerial.print(com);            
//  }
  while (mySerial.available()) {
   char  com_ao = mySerial.read();    
      Serial.print(com_ao);       
   }
   
}

