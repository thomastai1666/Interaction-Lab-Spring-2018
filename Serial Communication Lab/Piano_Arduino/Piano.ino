//Interactive Piano
//Thomas Tai

const int buzzer = 9; //buzzer to arduino pin 9
const int redLed = 10;
const int greenLed = 11;

float Notes[] = {261.626,293.665,329.628,349.228,391.995,
440.000,493.883,523.251,587.330,659.255,698.456,783.991,
880.000,987.767,1046.50,277.183,311.127,369.994,415.305,
466.164,554.365,622.254,739.989,830.609,932.328};
int valueFromProcessing;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//analog communication
  pinMode(buzzer, OUTPUT); // Set buzzer pin
  pinMode(redLed, OUTPUT); 
  pinMode(greenLed, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  //Debugging for all data values
  while (Serial.available()) {
    valueFromProcessing = Serial.read();
  }
  if(valueFromProcessing == 255 or valueFromProcessing == 0){
    noTone(buzzer);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else{
    tone(buzzer, Notes[valueFromProcessing-1]);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  }
  
  delay(50);
}
