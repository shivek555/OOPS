#include "graphics.h"

//intialize count
graphics::graphics() {count = 0;}

//Load bitmaps in memory.	Load sound in memory 
bool graphics::load_bitmap_and_sample() {
    int i; //for loop count
    char s[20];
    
    gameexit = load_bitmap("bitmaps\\gameexit.bmp",NULL);
    if (!gameexit) { allegro_message("gameexit bitmap not found");  return 0; }
    
    pause = load_bitmap("bitmaps\\pause.bmp",NULL);
    if (!pause) { allegro_message("pause bitmap not found");        return 0; }
    
    for(i=0; i<3; i++) {
        sprintf(s,"music\\a3s%d.wav", i+1);
        sound[i] = load_sample(s);
        if (!sound[i]) { allegro_message("sound wav not found");    return 0; }                
    }
    
    for(i=0; i<3; i++) {
        sprintf(s,"bitmaps\\ia3s%d.bmp", i+1);
        intro[i]=load_bitmap(s, NULL);
        if (!intro[i]) { allegro_message("Intro bitmap not found"); return 0; }    
    }
    
    for(i=0; i<3; i++) {
        sprintf(s,"bitmaps\\aground%d.bmp", i+1);
        ground[i]=load_bitmap(s, NULL);   
        if (!ground[i]) { allegro_message("ground bitmap not found");return 0;} 
    }
    
    for(i=0; i<3; i++) {
        sprintf(s,"bitmaps\\main%d.bmp", i+1);
        menu[i]=load_bitmap(s, NULL);
        if (!menu[i]) { allegro_message("menu bitmap not found");    return 0;}    
    }           
    
    return 1; //successful
}

//Unload all bitmaps and sound from memory.
graphics::~graphics() {
    int i;
    
    if (gameexit != NULL)       destroy_bitmap(gameexit);
    
    if (pause != NULL)          destroy_bitmap(pause);
    
    for(i=0; i<3; i++) {
        if (sound[i] != NULL)   destroy_sample(sound[i]);              }
    
    for(i=0; i<3; i++) {
        if (intro[i] != NULL)   destroy_bitmap(intro[i]);               }    
    
    for(i=0; i<3; i++) {
        if (ground[i] != NULL)  destroy_bitmap(ground[i]);               }
    
    for(i=0; i<3; i++) {
        if (menu[i] != NULL)    destroy_bitmap(menu[i]);                 }                
}

//"	Draw bitmap of introductory screens. Play intro sounds and then stop. Rest for some time and the end function.
void graphics::Intro() {
    int i;
    for (i=0; i<3; i++) {
        play_sample(sound[0], VOLUME, PANNING, PITCH, TRUE);
        draw_sprite(screen, intro[i], 0, 0);
        rest(1000*i);
        stop_sample(sound[0]); 
        rectfill(screen, 0, 0, 640, 480, 0); /*to see it moving*/       }
    
    rest(1000);
}

//"	Draw main menu screen. Wait for user click on bitmap. Returns value accord. to option selected which is then stored in level variable.
int graphics::MainMenu() {
    int i;
    count++; //increment count of menu displaying
    
    draw_sprite(screen, menu[0], 0, 0);
    BITMAP *buffer = create_bitmap(640, 480); //instead if drawing all bitmaps just draw buffer
    
    //if funtion is already executed once, activate retry button in next call
    if (count > 1) {
        stop_sample(sound[2]); //stop course sound will work when retry is hit
        draw_sprite(screen, menu[1], 0, 0);          }
        
    blit(screen, buffer, 0, 0, 0, 0, 640, 480); //blitting after retry is activated
    play_sample(sound[1], VOLUME, PANNING, PITCH, TRUE); //play main menu sound
    show_os_cursor(2); //show cursor on screen
    while(1) {
        if(mouse_b & 1) {
            if ((mouse_x>146 && mouse_x<440)&&(mouse_y>175 && mouse_y<245)) {
                        draw_sprite(screen, menu[2], 0, 0); //level select sprite
                        rest(100); //needed otherwise echo will cause problems
                        while(!mouse_b){} 
                        if (mouse_b & 1) {
                            if ((mouse_x>460 && mouse_x<507)&&(mouse_y>180 && mouse_y<227))
                                return 1;  
                            else if ((mouse_x>510 && mouse_x<557)&&(mouse_y>180 && mouse_y<227))
                                return 2;
                            else if ((mouse_x>560 && mouse_x<607)&&(mouse_y>180 && mouse_y<227))                                                   
                                return 3;
                        }
            }    
            else if ((mouse_x>210 && mouse_x<380)&&(mouse_y>255 && mouse_y<330)) {    
                            if (count > 1) //not allowed to retry in start            
                                return -1;            
            }
            
            else if ((mouse_x>225 && mouse_x<355)&&(mouse_y>340 && mouse_y<405)) {
                        if(!game_exit()) //in case of quit
                            return 0;                    
                        else 
                            continue;                           
            }  
        }
        blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    }    
}

//"	Draw course based on the variable of level (set by main menu function).	Play music.	Set pointers to some values based on course.
void graphics::course(int level, int* x, int* y) {
    stop_sample(sound[1]); //stop menu sound
    draw_sprite(screen, ground[level-1], 0, 0);
    draw_sprite (screen, pause, 0, 0);
    stop_sample(sound[2]); //use in transition from one level to another
    play_sample(sound[2], VOLUME, PANNING, PITCH, TRUE);
         
         if (level == 1) {*x = 542; *y = 410;}
    else if (level == 2) {*x = 48;  *y = 403;}
    else if (level == 3) {*x = 54;  *y = 135;}
}

//"	Draw game over screen. wait for usr answer return value acc. to option
int graphics::game_exit() {
    rest(100);
    draw_sprite(screen, gameexit, 0, 0);
    show_os_cursor(2);
    while(1) {
        if (mouse_b & 1) {
            if ((mouse_x>270 && mouse_x<335)&&(mouse_y>290 && mouse_y<330)) {           
            //game over
                return 0;             }
            //game continue i.e NO
            if ((mouse_x>275 && mouse_x<335)&&(mouse_y>345 && mouse_y<388)) {
                rest (100);
                return 1;            }
        }  
    }     
}
