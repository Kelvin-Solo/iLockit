/*extern "C"{
#include"pins_arduino.h"
#include"lcd.h"
//#include"myutils.h"
};
*/

#include<LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


/*const int trigPin = 0;
const int echoPin = 1;

long pulseDuration;
int distance;
char depth[5];
*/
void setup() {
/*  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
*/  //InitLCD(LS_BLINK|LS_ULINE);
  lcd.begin(16, 2);
}

void loop() {
  lcd.print("iLockIt");
  delay(2000);
  lcd.clear();
  
  // Clears the trigPin
  //digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  //digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  //pulseDuration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  //distance= pulseDuration*0.034/2;
  //itoa(distance, depth, 10);
  // Prints the distance on LCD
  //LCDWriteStringXY(0,0,"Distance: ");
  
  lcd.setCursor(0,0);
  lcd.print("Distance: ");

  lcd.setCursor(0,11);
  lcd.print("depth");
}
