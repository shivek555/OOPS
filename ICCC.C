#include <stdio.h>

int main() {
    char ch,x;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	printf("%c is an alphabet.\n", ch);
    else
	printf("%c is not an alphabet.\n", ch);
    scanf("%d",&x);

    return 0;
}