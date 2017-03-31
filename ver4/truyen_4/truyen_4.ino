#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // RX, TX

#define M0 4
#define M1 5

String inString = "";
int gia_tri_set=0;
char com_ao;
void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600); 
  
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  normal();
}

void normal()
{
  digitalWrite(M0, 0);
  digitalWrite(M1, 0);
}

void loop() 
{
//   while (mySerial.available()) {
//     com_ao = mySerial.read();
//   }
  for(int i=0; i<=100;i++)
  {
    mySerial.println(i);
    Serial.print(i);
    delay(1000);
  }
}

