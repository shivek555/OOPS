#include <iostream>
#include <conio.h>
#include <dir.h>
#include <dos.h>
using namespace std;

void playSound(unsigned int frequency, unsigned int duration) {
    sound(frequency); // Set the frequency of the sound
    delay(duration); // Wait for the specified duration
    nosound(); // Turn off the sound
}

void listMusicFiles(const char* directory) {
    struct ffblk ffblk;
    int done;
    done = findfirst(directory, &ffblk, FA_ARCH);
    if (!done) {
        do {
            cout << ffblk.ff_name << endl;
        } while (!findnext(&ffblk));
    }
}

int main() {
    const char* musicDirectory = "C:\\Path\\To\\Your\\Music\\Directory\\*.mp3"; // Change this to your music directory
    listMusicFiles(musicDirectory);

    // Main loop to handle user input and play music
    char userInput;
    while (true) {
        cout << "Enter the name of the file you want to play or 'q' to quit: ";
        userInput = _getch();
        if (userInput == 'q' || userInput == 'Q') {
            break;
        }
        // Convert userInput to filename and play music
        string filename(1, userInput);
        cout << "Now playing: " << filename << endl;
        // Simulate playing music by generating a simple tone
        playSound(440, 1000); // Play a 440 Hz tone for 1 second
    }

    return 0;
}