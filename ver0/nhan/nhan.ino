void setup()  
{
  Serial.begin(9600);
}

void loop() 
{
   while (Serial.available()) {
     char inChar1 = Serial.read(); 
     Serial.print(inChar1);   
   }
}

