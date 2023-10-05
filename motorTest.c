#include <Servo.h>
Servo servo1;
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
int ledPin = 6; // Define the pin for the LED
bool servoMoved = false; // Flag to track if the servo has moved

void setup() {
  servo1.attach(7); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  ultra();
  servo1.write(0);
  digitalWrite(ledPin, LOW); // Turn off the LED
  servoMoved = false; // Reset the flag

  if (distance <= 10) {
    int servoAngle = servo1.read(); // Read the current angle of the servo
    
    if (!servoMoved && servoAngle >= 45) {
      digitalWrite(ledPin, HIGH); // Turn on the LED when an object is detected and servo has moved at least 45 degrees
      servoMoved = true; // Set the flag to indicate that the servo has moved
    }
    
    servo1.write(90); // Move the servo to 90 degrees
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
