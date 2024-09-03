#include <stdio.h>
#include <ctype.h>

int main() {
    char ch,x;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (isalpha(ch))
	printf("%c is an alphabet.\n", ch);
    else if (isalnum(ch))
	printf("%c is a number.\n", ch);
    else if (isprint(ch))
	printf("%c is a special character.\n", ch);
    else
	printf("%c is not a printable character.\n", ch);
    scanf("%d",&x);
    return 0;
}