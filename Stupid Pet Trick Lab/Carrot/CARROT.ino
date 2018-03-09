//Music System
const int buzzer = 8; //buzzer to arduino pin 8
const float noteE5 = 659.3; //E Natural 
const float noteA4 = 440.0; //A Natural
const float noteC5 = 554.4; //C Sharp
const float noteD5 = 587.3; //D Natural
const float noteB4 = 493.9; //B Natural
//Light System
int redPin = 10;
int greenPin = 11;
int bluePin = 9;
//Plant settings
int correctMoisture = 400;
int correctTemp = 20;
int correctLight = 900;
//Temperature
int tempPin = 0;
int temp;
//Moisture
int mosPin = 2;
int moisture;
//Light
int lightPin = 1;
int light;
//Carrot
int health;



/*The smart carrot can keep track of your plant's health
There are three factors to keep your carrot happy:
1.) Moisture - Maintaining soil moisture is important to growth
2.) Light - Plants need light to survive!
3.) Temperature - Air temperature must always be above freezing

Output:
1.) Light - Red means poor health, Orange is deteriorating health, Green means the plant is healthy!
2.) The carrot will sing a song to let you know it needs attention
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//analog communication
  pinMode(buzzer, OUTPUT); // Set buzzer pin
  pinMode(redPin, OUTPUT); //Red pin
  pinMode(greenPin, OUTPUT); //Green pin
  pinMode(bluePin, OUTPUT);   //Blue pin
}

void loop() {
  // put your main code here, to run repeatedly:
  //Get light readings
  light = 1023 - analogRead(lightPin);
  //Get moisture readings
  moisture = analogRead(mosPin);   
  //Begin temperature reading
  temp = analogRead(tempPin);
  float mv = (temp/1024.0)*5000; 
  float cel = mv/10;
  //Calculate difference between correct and actual values
  int lightdeviation = abs(light - correctLight);
  int moisturedeviation = abs(moisture - correctMoisture);
  int tempdeviation = abs(temp - correctTemp);
  health = 100;
  if(moisturedeviation > 300 and moisturedeviation <= 500){
    health = health - 20;
  }
  else if(moisturedeviation > 500){
    health = health - 40;
  }
  if(tempdeviation > 5 and tempdeviation <= 20){
    health = health - 20;
  }
  else if(tempdeviation > 20){
    health = health - 50;
  }
  health = 100;
  if(lightdeviation > 100 and lightdeviation <= 300){
    health = health - 25;
  }
  else if(lightdeviation > 300 and lightdeviation <= 600){
    health = health - 45;
  }
  else if(lightdeviation > 600){
    health = health - 65;
  }
  //Debugging for all data values
  Serial.print("Temp = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.print("\tMoisture = ");
  Serial.print(moisture);    
  Serial.print("\tLight = ");
  Serial.print(light); 
  Serial.print("\tHealth = ");
  Serial.print(health);
  Serial.println();
  if(health <= 40){
    setColor(255,0,0);
    music();
  }
  else if(health < 80 and health > 40){
    setColor(255,50,0);
  }
  else{
    setColor(0,255,0);
  }
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void music(){
  //Composed in 4/4 (Lightly Row Folk Song)
  //Using Double note = 1 second
  
  tone(buzzer, noteE5); // Send E
  delay(500);        // quarter note
  
  tone(buzzer, noteC5); // Send C
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 
  
  tone(buzzer, noteC5); // Send C
  delay(1000);        // half note
  
  tone(buzzer, noteD5); // Send D
  delay(500);        // quarter note

  tone(buzzer, noteB4); // Send B
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 
  
  tone(buzzer, noteB4); // Send B
  delay(1000);        // half note

  tone(buzzer, noteA4); // Send A
  delay(500);        // quarter note

  tone(buzzer, noteB4); // Send B
  delay(500);        // quarter note

  tone(buzzer, noteC5); // Send C
  delay(500);        // quarter note

  tone(buzzer, noteD5); // Send D
  delay(500);        // quarter note

  tone(buzzer, noteE5); // Send E
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound...

  tone(buzzer, noteE5); // Send E
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound...

  tone(buzzer, noteE5); // Send E
  delay(1000);        // quarter note
  noTone(buzzer);     // Stop sound...

  tone(buzzer, noteE5); // Send E
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound...
  
  tone(buzzer, noteC5); // Send C
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 

  tone(buzzer, noteC5); // Send C
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound...
  
  tone(buzzer, noteC5); // Send C
  delay(500);        // half note

  tone(buzzer, noteD5); // Send D
  delay(500);        // quarter note

  tone(buzzer, noteB4); // Send B
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 

  tone(buzzer, noteB4); // Send B
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 

  tone(buzzer, noteB4); // Send B
  delay(500);        // quarter note

  tone(buzzer, noteA4); // Send A
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 

  tone(buzzer, noteC5); // Send C
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 

  tone(buzzer, noteE5); // Send E
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 

  tone(buzzer, noteE5); // Send E
  delay(500);        // quarter note
  
  tone(buzzer, noteC5); // Send C
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound...

  tone(buzzer, noteC5); // Send C
  delay(500);        // quarter note
  noTone(buzzer);     // Stop sound... 

  tone(buzzer, noteC5); // Send C
  delay(1000);        // half note
  noTone(buzzer);     // Stop sound... 
}
