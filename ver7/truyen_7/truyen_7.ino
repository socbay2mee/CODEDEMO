#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // RX, TX

#define M0 4
#define M1 5
char so_dem,so_set;

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
  while (mySerial.available()) {  // nhận số đếm từ lora hiển thị C#
      so_dem = mySerial.read();
      Serial.print(so_dem);    
  }
  
   while (Serial.available()) {  // gửi số từ C# qua lora
      so_set = Serial.read();
      mySerial.print(so_set);
     
  }
}

