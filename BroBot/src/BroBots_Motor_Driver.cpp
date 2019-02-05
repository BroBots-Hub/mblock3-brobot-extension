#include "Arduino.h"
#include "BroBots_Motor_Driver.h"

BroBots_Motor_Driver::BroBots_Motor_Driver(int ENA, int ENB, int INPins[4])
{
  _ena = ENA;
  _enb = ENB;

  _motors[0] = INPins[0];
  _motors[1] = INPins[1];
  _motors[2] = INPins[2];
  _motors[3] = INPins[3];
}

void BroBots_Motor_Driver::begin()
{
  pinMode(_ena, OUTPUT);
  pinMode(_enb, OUTPUT);

  for (int i = 0; i < sizeof(_motors); i++)
  {
    pinMode(_motors[i], OUTPUT);
  }
}

void BroBots_Motor_Driver::spinForward(int motorSpeed)
{
  analogWrite(_ena, motorSpeed);
  analogWrite(_enb, motorSpeed);
  digitalWrite(_motors[0], LOW);
  digitalWrite(_motors[1], HIGH);
  digitalWrite(_motors[2], LOW);
  digitalWrite(_motors[3], HIGH);
}

void BroBots_Motor_Driver::spinBackwards(int motorSpeed)
{
  analogWrite(_ena, motorSpeed);
  analogWrite(_enb, motorSpeed);
  digitalWrite(_motors[0], HIGH);
  digitalWrite(_motors[1], LOW);
  digitalWrite(_motors[2], HIGH);
  digitalWrite(_motors[3], LOW);
}

void BroBots_Motor_Driver::spinLeft(int motorSpeed)
{
  analogWrite(_ena, motorSpeed);
  analogWrite(_enb, motorSpeed);
  digitalWrite(_motors[0], LOW);
  digitalWrite(_motors[1], HIGH);
  digitalWrite(_motors[2], HIGH);
  digitalWrite(_motors[3], LOW);
}

void BroBots_Motor_Driver::turnLeft(int motorSpeed, int multiplier)
{
  analogWrite(_ena, motorSpeed);
  analogWrite(_enb, motorSpeed * multiplier);
  digitalWrite(_motors[0], LOW);
  digitalWrite(_motors[1], HIGH);
  digitalWrite(_motors[2], LOW);
  digitalWrite(_motors[3], HIGH);
}

void BroBots_Motor_Driver::spinRight(int motorSpeed)
{
  analogWrite(_ena, motorSpeed);
  analogWrite(_enb, motorSpeed);
  digitalWrite(_motors[0], HIGH);
  digitalWrite(_motors[1], LOW);
  digitalWrite(_motors[2], LOW);
  digitalWrite(_motors[3], HIGH);
}

void BroBots_Motor_Driver::turnRight(int motorSpeed, int multiplier)
{
  analogWrite(_ena, motorSpeed * multiplier);
  analogWrite(_enb, motorSpeed);
  digitalWrite(_motors[0], LOW);
  digitalWrite(_motors[1], HIGH);
  digitalWrite(_motors[2], LOW);
  digitalWrite(_motors[3], HIGH);
}

void BroBots_Motor_Driver::stopMotors()
{
  analogWrite(_ena, 0);
  analogWrite(_enb, 0);
  digitalWrite(_motors[0], LOW);
  digitalWrite(_motors[1], LOW);
  digitalWrite(_motors[2], LOW);
  digitalWrite(_motors[3], LOW);
}
