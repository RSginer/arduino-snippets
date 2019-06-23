#include <Servo.h>

Servo servo;

int PINSERVO = 2;
int PULSOMIN = 500;
int PULSOMAX = 2400;

void setup()
{
   servo.attach(PINSERVO, PULSOMIN, PULSOMAX);
}

void loop()
{
   servo.write(0);
   delay(2000);
   servo.write(180);
   delay(2000);
}
