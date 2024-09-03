#include "hole.h"   //aggregation, all headers are defined in it

class ball {
        int initx, inity, currx, curry, xspeed, yspeed, height, width; 
        BITMAP *image;
        BITMAP *balllost;
        BITMAP *buffer;
        BITMAP *score[6];
        BITMAP *gameover;
        BITMAP *win;
        SAMPLE *swing;
        int ball_left;
        int level;
        hole HOLE; //aggregation of hole class 
        
    public:
        ball(); //constructor to initialize attributes
        bool load_bitmap_and_sample();//used for exception handling
        void draw(int, int, int, int*, int*, bool);   
        int update_position(int); //move to next position
        int ball_lost();
        void speed(int);  //calculate speed  on the basis of direction
        ~ball(); //unload bitmap from memory
};
