
int count = 0;
int vong =0;
int chieudai=0;
void pulse()
{
    if(digitalRead(4) == LOW)
      count++;
    else
      count--;
    if(count==3600)
    {
      vong++;
      chieudai=vong*20;
      count=0;
    }
    
}

void setup()
{
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP); 
    pinMode(4, INPUT_PULLUP); 
    attachInterrupt(0, pulse, FALLING); //Ngắt cạnh xuống
}

void loop()
{
    Serial.println(count);
    Serial.println(vong);
    Serial.print("Chieu dai= ");
    Serial.println(chieudai);
}   
