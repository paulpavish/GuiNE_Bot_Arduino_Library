/*
  //   Title : GuiN-E UNO Motor Calibration V1.0
  //   Author : Paul Pavish
  //   Website : www.basicsexplained.com/creator
  //   YT Channel : https://www.youtube.com/channel/UCavN7aolUmBbfcKbDbydvMA
  //   LinkedIn : https://www.linkedin.com/in/paulpavish/
  //
  //   Kindly attribute to Author on any marvelous project you come up with using this piece of code.
  //   Also show your support at my Youtube Channel. Thankyou.
  //
  //   This sketch is a test run sketch to find out the correct pins for control of base motors.
  //   Note: This sketch helps to identify which is LEFT / RIGHT motor along with FORWARD / REVERSE controls.

   Run this code with the following Pin Configuration :
   -------------------------------------------
   ARDUINO_UNO PIN  : MOTOR_DRIVER (L293D) PIN
   -------------------------------------------
        PIN 3       :       EN_1 & EN_2
        PIN 4       :           IN 1
        PIN 5       :           IN 2
        PIN 6       :           IN 3
        PIN 7       :           IN 4

   Note: Any directions asked during the calibration is with respect to the Robot.

*/

//Including Libraries
#include<MotorDriver.h>

//DO NOT CHANGE THESE PINS
#define SpeedPin 3
#define LeftCtrl_A  4
#define LeftCtrl_B  5
#define RightCtrl_A 6
#define RightCtrl_B 7



//Defining the Base MotorDriver with a single SpeedPin (Similar speed) for both motors at all times
MotorDriver Base(SpeedPin, LeftCtrl_A, LeftCtrl_B, RightCtrl_A, RightCtrl_B);

//Defining Same Speed Value for both motors
#define SpeedVal 127
#define MinSpeedVal 25
#define MaxSpeedVal 215

//Calibration flag
bool calib = false;

void setup() {

  //Initializing Serial Communication
  Serial.begin(115200);

  Serial.println(F("Setup Complete.\nInitializing Base Motor Test.\nMake sure your robot is placed above ground,\nand no wheels are touching the ground."));
  Serial.println(F("Type any key & Press Enter, when ready:"));
  while (!Serial.available()) {}

  //Testing for similar rotation
  Base.forward(SpeedVal);

  //Ask Questions
  calib = Ask();

}

void loop() {

  if (calib) {
    //Move Forward
    Base.forward(SpeedVal);
    delay(2000);
    //halt and be ready for next command
    Base.halt(MinSpeedVal);
    delay(1000);
    //Move Backwards
    Base.reverse(SpeedVal);
    delay(2000);
    //halt and be ready for next command
    Base.halt(MinSpeedVal);
    delay(1000);
    //Turn Left
    Base.turn_left(SpeedVal);
    delay(2000);
    //halt and be ready for next command
    Base.halt(MinSpeedVal);
    delay(1000);
    //Turn Right
    Base.turn_right(SpeedVal);
    delay(2000);
    //halt and be ready for next command
    Base.halt(MinSpeedVal);
    delay(1000);
  }
  else {
    Base.power_down();
  }
}
