/*
   This is the Validate() functions that validates the answer and returns True or False Response.
*/

bool Validate() {
  char ans = '0';
  while (ans == '0') {
    char a;
    if (Serial.available()) {
      a = Serial.read();
    }
    if (a == 'y' || a == 'n' || a == 'N' || a == 'Y') {
      ans = a;
      if (a == 'y' || a == 'Y') {
        return true;
      }
      else if (a == 'n' || a == 'N') {
        return false;
      }
    }
  }
}
