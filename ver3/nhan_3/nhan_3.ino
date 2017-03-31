#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // RX, TX

#define M0 4
void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600); 
  
  pinMode(M0, OUTPUT);
  sleep();
  char ADR[6] = {0XC0,0X00,0X02,0X1A,0X02,0XC4}; // IN DIA CHI 2, KENH 2 VAO LORA-- M0&M1=1
  for(int i=0;i<=6;i++)
  {
    mySerial.print(ADR[i]);
  }
  normal();
}

void normal()
{
  digitalWrite(M0, 0);
}
void sleep()
{
  digitalWrite(M0, 1);
}

void loop() 
{
  // char inChar1;
   //while (mySerial.available()) {
      // inChar1 = mySerial.read();             
  // }
   while (mySerial.available()) {
   char  inChar1 = mySerial.read();    
      Serial.print(inChar1);      
   }
}

