#include <Servo.h>

int trig_Pin = 11;
int echo_Pin = 12;

int soap = 2;
int water = 3;

int buzzer = 9;

Servo waterOn;
Servo waterOff;

long duration;
int distance;

void setup() {

  waterOn.attach(5);
  waterOff.attach(6);

  pinMode(trig_Pin, OUTPUT);
  pinMode(echo_Pin, INPUT);

  pinMode(soap, OUTPUT);
  pinMode(water, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  
  digitalWrite(water, HIGH);
  digitalWrite(soap, HIGH);

  delay(3000);

  digitalWrite(water, LOW);
  digitalWrite(soap, LOW);
  
}

void loop() {

  digitalWrite(water, LOW);
  digitalWrite(soap, LOW);
  
  digitalWrite(buzzer, LOW);

  digitalWrite(trig_Pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin, LOW);

  duration = pulseIn(echo_Pin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" centimeters");

  delay(500);

  if(distance <= 15) {
    
    digitalWrite(buzzer, HIGH);  
    delay(3000);
    digitalWrite(buzzer, LOW);

    waterOn.write(90);
    delay(500);
    waterOn.write(0);

    digitalWrite(water, HIGH);
    delay(7000);
    
    digitalWrite(buzzer, HIGH);
    digitalWrite(water, LOW);
    delay(500);
    digitalWrite(water, HIGH);
    delay(500);
    digitalWrite(water, LOW);
    delay(500);
    digitalWrite(water, HIGH);
    delay(500);
    digitalWrite(water, LOW);
    delay(500);
    digitalWrite(water, HIGH);
    delay(500);
    digitalWrite(water, LOW);
    digitalWrite(buzzer, LOW);

    waterOff.write(90);
    delay(500);
    waterOff.write(0);
    
    delay(2500);

    digitalWrite(soap, HIGH);
    delay(17000);
    
    digitalWrite(soap, HIGH);
    digitalWrite(soap, LOW);
    delay(500);
    digitalWrite(soap, HIGH);
    delay(500);
    digitalWrite(soap, LOW);
    delay(500);
    digitalWrite(soap, HIGH);
    delay(500);
    digitalWrite(soap, LOW);
    delay(500);
    digitalWrite(soap, HIGH);
    delay(500);
    digitalWrite(soap, LOW);
    digitalWrite(buzzer, LOW);

    waterOn.write(90);
    delay(500);
    waterOn.write(0);

    digitalWrite(buzzer, HIGH);
    digitalWrite(water, LOW);
    delay(500);
    digitalWrite(water, HIGH);
    delay(500);
    digitalWrite(water, LOW);
    delay(500);
    digitalWrite(water, HIGH);
    delay(500);
    digitalWrite(water, LOW);
    delay(500);
    digitalWrite(water, HIGH);
    delay(500);
    digitalWrite(water, LOW);
    digitalWrite(buzzer, LOW);

    digitalWrite(water, HIGH);
    delay(7000);

    waterOff.write(90);
    delay(500);
    waterOff.write(0);

    delay(5000);
    
  }

}
