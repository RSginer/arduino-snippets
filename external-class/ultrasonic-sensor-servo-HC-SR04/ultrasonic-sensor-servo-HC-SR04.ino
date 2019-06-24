#include "DistanceSensor.h"
#include <Servo.h>

int PINSERVO = 2;
int PULSOMIN = 500;
int PULSOMAX = 2200;

// Ultrasonic sensor TRIG = 10, ECO = 9
int TRIG = 10;
int ECO = 9;

DistanceSensor distanceSensor(TRIG, ECO);

// Servo
Servo servo;

void setup()
{
  distanceSensor.init();

  servo.attach(PINSERVO, PULSOMIN, PULSOMAX);

  Serial.begin(9600);
}

void loop()
{ 
  int DISTANCE = distanceSensor.getDistance();
  
  Serial.println(DISTANCE);

  delay(200);

  if (DISTANCE < 50) {
    moveServo();
   }
}

void moveServo() {
   servo.write(0);
   delay(350);
   servo.write(180);
   delay(350);
}
