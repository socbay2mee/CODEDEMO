#define M0 4
void setup()  
{
  Serial.begin(9600);
  pinMode(M0, OUTPUT);
  sleep();
  char ADR[6] = {0XC0,0X00,0X01,0X1A,0X01,0XC4}; // IN DIA CHI 1, KENH 1 VAO LORA-- M0&M1=1
   for(int i=0;i<=6;i++)
   {
      Serial.print(ADR[i]);
   }
   normal();
}
//-------------------------------------------------------------------
void normal()
{
  digitalWrite(M0, 0);
}
void sleep()
{
  digitalWrite(M0, 1);
}
//------------------------------------------------------------------
void loop() 
{
//   while (Serial.available()) {
//     char inChar1 = Serial.read(); 
//     Serial.print(inChar1);   
//   }

    char a[4] = {0X00,0X02,0X02,0X41};
    for(int i=0;i<=4;i++)
    {
      Serial.print(a[i]);
    }   
     Serial.print("bbbbb");    
     delay(1000);
}

