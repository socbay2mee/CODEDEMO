#include <EEPROM.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5); // RX, TX

#define M0 6
#define M1 7
int addr = 0;
int latchPin = 10;
//chân SH_CP của 74HC595
int clockPin = 12;
//Chân DS của 74HC595
int dataPin = 11;
String inString = "";
//mảng có 10 số (từ 0-9) và 
const byte Seg[10] = {
  0b11000000,//0 - các thanh từ a-f sáng
  0b11111001,//1 - chỉ có 2 thanh b,c sáng
  0b10100100,//2
  0b10110000,//3
  0b10011001,//4
  0b10010010,//5
  0b10000010,//6
  0b11111000,//7
  0b10000000,//8
  0b10010000,//9
};
long x;
char a;
void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600); 
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M0, OUTPUT);
  normal();
  
}

void HIENTHI_LED7DOAN(unsigned long Giatri, byte SoLed) {
  
  byte *array= new byte[SoLed];
  for (byte i = 0; i < SoLed; i++) {
    //Lấy các chữ số từ phải quá trái
    array[i] = (byte)(Giatri % 10UL);
    Giatri = (unsigned long)(Giatri /10UL);
  }
  digitalWrite(latchPin, LOW);
  for (int i = SoLed - 1; i >= 0; i--)
    shiftOut(dataPin, clockPin, MSBFIRST, Seg[array[i]]); 
  
  digitalWrite(latchPin, HIGH);
  free(array);
}

void normal()
{
  digitalWrite(M0, 0);
  digitalWrite(M1, 0);
}

void loop() 
{
 
  while(mySerial.available()) {
    x = mySerial.parseInt(); //This is your Integer value
    Serial.print(x);
  }
  HIENTHI_LED7DOAN(x, 3);  
  delay(1000);
}

