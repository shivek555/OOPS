#include <stdio.h>

int main()
{
    char c, *cp;

    printf("Enter a character: ");
    scanf("%c", &c);

    /* Referencing */
    cp = &c;

    if(*cp >= 'a' && *cp <= 'z')
    {
        *cp = *cp - 32; /* Convert lowercase to uppercase */
    }
    else if(*cp >= 'A' && *cp <= 'Z')
    {
        *cp = *cp + 32; /* Convert uppercase to lowercase */
    }

    printf("The changed character is: %c\n", *cp);

    return 0;
}