int CHIEU_DAI=0;
int DEM=0;
int BAO_GAO=20;
int XUNG=0;
boolean START=false;
void ENCODER()
{
 if(START==true) // bắt đầu tính chiều dài
 {  
    if(digitalRead(4) == LOW)
      XUNG++;
    else
      XUNG--;
      
    CHIEU_DAI=XUNG*0.01;
    
    if(digitalRead(3) == LOW) // phát hiện cạnh xuống không cho tính chiều dài
    {
      XUNG=0;
      BAO_GAO=20;
      START=false ;  
      CHIEU_DAI=0;
    }
    if(CHIEU_DAI == BAO_GAO + 10 )  // chiều dài quá 1,5 bao => tính 2 bao
    {
      DEM=DEM+1;
      BAO_GAO=BAO_GAO+20;
    }
 } 
  
}
void PHAT_HIEN()
{
  DEM=DEM+1;
  START=true;
}

void setup()
{
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT);
    pinMode(4, INPUT_PULLUP); 
    attachInterrupt(0, ENCODER, FALLING); //Ngắt cạnh xuống
    attachInterrupt(1, PHAT_HIEN, RISING); //Ngắt cạnh LEN
}

void loop()
{   Serial.print("San pham=");
    Serial.println(DEM);
    Serial.print("Xung=");
    Serial.println(XUNG);
    Serial.print("Vong=");
   // Serial.println(vong);
    Serial.print("Chieu dai= ");
    Serial.println(CHIEU_DAI);
    Serial.println("-----------------------");
    delay(1000);
        if(digitalRead(3) == LOW)
    {
      XUNG=0;
      BAO_GAO=20;
      START=false ;  
      CHIEU_DAI=0;
    }
}   
