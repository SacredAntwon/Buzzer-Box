/*
Music Distance Box (With RGB LED)
Made By: SacredAntwon
Purpose: This is a instrument that plays the buzzer at 
different frequencies and flashes the LED at differend speeds
depending on the distance of an object in front of the range
finder. 

Pin Setup:
VL53L0X Pin    Arduino Pin
 VCC            5V
 GND            GND
 SDA            A4 or SDA if Available
 SCL            A5 or SCL if Available
 GPIO1          Leave it Unconnected
 XSHUT          D12 (digital 12 or pin 12)

LED Pin        Arduino Pin
 LED Red Pin    D7
 LED Green Pin  D8
 LED Blue Pin   D9
 Ground Pin     GND

Buzzer Pin     Arduino Pin
 Positive       D5
 Negative       GND
*/

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

const int redPin = 7;
const int greenPin = 8;
const int bluePin = 9;

const int buzzerPin = 5;

const int toneDelay = 80;

int ledState = LOW;
int oppLedState = HIGH;

unsigned long previousMillis = 0;
void setup()
{
  pinMode(12,INPUT_PULLUP);
  digitalWrite(12,HIGH);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  for(int b=0; b < 4; b++)
  {
    digitalWrite(greenPin, HIGH);
    delay(300);
    digitalWrite(greenPin, LOW);
    delay(300);
  }

  digitalWrite(greenPin, HIGH);
  delay(800);
  digitalWrite(greenPin, LOW);
}

void loop()
{
  // Grab distance from sensor
  int distance =sensor.readRangeContinuousMillimeters();
  
  //FIRST DISTANCE
  if(distance < 50)
  {
     ledLoop(100);
     tone(buzzerPin, 1600);
     delay(toneDelay);
     noTone(buzzerPin);
     delay(toneDelay);
  }

  //SECOND DISTANCE
  else if(distance < 100)
  {
    ledLoop(200);
    tone(buzzerPin, 1450);
    delay(toneDelay);
    noTone(buzzerPin);
    delay(toneDelay);
  }

  //THIRD DISTANCE
  else if(distance < 150)
  {
    ledLoop(300);
    tone(buzzerPin, 1300);
    delay(toneDelay);
    noTone(buzzerPin);
    delay(toneDelay);
  }

  //FOURTH DISTANCE
  else if(distance < 200)
  {
    ledLoop(400);
    tone(buzzerPin, 1150);
    delay(toneDelay);
    noTone(buzzerPin);
    delay(toneDelay);
  }

  //FIFTH DISTANCE
  else if(distance < 250)
  {
    ledLoop(500);
    tone(buzzerPin, 1000);
    delay(toneDelay);
    noTone(buzzerPin);
    delay(toneDelay);
  }

  //SIXTH DISTANCE
  else if(distance < 300)
  {
    ledLoop(600);
    tone(buzzerPin, 850);
    delay(toneDelay);
    noTone(buzzerPin);
    delay(toneDelay);
  }

  //SEVENTH DISTANCE
  else if(distance < 350)
  {
    ledLoop(700);
    tone(buzzerPin, 700);
    delay(toneDelay);
    noTone(buzzerPin);
    delay(toneDelay);
  }
  
  else if(distance >= 350)
  {
     ledLoop(1000);
  }
}

int ledLoop(int tick)
{
  unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= tick) 
    {
      previousMillis = currentMillis;

      if (ledState == LOW) 
      {
        ledState = HIGH;
        oppLedState = LOW;
      } 
      else 
      {
        ledState = LOW;
        oppLedState = HIGH;
      }

     digitalWrite(bluePin, ledState);
     digitalWrite(redPin, oppLedState);
    } 
}
