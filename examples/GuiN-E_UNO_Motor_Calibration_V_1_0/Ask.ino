/*
   This is the Ask() functions that asks questions for calibrating the Base motors
*/

bool Ask(){
  Serial.println(F("Are the Both the motors turning in the Same Direction ? : Yes(Y/y) or No(N/n)"));
  bool a_1 = Validate();
  if (a_1 == true) {
    Serial.println(F("Yes."));
    Serial.println(F("Are they rotating in Forward Direction ? : Yes(Y/y) or No(N/n)"));
    bool a_1_1 = Validate();
    if (a_1_1 == true) {
      Serial.println(F("Yes."));
      Serial.println(F("Congratulations! The current Pin configuration is correct and can be used as it is for GuiN-E Bot V1.0"));
      return true;
    }
    else if (a_1_1 == false) {
      Serial.println(F("No."));
      Serial.println(F("So the motors are rotating in Reverse/Backward Direction. No Problem."));
      Serial.println(F("Just reverse the wiring connections (on the driver) for both the motors in their respective terminals."));
      Serial.println(F("After changing the wiring as suggested above:\n 1. Clear the terminal output\n 2. Press reset button (on Arduino UNO) and Run this again to confirm."));
      return false;
    }
  }

  else if (a_1 == false) {
    Serial.println(F("No."));
    Serial.println(F("OK. Then Let's find which motor to rewire."));
    Serial.println(F("Which of the two motors is rotating in Forward Direction ? Left(Y/y) or Right(N/n)"));
    bool b_1 = Validate();
    if (b_1 == true) {
      Serial.println(F("Left Motor."));
      Serial.println(F("This means the Left motor is connected correctly."));
      Serial.println(F("Just reverse the wiring connection (on the driver) for the Right Motor in its terminal."));
      Serial.println(F("After changing the wiring as suggested above:\n 1. Clear the terminal output\n 2. Press reset button (on Arduino UNO) and Run this again to confirm."));
      return false;
    }
    else if (b_1 == false) {
      Serial.println(F("Right Motor."));
      Serial.println(F("This means the Right motor is connected correctly."));
      Serial.println(F("Just reverse the wiring connection (on the driver) for the Left Motor in its terminal."));
      Serial.println(F("After changing the wiring as suggested above:\n 1. Clear the terminal output\n 2. Press reset button (on Arduino UNO) and Run this again to confirm."));
      return false;
    }
  }
}
