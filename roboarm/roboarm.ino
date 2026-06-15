#include <Servo.h>

Servo baseServo;
Servo armServo;

int xPin = A0;   // X-axis of joystick
int yPin = A2;   // Y-axis of joystick

int xValue;
int yValue;

int baseAngle;
int armAngle;

void setup() {
  baseServo.attach(5);   // Servo 1
  armServo.attach(6);   // Servo 2
}

void loop() {

  // Read joystick values
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);

  // Convert joystick value to angle
  baseAngle = xValue / 5.68;
  armAngle = yValue / 5.68;

  // Move servos
  baseServo.write(baseAngle);
  armServo.write(armAngle);

  delay(100);
}