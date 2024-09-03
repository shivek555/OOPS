#include <stdio.h>
#include <string.h>

int main() {
    char paragraph[1000];
    int lines = 0, words = 0, characters = 0;
    int i = 0;

    printf("Enter a paragraph:\n");
    gets(paragraph);

    while (paragraph[i]!= '\0') {
        if (paragraph[i] == '\n') {
            lines++;
        }
        if (paragraph[i]!= ' ' && (i == 0 || paragraph[i - 1] == ' ')) {
            words++;
        }

        if (paragraph[i]!= ' ' && paragraph[i]!= '\n' && paragraph[i]!= '\t') {
            characters++;
        }

        i++;
    }

    // Increase the line count by 1 if the last character is not a newline
    if (paragraph[i - 1]!= '\n') {
        lines++;
    }

    printf("\nNumber of characters: %d", characters);
    printf("\nNumber of words: %d", words);
    printf("\nNumber of lines: %d\n", lines);

    return 0;
}