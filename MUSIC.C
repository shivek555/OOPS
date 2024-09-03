#include <stdio.h>
#include <stdlib.h>

int main() {
char *buffer ;
  long size ;
  // Open the music file
  FILE *fp = fopen("Dil Ko Tujhpe Pyaar Vishal Mishra(MixJio.In).mp3", "rb");
  if (fp == NULL) {
    printf("Error opening music file\n");
    return 1;
  }

  // Get the file size
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // Allocate a buffer to store the music data
 buffer = malloc(size);
  if (buffer == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  // Read the music data into the buffer
  fread(buffer, 1, size, fp);

  // Close the music file
  fclose(fp);

  // Play the music data
  printf("Playing music...\n");
  system("aplay music.mp3");

  // Free the buffer
  free(buffer);

  return 0;
}