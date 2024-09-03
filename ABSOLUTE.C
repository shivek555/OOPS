#include <stdio.h>

void main() {
 /*  int num,absolute_value,x;
    printf("Enter a number: ");
    scanf("%d", &num);

    absolute_value = num < 0 ? -num : num;

    printf("The absolute value of %d is %d.\n", num, absolute_value);
    scanf("%d",&x);
   */
   int year,x;
   printf("enter a year");;
   scanf("%d",&year);
   if (year%4==0)
   {
    printf("%d is a leap year",year);
   }
   else{printf("%d is not a leap year",year);}
   scanf("%d",&x);
}

/*
// Function to calculate the area of the triangle
float area_of_triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    return 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

// Function to determine if three points are colinear
int colinear_points(float x1, float y1, float x2, float y2, float x3, float y3) {
    float area = area_of_triangle(x1, y1, x2, y2, x3, y3);

    if (area == 0) {
	return 1; // Colinear
    } else {
	return 0; // Not colinear
    }
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point (x, y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x, y): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point (x, y): ");
    scanf("%d %d", &x3, &y3);

    if (colinear_points(x1, y1, x2, y2, x3, y3)) {
	printf("The points are colinear.\n");
    } else {
	printf("The points are not colinear.\n");
    }

    return 0;
}
     */