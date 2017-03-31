#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // RX, TX

#define M0 4
//#define M1 5
void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600); 
  
  pinMode(M0, OUTPUT);
 // pinMode(M1, OUTPUT);
  sleep();
  char ADR[6] = {0XC0,0X00,0X01,0X1A,0X01,0XC4}; // IN DIA CHI 1, KENH 1 VAO LORA-- M0&M1=1
   for(int i=0;i<=6;i++)
   {
      mySerial.print(ADR[i]);
   }
   normal();
}
//-------------------------------------------------------------------
void normal()
{
  digitalWrite(M0, 0);
  //digitalWrite(M1, 0);
}
void sleep()
{
  digitalWrite(M0, 1);
  //digitalWrite(M1, 1);
}
//------------------------------------------------------------------
void loop() 
{
//   while (Serial.available()) {
//     char inChar1 = Serial.read(); 
//     Serial.print(inChar1);   
//   }

    char a[3] = {0X00,0X02,0X02};
    //for(int j=0;j<=100;j++)
    //{
      for(int i=0;i<=3;i++)
      {
        mySerial.print(a[i]);
      }   
      mySerial.print("bbbba");
      Serial.print("bbbba");       
      delay(1000);
   // }         

}

