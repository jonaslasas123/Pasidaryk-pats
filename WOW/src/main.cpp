#include <Arduino.h>

String inputString = "";      // a String to hold incoming data
bool inputComplete = false;   // whether the string is complete

void setup() {
  Serial.begin(9600);         // Start serial communication at 9600 baud
  Serial.println("Enter text:");
}

void loop() {
  // Check if input is complete
  if (inputComplete) {
    Serial.print("You entered: ");
    Serial.println(inputString);

    // Clear the input
    inputString = "";
    inputComplete = false;
  }
}

// This function is automatically called when new serial data arrives
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inChar == '\n') {  // End of input line
      inputComplete = true;
    }
  }
}