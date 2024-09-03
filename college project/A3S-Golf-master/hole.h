#include "allegro.h"
#include <iostream>
#define PANNING 128     //variables needed for sound
#define PITCH 1000
#define VOLUME 128
using namespace std;

class hole {
    int x, y; 
    BITMAP *image;
    SAMPLE *clap;
    public:
        hole(); 
        bool load_bitmap_and_sample();
        void draw();
        int is_inside(int, int, int, int);
        ~hole();
};
