void setup()  
{
  Serial.begin(9600);
}
void loop() 
{
//   while (Serial.available()) {
//     char inChar1 = Serial.read(); 
//     Serial.print(inChar1);   
//   }
 
    char a[6] = {0XC0,0X00,0X04,0X1A,0X02,0XC4}; // IN DIA CHI, KENH VAO LORA-- M0&M1=1
    for(int i=0;i<=6;i++)
    {
      Serial.print(a[i]);
    }     
     delay(1000);
        
 
}
// set tran: 00 01 01
