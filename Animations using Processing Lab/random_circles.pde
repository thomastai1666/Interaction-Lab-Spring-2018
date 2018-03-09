void setup(){
  size(500,500);
  background(0);
}

void draw(){
  float a = random(width);
  float b = random(height);
  float size = random(10,300);
  float c = random(255);
  circle(a,b,size);
}

void circle(float a,float b,float size){
  noFill();
  stroke(random(255),random(255),random(255));
  ellipse(a,b,size,size);
}