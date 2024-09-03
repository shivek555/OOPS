#include <stdio.h>

int main() {
    char str[100];
    int i,alphaCount = 0, digitCount = 0, specCount = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; str[i]!= '\0'; i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            alphaCount++;
        else if(str[i] >= '0' && str[i] <= '9')
            digitCount++;
        else
            specCount++;
    }

    printf("Total number of alphabets: %d\n", alphaCount);
    printf("Total number of digits: %d\n", digitCount);
    printf("Total number of special characters: %d\n", specCount);

    return 0;
}