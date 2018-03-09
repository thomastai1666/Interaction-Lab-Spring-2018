PImage bg;
float angle = 0;
int counter = 0;
void setup(){
  //delay(5000);
  //Initialize environment variables
  background(0);
  size(500,500);
  smooth();
  noStroke();
  frameRate(60);
  
  //Used to save processing power as filter is CPU demanding
  PGraphics pg = createGraphics(width, height, JAVA2D);
  pg.beginDraw();
  pg.background(#000000);
  pg.fill(255);
  pg.ellipse(150,150,210,210); //Create outer white border
  pg.filter( BLUR, 9 );
  pg.fill(0);
  pg.endDraw();
 
  //Save background for redrawing
  bg = pg.get();
}

void draw(){
  //Redraw black background
  set(0, 0, bg);
  
  ellipseMode(CENTER); //Circles only
  
  //Create Sun-like Object
  fill(22,33,72);
  ellipse(150,150,200,200); //Create blue circle
  fill(0);
  ellipse(counter,120,130,130); //Create black shadow
  
  //Increment shadow x position
  counter += 1;
  
  //Move shadow back to initial frame
  if(counter > 500){
    counter = -100;
  }
  
  //Function draws a circle with the following paramters:
  //draw_Circle(x, y, size, r, g, b, speed_multiplier, translate_1, translate_2);
  draw_Circle(0, 0, 40, 174, 107, 109, 1, 90, 0); //Pink circle 1
  draw_Circle(0, 0, 14, 180, 151, 62, -2, 36, 0); //Yellow circle 2
  draw_Circle(300, 300, 90, 141, 136, 149, -0.3, 30, 0); //Lavendar circle 3
  draw_Circle(300, 300, 30, 86, 122, 152, 0.8, 30, 0); //Blue circle 4
  draw_Circle(310, 310, 10, 135, 25, 25, 2, 30, 0); //Red Circle 5
  draw_Circle(315, 315, 10, 20, 20, 20, 2.1, 30, 0); //Black Circle 6
  draw_Circle(200, 150, 30, 26, 43, 90, -.7, 30, 0); //Blue Circle 7
  draw_Circle(250, 50, 20, 130, 106, 73, 1.5, 30, 0); //Grey Circle 8
  draw_Circle(400, 400, 70, 255, 30, 60, -1.1, 10, 50); //Red Circle 9
  draw_Circle(200, 200, 50, 189, 162, 69, 0.2, 40, 40); //Yellow Circle 10
  draw_Circle(200, 180, 50, 127, 68, 31, 0.3, 40, 40); //Orange Circle 11
  draw_Circle(200, 200, 50, 127, 39, 33, 0.25, 50, 40); //Red Circle 12
  draw_Circle(220, 200, 50, 127, 50, 70, 0.3, 50, 40); //Pink Circle 12
  draw_Circle(200, 200, 50, 127, 39, 33, -2.1, 50, 40); //Red Circle 13
  draw_Circle(210, 210, 50, 169, 126, 90, -0.6, 30, 0); //Gold Circle 14 
  draw_Circle(210, 210, 50, 69, 120, 60, -0.5, 30, 0); //Light green circle 15
  draw_Circle(200, 100, 80, 26, 52, 51, 0.9, 30, 0); //Green Circle 16
  draw_Circle(200, 100, 20, 0, 0, 0, 0.9, 30, 0); //Black Circle 17
  draw_Circle(100, 300, 58, 81, 97, 112, 1.0, 30, 0); //White-Blue Circle 18
  draw_Circle(100, 300, 55, 13, 13, 13, 1.0, 30, 0); //Black Circle 19
  draw_Circle(100, 300, 50, 145, 130, 149, 1.0, 30, 0); //Lavender Circle 20
  draw_Circle(100, 310, 20, 0, 0, 0, 1.0, 30, 0); //Black Circle 21
  draw_Circle(315, 315, 10, 20, 20, 20, 2.1, 30, 0); //Black Circle 22
  draw_Circle(200, 200, 70, 81, 63, 28, -1.3, 40, 40); //Gold circle 23
  draw_Circle(450, 450, 30, 110, 138, 116, 1.2, 40, 40); //Light green circle 24
  draw_Circle(300, 150, 70, 26, 38, 85, 1.5, 40, 40); //Brown circle circle 25
  draw_Circle(400, 400, 20, 30, 40, 110, 1.5, 30, 0); //Blue Circle 27
  draw_Circle(410, 410, 20, 150, 30, 30, -1.5, 30, 0); //Red Circle 28
  draw_Circle(250, 400, 30, 170, 143, 37, 1.5, 30, 0); //Yellow Circle 29
  draw_Circle(290, 270, 80, 193, 113, 28, -0.295, 30, 0); //Lavendar circle 3
  
  //Increment rotation variable (Rotating Objects)
  angle += 0.008;
}

void draw_Circle(int x, int y, int size, int r, int g, int b, float speed, int t1, int t2){
  pushMatrix();
  rotate(angle * speed); 
  translate(t1, t2);
  fill(r,g,b,200);
  ellipse(x, y, size, size);
  popMatrix();
}