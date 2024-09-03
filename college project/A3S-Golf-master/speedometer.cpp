#include "speedometer.h"

//Initialize all other variables to zero
speedometer::speedometer() {
      angle = x = y = 0;
      buffer = create_bitmap(640, 480); //create secondry screen
}

//	Load all bitmaps in an array
bool speedometer::load_bitmap_and_sample() {
     char s[20]; 
     for (int i=0; i<6; i++) {
         sprintf(s,"bitmaps\\arrow%d.bmp",i);
         image[i] = load_bitmap(s, NULL);
         if (!image[i]) { allegro_message("speedometer Bitmap not found");  return 0; }    
      } 
      return 1;
}

//Draw bitmap of speedometer on the position passed as argument.
void speedometer::draw(int a, int b) {
      x = a; y = b;
      blit(screen, buffer, 0, 0, 0, 0, 640, 480); //copying all content of screen on buffer..... 
      draw_sprite(screen, image[0], x, y); //drawing 1st image of meter
}

//A loop that runs until click is hold. Redraw background and ball. 
//Draw bitmaps continuously to create a filling effect. Rest for some time before another loop.
int speedometer::fill_up() {
    
     for (int i=0; i<6; i++) {
          pivot_sprite(screen, image[i], x+20, y, 20, 0, itofix(angle));//builtin function to draw speedometer on next position
          rest(150);
          if (!mouse_b & 1) { //false until click is hold. 
              int a = (i+1)*50;
              return a;              } //+1 to work in case of zero
          
          if( i==4 ) { //for continous and infinite effect
              i=0;
              pivot_sprite(screen, image[5], x+20, y, 20, 0, itofix(angle));  }    
          rest(150);                }
          
     //return 
}

//Redraw background, hole and ball.Rotate bitmap of meter on a pivot according to position of mouse.
//Draw bitmap of meter on new position. Rest for some time.
int speedometer::direct() {    
    rest(100);
    while (!mouse_b & 1) { //wait until click
        angle = 128- abs(fixtoi(fatan2(ftofix(mouse_x-x), ftofix(mouse_y-y)))+ 128); //formula for calculating angle wrt mouse position
        angle/=32;        angle*=32; //to drop of remainders
        blit(buffer, screen,  0, 0, 0, 0, 640, 480);
        
        if (key[KEY_M])        
            return -1; //in game pause (IN-GAME MENU)
        
        pivot_sprite(screen, image[0], x+20, y, 20, 0, itofix(angle));
    }
    return angle;
}   
 
//Unload all bitmaps from memory if not deleted previously.     
speedometer::~speedometer() { 
    
    for (int i=0; i<6; i++) { if (image[i] != NULL)   destroy_bitmap(image[i]); }
    
    if (buffer != NULL)                destroy_bitmap(buffer);
}
