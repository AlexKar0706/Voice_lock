#include <Servo.h>
#define onCommandPin 10
#define offCommandPin 9
#define servoPin 3
#define ledPin 13

// variables
int onCommandStatus = 0,  // variable for reading 'ON' command of Arduino Nano
    offCommandStatus = 0, // variable for reading 'OFF' command of Arduino Nano
    lockStatus = LOW;    // variable for setting open and close status of lock

//Special object for servomotor
Servo Servo1; 

void setup() {
  pinMode(onCommandPin, INPUT);   // Initialize the pin for 'ON' command of Arduino Nano as an input
  pinMode(offCommandPin, INPUT);  // Initialize the pin for 'OFF' command of Arduino Nano as an input
  pinMode(ledPin, OUTPUT);        // Initialize the LED pin as an output
  Servo1.attach(servoPin);        // Initialize the servo pin for servomotor
  Servo1.write(180);              // Rotate servomotor to start position
}

void loop() {
  readNanoStatus();
  setLock();
}

//Function read the Arduino Nano status
void readNanoStatus () {
  onCommandStatus = digitalRead(onCommandPin);
  offCommandStatus = digitalRead(offCommandPin);
  if (onCommandStatus == HIGH) lockStatus = HIGH;
  else if (offCommandStatus == HIGH) lockStatus = LOW;
}

//Function for opening and closing the lock
void setLock() {
  if (lockStatus == HIGH) {        // Open the lock
    digitalWrite(ledPin, HIGH);
    Servo1.write(90);
  } else if (lockStatus == LOW) {  // Close the lock
    digitalWrite(ledPin, LOW);
    Servo1.write(180);
  }
}