import java.util.Arrays;
import processing.serial.*;

Serial myPort;
int valueFromArduino;

//Used only for reference
float[] whiteKeyNotes = {261.626,293.665,329.628,349.228,391.995,440.000,493.883,523.251,587.330,659.255,698.456,783.991,880.000,987.767,1046.50};
float[] blackKeyNotes = {277.183,311.127,369.994,415.305,466.164,554.365,622.254,739.989,830.609,932.328};

//Rectangle cordinates
int[] rect_x = {45,105,225,285,345,465,525,645,705,765};

void setup(){
  //Serial communication
  //printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[ 2 ], 9600);
  //Draw a simple piano
  size(900,400);
  background(255);
  stroke(0);
  strokeWeight(1.15);
  for(int x = 0; x < 900; x = x + (width/15)){
    if(x > 50){
      line(x,1000,x,0);
    }
  }
  fill(0);
  for(int x = 0; x< rect_x.length; x++){
    rect(rect_x[x],0,30,220);
  }
}

void draw(){
  //Check piano keys
  boolean blackKeyPressed = false;
  int keyPressed = 255; //No key pressed = 255
  if (mousePressed == true) {
    //Check for black keys being pressed
    for(int x = 0; x< rect_x.length; x++){
      int value = rect_x[x];
      if((mouseX >= value - 15) && (mouseX <= value + 30) && mouseY <= 220){
        println("Black key being pressed: " +x);
        keyPressed = x + 15; //Offset white key base value
        blackKeyPressed = true;
      }
    }
    //Check white keys being pressed
    if(blackKeyPressed == false){
      println("White key being pressed: " +mouseX/60);
      keyPressed = mouseX / 60;
    }
  }
  myPort.write(keyPressed+1);
  //println(keyPressed);
}