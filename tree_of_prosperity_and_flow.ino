#include <CapacitiveSensor.h>
#include <SPI.h>
#include <TFT.h>

#define CS   10
#define DC   9
#define RESET  8

TFT myScreen = TFT(CS, DC, RESET);

CapacitiveSensor capSensor = CapacitiveSensor(4,2);
int threshold = 1000;
const int ledPin1 = 3;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 9;
const int ledPin5 = 10;
const int ledPin6 = 11;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
    pinMode(ledPin5, OUTPUT);
    pinMode(ledPin6, OUTPUT);

}

void loop() {
    long sensorValue = capSensor.capacitiveSensor(30);
    Serial.println(sensorValue);
  if(sensorValue < threshold) {
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);
      digitalWrite(ledPin3,LOW);
      digitalWrite(ledPin4,LOW);
      digitalWrite(ledPin5,LOW);
      digitalWrite(ledPin6,LOW);
  } else { 
    for (int fadeValue = 0; fadeValue <=255; fadeValue ++){
      analogWrite(ledPin1, fadeValue);
      analogWrite(ledPin2, fadeValue);
      analogWrite(ledPin3, fadeValue);
      analogWrite(ledPin4, fadeValue);
      analogWrite(ledPin5, fadeValue);
      analogWrite(ledPin6, fadeValue);
     delay(8);
     Serial.println(fadeValue);
    }
    
    for (int fadeValue = 255; fadeValue >=0; fadeValue --){
      analogWrite(ledPin1, fadeValue);
      analogWrite(ledPin2, fadeValue);
      analogWrite(ledPin3, fadeValue);
      analogWrite(ledPin4, fadeValue);
      analogWrite(ledPin5, fadeValue);
      analogWrite(ledPin6, fadeValue);
    delay(8);
    Serial.println(fadeValue);
   }
  }
    
    delay(88);
}
