//Recitation week 7
//Thomas Tai

int potentiometerPin = A1;
int processingPin = A0;
int valueFromProcessing;

void setup() {
  Serial.begin(9600);
}


void loop() {
  int sensorValue = analogRead(potentiometerPin);
  int value = analogRead(processingPin);
  Serial.write(sensorValue); 
  delay(10); 
}
