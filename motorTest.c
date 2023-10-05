#include <Servo.h>
Servo servo1;
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
int ledPin = 6; // Define the pin for the LED

void setup() {
  servo1.attach(7); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  ultra();
  servo1.write(0);
  digitalWrite(ledPin, LOW); // Turn off the LED

  if (distance <= 10) {
    servo1.write(90);
    if(servo1.write>=30){
      digitalWrite(ledPin, HIGH); // Turn on the LED when an object is detected
    }
  }
}

void ultra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
