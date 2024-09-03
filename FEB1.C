#include <stdio.h>
#include <ctype.h>

int main() {
    char c;

    printf("Enter a character: ");
    scanf(" %c", &c);

    if (islower(c)) {
        printf("The character is in lower case.\n");
    } else if (isupper(c)) {
        printf("The character is in upper case.\n");
    } else {
        printf("The character is neither in lower case nor in upper case.\n");
    }

    return 0;
}