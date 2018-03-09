/*
  ADXL3xx

  Reads an Analog Devices ADXL3xx accelerometer and communicates the
  acceleration to the computer. The pins used are designed to be easily
  compatible with the breakout boards from SparkFun, available from:
  http://www.sparkfun.com/commerce/categories.php?c=80

  The circuit:
  - analog 0: accelerometer self test
  - analog 1: z-axis
  - analog 2: y-axis
  - analog 3: x-axis
  - analog 4: ground
  - analog 5: vcc

  created 2 Jul 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ADXL3xx
*/

// these constants describe the pins. They won't change:
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
const int zpin = A2;                  // z-axis (only on 3-axis models)

int xpos = 0;
int ypos = 0;
int zpos = 0;

int xoutput = 0;
int youtput = 0;
int zoutput = 0;

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // print the sensor values:
  if(xoutput >= -10 && xoutput < 60){
    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if(xoutput >= 60 && xoutput < 120){
    digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
  }
  else if(xoutput >= 120){
    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
  xpos = analogRead(xpin);
  xoutput = map(xpos, 500, 600, 0, 180);
  Serial.print("\nRaw X: ");
  Serial.print(xpos);
  Serial.print("\t");
  //Serial.print("Mapped X:");
  Serial.print(xoutput);
  // print a tab between values:
  /*Serial.print("\t");
  Serial.print("Y:");
  ypos = analogRead(ypin);
  youtput = map(ypos, 200, 300, 0, 180);
  Serial.print(youtput);
  // print a tab between values:
  Serial.print("\t");
  Serial.print("Z:");
  zpos = analogRead(zpin);
  Serial.print(zpos);
  Serial.println();
  */
  // delay before next reading:
  delay(100);
}
