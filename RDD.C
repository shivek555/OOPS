#include <stdio.h>
#include <string.h>

char* removeDuplicate(char str[], int n)
{
    // Used as an index in the modified string
    int j,i,index = 0;

    // Traverse through all characters
    for (i = 0; i < n; i++) {
	// Check if str[i] is present before it

	for (j = 0; j < i; j++) {
	    if (str[i] == str[j])
		break;
	}

	// If not present, then add it to the result.
	if (j == i)
	    str[index++] = str[i];
    }

    // Add null character at the end to terminate the string
    str[index] = '\0';

    return str;
}

// Driver code
int main()
{
    char str[] = "the new way ";
    int n = sizeof(str) / sizeof(str[0]);
    printf("%s\n", removeDuplicate(str, n));
    return 0;
}
