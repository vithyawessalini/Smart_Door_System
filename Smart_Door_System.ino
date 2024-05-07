const int motionSensorPin = 2; 
const int servoMotorPin = 9; 
volatile bool motionDetected = false;
#include <Servo.h>
Servo doorServo;
void setup() {
  Serial.begin(9600);
  doorServo.attach(servoMotorPin);
  attachInterrupt(digitalPinToInterrupt(motionSensorPin), motionDetectedISR, HIGH);
  doorServo.write(0);
  Serial.println("Smart Door System initialized.");
}
void loop() {
  if (motionDetected) {
    Serial.println("Motion detected! Opening door...");
    doorOpen();
    motionDetected = false;
    delay(5000);
    doorClose();
  }
}
void motionDetectedISR() {
  motionDetected = true;
}
void doorOpen() {
  doorServo.write(90);
}
void doorClose() {
  doorServo.write(0);
}
