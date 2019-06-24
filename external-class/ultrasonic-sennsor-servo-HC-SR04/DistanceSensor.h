#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <Arduino.h>

class DistanceSensor
{
protected:
  int TRIG;
  int ECO;
  int DISTANCE;
  int DURATION;

public:
  DistanceSensor(int trig, int eco)
  {
    TRIG = trig;
    ECO = eco;
  }

  void init()
  {
    pinMode(TRIG, OUTPUT);
    pinMode(ECO, INPUT);
  }

  int getDistance()
  {
    digitalWrite(TRIG, HIGH);
    delay(1);
    digitalWrite(TRIG, LOW);
    DURATION = pulseIn(ECO, HIGH);
    DISTANCE = DURATION / 58.2;
    return DISTANCE;
  }
};

#endif
