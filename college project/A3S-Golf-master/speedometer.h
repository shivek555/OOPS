#include "allegro.h"
#include <iostream>
#define PANNING 128     //variables needed for sound
#define PITCH 1000
#define VOLUME 128
using namespace std;

class speedometer {
        int angle, x, y; //angle for direction and x y for position
        BITMAP *image[6]; //for meter images
        BITMAP *buffer; //secondry screen to copy all contents of screen before displaying meter
    public:
        speedometer();
        bool load_bitmap_and_sample();
        void draw(int, int);
        int fill_up();
        int direct();
        ~speedometer();
};
