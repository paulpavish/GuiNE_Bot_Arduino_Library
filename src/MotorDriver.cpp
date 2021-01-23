/*
  //   Title : MotorDriver.cpp
  //   Version : 1.0.0
  //   Author : Paul Pavish
  //   Website : www.basicsexplained.com/creator
  //   YT Channel : https://www.youtube.com/channel/UCavN7aolUmBbfcKbDbydvMA
  //   LinkedIn : https://www.linkedin.com/in/paulpavish/
  //   Project_Url : https://github.com/paulpavish/MotorDriver_GuiNE_Bot
  //
  //   Kindly attribute to Author on any marvelous project you come up with using this piece of code.
  //   Also show your support at my Youtube Channel. Thankyou.
  //
  //   Note : This is a library file designed specifically for GuiN-E Bot Series (V 1.0).
  //
  //   This library can configure & control the GuiN-E Bot V1.0 base motors.
  //   This library can be used to control any dual h-bridge motor drivers like (L293D, L298N, etc.).
  //
  //  This library is purposefully constructed for easy future updation for upcoming GuiN-E Bot versions.
  //	
  //	Copyright (c) 2021 Paul Pavish.  All right reserved.

*/

#include "Arduino.h"
#include "MotorDriver.h"

MotorDriver::MotorDriver(byte EN1, byte IN1, byte IN2, byte IN3, byte IN4)
{
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  _en1 = EN1;
  _in1 = IN1;
  _in2 = IN2;
  _in3 = IN3;
  _in4 = IN4;
  MotorState = false;
}

MotorDriver::MotorDriver(byte EN1, byte IN1, byte IN2, byte IN3, byte IN4, byte EN2)
{
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN2, OUTPUT);
  _en1 = EN1;
  _in1 = IN1;
  _in2 = IN2;
  _in3 = IN3;
  _in4 = IN4;
  _en2 = EN2;
  MotorState = true;
}

void MotorDriver::forward(byte SpeedValue)
{
  analogWrite(_en1, SpeedValue);
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);
}

void MotorDriver::forward(byte LeftSpeedValue, byte RightSpeedValue)
{
  analogWrite(_en1, LeftSpeedValue);
  analogWrite(_en2, RightSpeedValue);
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);
}

void MotorDriver::reverse(byte SpeedValue)
{
  analogWrite(_en1, SpeedValue);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
}

void MotorDriver::reverse(byte LeftSpeedValue, byte RightSpeedValue)
{
  analogWrite(_en1, LeftSpeedValue);
  analogWrite(_en2, RightSpeedValue);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
}

void MotorDriver::halt(byte MinSpeedValue)
{
  analogWrite(_en1, MinSpeedValue);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW);
}

void MotorDriver::halt(byte LeftMinSpeedValue, byte RightMinSpeedValue)
{
  analogWrite(_en1, LeftMinSpeedValue);
  analogWrite(_en2, RightMinSpeedValue);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW);
}

void MotorDriver::turn_left(byte SpeedValue)
{
  analogWrite(_en1, SpeedValue);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);
}

void MotorDriver::turn_left(byte LeftSpeedValue, byte RightSpeedValue)
{
  analogWrite(_en1, LeftSpeedValue);
  analogWrite(_en2, RightSpeedValue);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);
}

void MotorDriver::turn_right(byte SpeedValue)
{
  analogWrite(_en1, SpeedValue);
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
}

void MotorDriver::turn_right(byte LeftSpeedValue, byte RightSpeedValue)
{
  analogWrite(_en1, LeftSpeedValue);
  analogWrite(_en2, RightSpeedValue);
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
}

void MotorDriver::diff_turn_forward(byte LeftSpeedValue, byte RightSpeedValue)
{
  analogWrite(_en1, LeftSpeedValue);
  analogWrite(_en2, RightSpeedValue);
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);
}

void MotorDriver::diff_turn_reverse(byte LeftSpeedValue, byte RightSpeedValue)
{
  analogWrite(_en1, LeftSpeedValue);
  analogWrite(_en2, RightSpeedValue);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
}

void MotorDriver::Control(byte SpeedValue, bool A, bool B, bool C, bool D)
{
  analogWrite(_en1, SpeedValue);
  digitalWrite(_in1, A);
  digitalWrite(_in2, B);
  digitalWrite(_in3, C);
  digitalWrite(_in4, D);
}

void MotorDriver::Control(byte LeftSpeedValue, bool A, bool B, bool C, bool D, byte RightSpeedValue)
{
  analogWrite(_en1, LeftSpeedValue);
  analogWrite(_en2, RightSpeedValue);
  digitalWrite(_in1, A);
  digitalWrite(_in2, B);
  digitalWrite(_in3, C);
  digitalWrite(_in4, D);
}

void MotorDriver::power_down()
{
  if (MotorState == false) {
    MotorDriver::halt(0);
  }
  else if (MotorState == true) {
    MotorDriver::halt(0, 0);
  }
}

/*
  //  END OF MotorDriver.cpp V. 1.0.0
  //  Copyright (c) 2021 Paul Pavish.  All right reserved.
*/
