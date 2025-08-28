#include <Servo.h>

byte servoPin = 9;

int potentiometer_pin=A0;

Servo servo;

void setup() {
  servo.attach(servoPin);

  servo.writeMicroseconds(1500); // send "stop" signal to ESC.

  delay(7000); // delay to allow the ESC to recognize the stopped signal

  pinMode(potentiometer_pin,INPUT);
  
}

void loop() {
//  int signal = 1700; // Set signal value, which should be between 1100 and 1900
  int potentiometer_reading=analogRead(potentiometer_pin);  //this is from 0 to 1023
  int signal= 1100 + (v * (1900 - 1100)) / 1023;   //scale reading to range

  servo.writeMicroseconds(signal); // Send signal to ESC.
}
