#define M0 4
//#define M1 5
void setup()  
{
  Serial.begin(9600);
  pinMode(M0, OUTPUT);
//pinMode(M1, OUTPUT);
  sleep();
  char ADR[6] = {0XC0,0X00,0X02,0X1A,0X02,0XC4}; // IN DIA CHI 2, KENH 2 VAO LORA-- M0&M1=1
  for(int i=0;i<=6;i++)
  {
    Serial.print(ADR[i]);
  }
  normal();
}
//----------------------------------------------
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
//----------------------------------------------
void loop() 
{
   while (Serial.available()) {
     char inChar1 = Serial.read();    
      Serial.print(inChar1);
      //delay(100);
      
   }
//   Serial.print("012345 ");
//   delay(1000);
}

