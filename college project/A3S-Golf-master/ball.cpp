#include "ball.h"

//Initializes all variables to zero. 
//and create buffer bitmap
ball::ball() {
    
    initx= inity= currx= curry= xspeed= yspeed= height= width= 0;  
    buffer = create_bitmap(640, 480); 
}

//Load sound in the memory. Load the bitmap in the memory.
//Set height and width variable according to dimensions of bitmap.
bool ball::load_bitmap_and_sample() {
    
    char s[20];
    
    sprintf(s, "bitmaps\\ball.bmp");
    image = load_bitmap(s,NULL);
    if (!image) { allegro_message("ball bitmap not found"); return 0; }
    
    sprintf(s, "bitmaps\\balllost.bmp");
    balllost = load_bitmap(s,NULL);
    if (!balllost) { allegro_message("ball lost bitmap not found"); return 0; }
    
    sprintf(s, "bitmaps\\gameover.bmp");
    gameover = load_bitmap(s,NULL);
    if (!gameover) { allegro_message("game over bitmap not found"); return 0; }
    
    sprintf(s, "bitmaps\\win.bmp");
    win = load_bitmap(s,NULL);
    if (!win) { allegro_message("win bitmap not found"); return 0; }
    
    sprintf(s, "music\\swing.wav");
    swing = load_sample(s);
    if (!swing) { allegro_message("swing wav not found"); return 0; }
          
    //load score bitmaps
    for(int i=0; i<6; i++) {
        sprintf(s,"bitmaps\\score%d.bmp", i);
        score[i]=load_bitmap(s, NULL);
        if (!score[i]) { allegro_message("score bitmap not found"); return 0; }    
    }
    
    height= image->h; //cannot put in constructor segmentation fault occurs
    width = image->w;
    HOLE.load_bitmap_and_sample(); //load hole bitmaps     
    return 1;
}

//Unload the bitmap from the memory. Unload sound from memory.    
ball::~ball() {
   
     if (image !=NULL)         destroy_bitmap(image); 
    
    if (swing !=NULL)         destroy_sample(swing);
    
    if (balllost !=NULL)      destroy_bitmap(balllost); 
    
    if (gameover !=NULL)      destroy_bitmap(gameover); 
    
    if (win !=NULL)           destroy_bitmap(win);  
    
    if (buffer !=NULL)        destroy_bitmap(buffer);
    
    for (int i=0; i<6; i++) {
        if (score[i]!= NULL)  destroy_bitmap (score[i]);                }
}
        
//Set variables of initial and current position to values of arguments passed.
//Draw the bitmap of the ball on the buffer at position passed as arguments.
//Set pointers value with respect to ball dimensions.     
void ball::draw(int lvl, int x, int y, int *ptr1, int *ptr2, bool new_game) {
    
    HOLE.draw();
    if (x != -1 && y != -1)/*when called after update position*/ 
        { initx = x;    inity = y; }
    
    if (new_game) { //draw whats on screen on a bitmap 
        blit(screen, buffer, 0, 0, 0, 0, 640, 480);     
        level = lvl;
        ball_left = level+2;                                } 
    
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    
    draw_sprite(screen, score[ball_left--], 0, 0);//lvl 1 -> 3chances and so on
    draw_sprite(screen, image, initx, inity);   //draw ball
    *ptr1 = initx-10; *ptr2 = inity+20;  //adhusted pos of meter          
}

//Set variables of speed according to direction variable. using switch
void ball::speed(int choice) {
    switch (choice) {
        case 64:   xspeed = 10;  yspeed = 0;   break;//E   
        case 32:   xspeed = 7;   yspeed = -7;  break;//NE
        case 0:    xspeed = 0;   yspeed = -10; break;//N
        case -32:  xspeed = -7;  yspeed = -7;  break;//NW
        case -64:  xspeed = -10; yspeed = 0;   break;//W
        case -96:  xspeed = -7;  yspeed = 7;   break;//SW
        case -128: xspeed = 0;   yspeed = 10;  break;//S
        case 96:   xspeed = 7;   yspeed = 10;  break; //SE
        default:   xspeed = 30;  yspeed = 30;            }
}

// -2 -> hole  -1 -> all chances are over  0 -> ball lost   1 -> successful
int ball::update_position(int value) {
    play_sample(swing, VOLUME, PANNING, PITCH, TRUE);
    rest(100);
    stop_sample(swing);
    currx = initx;    curry = inity;
    for (int i=0; i<value-50; i+=5) { //without -50 level 3 was not working properly impossible to hit condition
        currx+=xspeed;    curry+=yspeed;
        blit(buffer, screen, 0, 0, 0, 0, 640, 480);
        draw_sprite(screen, image, currx, curry);
        if(HOLE.is_inside(currx,  curry, currx+width, curry+height)) { //birdie
                blit(buffer, screen, 0, 0, 0, 0, 640, 480);
                draw_sprite(screen, image, 60, 60); //draw ball inside hole
                blit(win, screen, 0, 0, 0, 0, 640, 480); 
                rest(2500);
                return -2;         
        }
        //check for ball in water for level 1
        if (level == 1) {
            if (!(((curry > 15 && curry<156) && (currx >16 && currx<615)) || ((curry > 156 && curry<460) && (currx >475 && currx<615)))) {
                return(ball_lost());   }            
        }    
        //for level 2
        else if (level == 2) {
            if (!((((curry>15&&curry<120)||(curry>360&&curry<465)) && (currx>23&&currx<617))   ||   ((curry>120&&curry<360)&&(currx>430&&currx<617)))) {
                return(ball_lost()); }
        }
        //for level 3
        else if (level == 3) {
            if (!((((curry>15&&curry<110)||(curry>380&&curry<450)) && (currx>22&&currx<618))   ||   ((curry>110&&curry<380)&&(currx>498&&currx<618))   ||   ((curry>140&&curry<380)&&(currx>22&&currx<110)))) {
                return(ball_lost()); }
        }
        
        rest(260-value); //rest before repeating loop
    }
    
    initx = currx;        inity = curry;
    if (ball_left < 0)    { draw_sprite(screen, gameover, 0, 0); rest(2500); return -1;} //All chances are over
    
    return 1; //successful
}  

int ball::ball_lost() {
    //ball lost
    rectfill(screen, 0, 0, 640, 480, 0);
    draw_sprite(screen, balllost, 0, 0);
    rest(1000);
    
    if (ball_left < 0){
        blit(gameover, screen, 0, 0, 0, 0, 640, 480); 
        rest(1500); 
        return -1; //All chances are over
    } 
     
    return 0;
}
