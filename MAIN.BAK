#include "allegro.h"
#include <iostream>
#include "ball.h"
#include "graphics.h"
#include "speedometer.h"
using namespace std;

int main() {
    allegro_init();
    install_mouse();
    install_keyboard();
    set_color_depth(24);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
        allegro_message(allegro_error);
        return 1;            } 
    
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
        allegro_message("Error initializing sound system\n%s\n", allegro_error);
        return 1;        }
    
    int b_pos_x = 0, b_pos_y = 0, m_pos_x = 0, m_pos_y = 0;
    int ret = 1;
    int angle; //only 8 angle therefore integer
    int option, re_option;
    bool new_game = 0;
    int lvl;
    
    //making objects
    graphics INTERFACE;
    ball BALL;
    speedometer METER;
    
    //checking for exceptions
    if (!BALL.load_bitmap_and_sample())     return 1;
    if (!METER.load_bitmap_and_sample())    return 1;
    if (!INTERFACE.load_bitmap_and_sample())return 1;
    
    //this should be played once
    INTERFACE.Intro();
    
    //execute it for start 
    option = INTERFACE.MainMenu();
    if (option == 0) { //game over
        goto GAME_OVER;                 }
  
 RESTART: 
    rest(100); //for retrying game    
    lvl = option;    new_game = 1;
 NEXT_LEVEL:
    INTERFACE.course(lvl, &b_pos_x, &b_pos_y);
    
    //GAME LOOP
    while (1) {
        //every time either update function or pause is executed and or ball is lost
        BALL.draw(lvl, b_pos_x, b_pos_y, &m_pos_x, &m_pos_y, new_game);
        METER.draw(m_pos_x, m_pos_y);
        angle = METER.direct();
    
        //IN GAME-MENU i.e p is pressed
        if (angle == -1) {
            MENU:
            re_option = INTERFACE.MainMenu(); 
            if (re_option == -1){      //retry      
                goto RESTART;            } 
            else if (re_option == 0) { //game over
                goto GAME_OVER;               }
            else if (re_option > 0) { //new game 
                option = lvl = re_option;
                new_game = 1;
                INTERFACE.course(lvl, &b_pos_x, &b_pos_y);
                continue;            }
        }
            
        BALL.speed(angle);
        ret = BALL.update_position(METER.fill_up()); //returns 0 at ball lost
        if (ret == 1) {b_pos_x = b_pos_y = -1;} //successfully updated
        else if (ret == -1) //all chances are over
                goto MENU;        
        else if (ret == -2) { //level is done
                lvl++;
                if (lvl > 3)        goto RESTART; //after level 3 load main menu
                new_game = 1; 
                goto NEXT_LEVEL;          }
        new_game = 0;
        continue;
    }     

GAME_OVER:
    return 0;
}
END_OF_MAIN() 
