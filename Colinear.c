#include <stdio.h>
/*
// Function to check collinearity using ab + bc = ac
int areCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    int result = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    return result == 0;
}

int main() {
    // Input coordinates
    int x1, y1, x2, y2, x3, y3;

    // Get input from user
    printf("Enter coordinates of point 1 (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter coordinates of point 2 (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter coordinates of point 3 (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Check collinearity
    if (areCollinear(x1, y1, x2, y2, x3, y3)) {
        printf("Points are collinear.\n");
    } else {
        printf("Points are not collinear.\n");
    }

    return 0;
}*/


// Function to check collinearity
int areCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    // Calculate slopes
    float slope1 = (float)(y2 - y1) / (x2 - x1);
    float slope2 = (float)(y3 - y2) / (x3 - x2);

    // Check if slopes are equal
    return slope1 == slope2;
}

int main() {
    // Input coordinates
    int x1, y1, x2, y2, x3, y3;

    // Get input from user
    printf("Enter coordinates of point 1 (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter coordinates of point 2 (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter coordinates of point 3 (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Check collinearity
    if (areCollinear(x1, y1, x2, y2, x3, y3)) {
        printf("Points are collinear.\n");
    } else {
        printf("Points are not collinear.\n");
    }

    return 0;
}