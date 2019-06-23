#include <Servo.h>

Servo servo;

int PINSERVO = 2;
int PULSOMIN = 500;
int PULSOMAX = 2200;

// Ultrasonic sensor
int TRIG = 10;
int ECO = 9;
int LED = 2;

int DURATION;
int DISTANCE;


void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  servo.attach(PINSERVO, PULSOMIN, PULSOMAX);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURATION = pulseIn(ECO, HIGH);
  DISTANCE = DURATION / 58.2; // CONSTANT OF MY SENSOR
  Serial.println(DISTANCE);
  delay(200);

  if (DISTANCE < 50) {
    moveServo();
   }
}


void moveServo() {
   servo.write(0);
   delay(2000);
   servo.write(180);
   delay(2000);
}
