/*
 * Midterm Project for Interactive Media Lab Spring 2018
 * Thomas Tai
 * March 18, 2018
 * References: Ping Example Code, Grove LED Example Code
 * Audio files by Jobro
 * Link: https://freesound.org/people/jobro/packs/2489/?page=2#sound
 * License: http://creativecommons.org/licenses/by/3.0/
*/

#include <Grove_LED_Bar.h>
Grove_LED_Bar leftbar(9, 8, 0);
Grove_LED_Bar rightbar(6, 7, 0);

//Sensor pins
const int pitchPin = 2;
const int volPin = 3;


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  leftbar.begin();
  rightbar.begin();
}

void loop() {
  long duration1,duration2,cm1,cm2;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(volPin, OUTPUT);
  digitalWrite(volPin, LOW);
  delayMicroseconds(2);
  digitalWrite(volPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(volPin, LOW);

  pinMode(volPin, INPUT);
  duration1 = pulseIn(volPin, HIGH);

  pinMode(pitchPin, OUTPUT);
  digitalWrite(pitchPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pitchPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pitchPin, LOW);

  pinMode(pitchPin, INPUT);
  duration2 = pulseIn(pitchPin, HIGH);

  // convert the time into a distance
  cm1 = microsecondsToCentimeters(duration1); //Volume
  cm2 = microsecondsToCentimeters(duration2); //Pitch

  if(cm1 > 50){
    cm1 = 50;
  }
  if(cm2 > 30){
    cm2 = 30;
  }
  
  Serial.print(cm1);
  Serial.print(",");
  Serial.print(cm2);
  Serial.println();

  animateBar(cm1,cm2);
  
  delay(100);
}

void animateBar(int volume, int pitch){
  leftbar.setLevel(0);
  rightbar.setLevel(0);
  if(pitch <= 8){
    leftbar.toggleLed(pitch+1);
  }
  if(pitch > 8 and pitch <= 16){
    rightbar.toggleLed(10 - (pitch - 9));
  }
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
