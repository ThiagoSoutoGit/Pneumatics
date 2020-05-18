/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/


// include the library code:
#include "Ultrasonic.h"
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensorvoid setup()

const int echoPin2 = 8; // Echo Pin of Ultrasonic Sensor
const int pingPin2 = 9; // Trigger Pin of Ultrasonic Sensorvoid setup()

int led13 = 13;
int led10 = 10;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  pinMode(led13, OUTPUT);
  pinMode(led10, OUTPUT);
  
  pinMode(pingPin, OUTPUT); // initialising pin 7 as output
  pinMode(echoPin, INPUT); // initialising pin 6 as input
  pinMode(pingPin2, OUTPUT); // initialising pin 9 as output
  pinMode(echoPin2, INPUT); // initialising pin 8 as input
}

void loop() {
  long duration, duration2, cm, cm2;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration); // calling

  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  cm2 = microsecondsToCentimeters(duration2); // calling


  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("UT cm: ");
  lcd.print(cm);
  lcd.setCursor(0, 1);
  lcd.print("UT cm2: ");
  lcd.print(cm2);
  

  if (cm < 20) {
    digitalWrite(led13, HIGH); // Turn the LED on
    delay(1000);
    digitalWrite(led13, LOW);
    delay(2000);
  } else {
     digitalWrite(led13, LOW); // Turn the LED off
  }

  if (cm2 < 6) {
    digitalWrite(led10, HIGH); // Turn the LED on
    delay(1000);
    digitalWrite(led10, LOW);
    delay(1000);
  } else {
     digitalWrite(led10, LOW); // Turn the LED off
  }

  delay(100);
  
}

long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
return microseconds / 29 / 2;
}
