#include <Servo.h>

Servo myServo;

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 3;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myServo.attach(6);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
    myServo.write(90);
  } else {
    digitalWrite(ledPin, LOW);
    myServo.write(0);
  }

  delay(200);
}
