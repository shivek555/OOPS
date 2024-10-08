#include <stdio.h>
#include <math.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    int binary[100];
    int i = 0;
    int j;
    while (decimal!= 0) {
	binary[i++] = decimal % 2;
	decimal /= 2;
    }
    printf("Decimal %d in binary: ", decimal);
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Function to convert binary to decimal
int binary_to_decimal(int binary) {
    int decimal = 0, i = 0, rem;
    while (binary!= 0) {
        rem = binary % 10;
        binary /= 10;
        decimal += rem * pow(2, i);
        i++;
    }
    return decimal;
}

// Function to convert decimal to octal
void decimal_to_octal(int decimal) {
int j;
    int octal[100];
    int i = 0;
    while (decimal!= 0) {
	octal[i++] = decimal % 8;
	decimal /= 8;
    }
    printf("Decimal %d in octal: ", decimal);
    for (j = i - 1; j >= 0; j--) {
	printf("%d", octal[j]);
    }
    printf("\n");
}

// Function to convert octal to decimal
int octal_to_decimal(int octal) {
    int decimal = 0, i = 0, rem;
    while (octal!= 0) {
	rem = octal % 10;
	octal /= 10;
	decimal += rem * pow(8, i);
	i++;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int decimal) {
    int hexadecimal[100];
    int i = 0;
    int j;
    while (decimal!= 0) {
        hexadecimal[i++] = decimal % 16;
        decimal /= 16;
    }
    printf("Decimal %d in hexadecimal: ", decimal);
    for (j = i - 1; j >= 0; j--) {
        if (hexadecimal[j] < 10) {
            printf("%d", hexadecimal[j]);
        } else {
            printf("%c", 'A' + hexadecimal[j] - 10);
        }
    }
    printf("\n");
}

// Function to convert hexadecimal to decimal
int hexadecimal_to_decimal(int hexadecimal) {
    int decimal = 0, i = 0, rem;
    int multiple = 1;
    while (hexadecimal!= 0) {
        rem = hexadecimal % 10;
        if (rem > 9) {
            rem -= 7;
        }
        hexadecimal /= 10;
        decimal += rem * multiple;
        multiple *= 16;
    }
    return decimal;
}

int main() {
    int choice;
    int number;

    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Decimal to Octal\n");
    printf("4. Octal to Decimal\n");
    printf("5. Decimal to Hexadecimal\n");
    printf("6. Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            decimal_to_binary(number);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Binary %d in decimal: %d\n", number, binary_to_decimal(number));
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            decimal_to_octal(number);
            break;
        case 4:
            printf("Enter an octal number: ");
            scanf("%d", &number);
            printf("Octal %d in decimal: %d\n", number, octal_to_decimal(number));
            break;
        case 5:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            decimal_to_hexadecimal(number);
            break;
        case 6:
            printf("Enter a hexadecimal number: ");
            scanf("%d", &number);
            printf("Hexadecimal %d in decimal: %d\n", number, hexadecimal_to_decimal(number));
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}