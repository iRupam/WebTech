#include <Servo.h>
Servo servo1;

void setup() {
  servo1.attach(7);
}

void loop() {
delay(1000);//by this code I basically checked whether the motor is moving on its own or from a false signal from the ultrasonic sensor.
}



