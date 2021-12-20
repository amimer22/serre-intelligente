#include "DHT.h"

#define DHTPIN 2
 
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
int const trigPin = 10;
int const echoPin = 9;
int solhumidité =analogRead(A2);
int lumiere = analogRead(A0);
void setup() {
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  Serial.begin(9600);
   
  // Initialise la capteur DHT11
  dht.begin();
}

void loop() {
 // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  int duration, distance;
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  //
  Serial.println("Temperature = " + String(dht.readTemperature())+" °C");
  Serial.println("Humidite = " + String(dht.readHumidity())+" %");
  
}
