#include "hole.h"

//initialize other variables.
hole::hole() { x = y = 60; } 

//Load bitmap in memory. and  Load sound in memory.
bool hole::load_bitmap_and_sample() {
    
    image = load_bitmap("bitmaps\\hole.bmp",NULL);
    if (!image) { allegro_message("hole bitmap not found");  return 0; }
    
    clap = load_sample("music\\clap.wav");
    if (!clap) { allegro_message("clap wav not found");      return 0; }
}

//draw hole
void hole::draw() { draw_sprite(screen, image, x, y); }

//Compare values of position constants and variable passed. 
//Play a sound and Returns 1 on success
int hole::is_inside(int x1,int y1, int x2, int y2) {
    if ((x1 >=30 && x2 <=90) && (y1 >=30 && y2 <= 90)) { //our hole is at (60, 60)
        play_sample(clap, VOLUME, PANNING, PITCH, TRUE);
        rest(100);
        stop_sample(clap);
        return 1;        } 
    else 
        return 0;       
}

//"	Unload bitmap from memory Unload sound from memory.
hole::~hole()  { if (image != NULL)   destroy_bitmap(image); }
