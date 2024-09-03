#include<stdio.h>
int main()
{
    char x;
    printf("enter a alplabet: ");
    scanf("%c",&x);
    switch(x)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        printf("%c is a vowel",x); break;
        default:
        printf("%c is a consonant",x); break;
    }
    return 0;
}