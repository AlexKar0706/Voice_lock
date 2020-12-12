#include <Servo.h>
#include <SoftwareSerial.h>
#define rxPin 10
#define txPin 11
#define baudrate 9600

// Pins declaration. Button pin is used for debugging.
//const int buttonPin = 2;
const int ledPin = 13;       // LED pin.(can be changed on LED_BUILTIN)
const int servoPin = 3;      // Pin for servomotor

// variables
// Button variables only used for debugging with button pin
/*int currButtonState = LOW;
int prevButtonState = LOW;
int flag = 0*/
int data = '0'; // data variable represent the data received from bluetooth-module 

//Special objects for servomotor and for bluetooth module HC-05
Servo Servo1;
SoftwareSerial hc05(rxPin ,txPin); 

void setup() {
  //pinMode(buttonPin, INPUT); // Initialize the pushbutton pin as an input
  pinMode(rxPin,INPUT);        // Initialize the rx pin for HC-05 module as input
  pinMode(txPin,OUTPUT);       // Initialize the tx pin for HC-05 module as output
  pinMode(ledPin, OUTPUT);     // Initialize the LED pin as an output
  hc05.begin(baudrate);        // Set fixed baudrate for module HC-05
  Servo1.attach(servoPin);     // Initialize the servo pin for servomotor
  Servo1.write(180);           // Rotate servomotor to start position
}

void loop() {
  readStatus();
  setLock();
}

// Function for reading status of bluetooth module
void readStatus() {
    if (hc05.available()) data = hc05.read(); // Read information from bluetooth module

    //Button version for debugging
    /*currButtonState = digitalRead(buttonPin);
    if (!currButtonState && currButtonState != prevButtonState) flag ^= 1;
    prevButtonState = currButtonState;
    if (flag) data = '1';
    else data = '0';
    */
}

//Function for opening and closing the lock
void setLock() {
  if (data == '1') {            // Open the lock
    digitalWrite(ledPin, HIGH);
    Servo1.write(90);
  } else if (data == '0') {     // Close the lock
    digitalWrite(ledPin, LOW);
    Servo1.write(180);
  }
}