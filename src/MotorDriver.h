  /*
  //   Title : MotorDriver.cpp
  //   Author : Paul Pavish
  //   Website : www.basicsexplained.com/creator
  //   YT Channel : https://www.youtube.com/channel/UCavN7aolUmBbfcKbDbydvMA
  //   LinkedIn : https://www.linkedin.com/in/paulpavish/
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
#ifndef MotorDriver_H
#define MotorDriver_H

#include<Arduino.h>

//Functions Here

class MotorDriver {
  public:
    MotorDriver(byte EN1, byte IN1, byte IN2, byte IN3, byte IN4);
    MotorDriver(byte EN1, byte IN1, byte IN2, byte IN3, byte IN4, byte EN2);
    void forward(byte SpeedValue);
    void forward(byte LeftSpeedValue, byte RightSpeedValue);
    void reverse(byte SpeedValue);
    void reverse(byte LeftSpeedValue, byte RightSpeedValue);
    void halt(byte MinSpeedValue);
    void halt(byte LeftMinSpeedValue, byte RightMinSpeedValue);
    void turn_left(byte SpeedValue);
    void turn_left(byte LeftSpeedValue, byte RightSpeedValue);
    void turn_right(byte SpeedValue);
    void turn_right(byte LeftSpeedValue, byte RightSpeedValue);
    void diff_turn_forward(byte LeftSpeedValue, byte RightSpeedValue);
    void diff_turn_reverse(byte LeftSpeedValue, byte RightSpeedValue);
    void Control(byte SpeedValue, bool A, bool B, bool C, bool D);
    void Control(byte LeftSpeedValue, bool A, bool B, bool C, bool D, byte RightSpeedValue);
    void power_down();

  private:
    byte _en1, _en2, _in1, _in2, _in3, _in4;
    bool MotorState; //false(0) = One Enable; true(1) = Two Enables;

};


#endif
