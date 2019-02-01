#ifndef BroBots_Motor_Driver_h
#define BroBots_Motor_Driver_h

#include "Arduino.h"

class BroBots_Motor_Driver
{
public:
  BroBots_Motor_Driver(int ENA, int ENB, int INPins[4]);
  void begin();
  void spinForward(int motorSpeed);
  void spinBackwards(int motorSpeed);
  void spinLeft(int motorSpeed);
  void turnLeft(int motorSpeed, int multiplier);
  void spinRight(int motorSpeed);
  void turnRight(int motorSpeed, int multiplier);
  void stopMotors();

private:
  int _ena;
  int _enb;
  int _motors[4];
};

#endif
