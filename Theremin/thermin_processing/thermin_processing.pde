import java.util.Arrays;
import processing.serial.*;
import processing.sound.*;

AudioDevice device;
SoundFile[] file;

Serial myPort;
int valueFromArduino;
String myString;
int rawvolume;

float volume;
int pitch;

float noteStartTime;
float noteEndTime;
int notePlayed = -1;
final int notes = 15;

//Black Rectangle cordinates
int[] rect_x = {45,105,225,285,345,465,525,645,705,765};

//Audio files by Jobro
//Link: https://freesound.org/people/jobro/packs/2489/?page=2#sound
//License: http://creativecommons.org/licenses/by/3.0/

void setup(){
  //Initialize Serial communication
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[ 2 ], 9600);
  //Initialize window
  size(901,400);
  background(255);
  //Initialize Sound Files
  device = new AudioDevice(this, 48000, 32);
  file = new SoundFile[notes];
  for(int i = 0; i < notes; i++){
    file[i] = new SoundFile(this, i + ".wav");
  }
}

void draw(){
  //Gather data from serial port
  while(myPort.available() > 0){
    myString = myPort.readStringUntil(10);
  }
  //Interpret data and split into separate ints
  String[] myArrayofValues = split(myString,",");
  rawvolume = Integer.valueOf(myArrayofValues[0]);
  pitch = Integer.valueOf(myArrayofValues[1].toString().trim());
  //Reduce and map values to make it easier to work with
  volume = map(rawvolume, 0, 50, 0, 3);
  //DEBUG: println("Volume: " +volume +"  Pitch: " +pitch);
  animatePiano();
}

void animatePiano(){
  strokeWeight(1.15);
  //Draw and animate white keys
  for(int x = 0; x <= 900; x = x + (width/15)){
    if(x / 60 == pitch - 2){
      fill(200);
      if(x/60 < 15){
        playNote(x / 60);
      }
    }
    else{
      fill(255);
    }
    rect(x,0,60,1000);
  }
  //Draw black keys
  fill(0);
  for(int x = 0; x< rect_x.length; x++){
    rect(rect_x[x],0,30,220);
  }
}

void playNote(int Note){
  //Only play note if it is different, or there is no note being played
  if(notePlayed != Note){
    noteStartTime = millis();
    noteEndTime = millis() + (file[Note].duration() * 500);
    file[Note].play(1.0, volume);
    notePlayed = Note;
  }
  //Reset notePlayed if note is over
  if(millis() >= noteEndTime){
    notePlayed = -1;
  }
}