#include "allegro.h"
#include <iostream>
#define PANNING 128     //variables needed for sound
#define PITCH 1000
#define VOLUME 128
using namespace std;

class graphics {
    SAMPLE *sound[3];
    BITMAP *intro[3];
    BITMAP *menu[3];
    BITMAP *gameexit;
    BITMAP *pause; //to display pause message
    BITMAP *ground[3];
    int count;     //counts how many times main menu is executed helpful in activating retry button 
    public:
        graphics();
        bool load_bitmap_and_sample();
        void Intro();
        int MainMenu();
        void course(int, int*, int*);
        int game_exit();    
        ~graphics();
};
