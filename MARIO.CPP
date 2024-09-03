// mario_game.cpp

#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define CHARACTER_WIDTH 20
#define CHARACTER_HEIGHT 20

// Game variables
int character_x = SCREEN_WIDTH / 2;
int character_y = SCREEN_HEIGHT / 2;
int character_speed = 5;
int jump_height = 10;
int gravity = 1;

// Game functions
void draw_character(int x, int y) {
    // Draw a simple character using ASCII art
    printf("\x1B[%d;%dH", y, x);
    printf(" /_/\\ ");
    printf("\x1B[%d;%dH", y + 1, x);
    printf("( o.o )");
    printf("\x1B[%d;%dH", y + 2, x);
    printf(" > ^ < ");
}

void update_character() {
    // Update character position based on user input
    if (kbhit()) {
        char c = getch();
        if (c == 'a' || c == 'A') {
            character_x -= character_speed;
        } else if (c == 'd' || c == 'D') {
            character_x += character_speed;
        } else if (c == 'w' || c == 'W') {
            character_y -= jump_height;
        }
    }

    // Apply gravity
    character_y += gravity;

    // Ensure character stays within screen bounds
    if (character_x < 0) character_x = 0;
    if (character_x > SCREEN_WIDTH - CHARACTER_WIDTH) character_x = SCREEN_WIDTH - CHARACTER_WIDTH;
    if (character_y < 0) character_y = 0;
    if (character_y > SCREEN_HEIGHT - CHARACTER_HEIGHT) character_y = SCREEN_HEIGHT - CHARACTER_HEIGHT;
}

int main() {
    // Initialize graphics mode
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

    // Set screen dimensions
    setviewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 1);

    // Game loop
    while (!kbhit()) {
        // Clear screen
        cleardevice();

        // Draw character
        draw_character(character_x, character_y);

        // Update character position
        update_character();

        // Delay to control frame rate
       // delay(50);
    }

    // Close graphics mode
    closegraph();

    return 0;
}