//WAP TO USE A FUNCTION TO SWAP VALUE OF TWO VARIABLE
//WAP TO FIND LARGEST OF THREE NUMBERS USING FUNCTION 
//WAP TO CONVERT TIME TO MINUTES USING FUNCTION
//WAP CALCULATOR OPERATIONS USING FUNCTIONS
//WAP TO SUM THE SERIES (1/1!+1/2!---------1/n!)
//WAP TO FUNCTION TO TELL WHICH MONTH IS UPON ENTERING THE INTEGER VALUE OF MONTH
#include <stdio.h>
/*
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x,y;
printf("enter number 1:");
scanf("%d",&x);
printf("enter number 2:");
scanf("%d",&y);
    printf("Before swapping: x = %d, y = %d\n", x, y);

    // calling swap function
    swap(&x, &y);

    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
}
*/
/*
int findLargest(int a, int b, int c) {
    if (a > b && a > c) {
	return a;
    } else if (b > a && b > c) {
	return b;
    } else {
	return c;
    }
}

int main() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("The largest number is: %d", findLargest(a, b, c));
    return 0;
}/*
int convert_to_minutes(int hours, int minutes) {
    return hours * 60 + minutes;
}

int main() {
    int hours, minutes;
    printf("Enter the number of hours: ");
    scanf("%d", &hours);
    printf("Enter the number of minutes: ");
    scanf("%d", &minutes);
    printf("The time in minutes is: %d", convert_to_minutes(hours, minutes));
    return 0;
}*/
/*
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
	printf("Error: Division by zero is not allowed.");
	return 0;
    }
    return a / b;
}

int main() {
    int num1, num2, choice;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter the operation (1. Addition, 2. Subtraction, 3. Multiplication, 4. Division): ");
    scanf("%d", &choice);
    switch (choice) {
	case 1:
	    printf("The sum of %d and %d is %d\n", num1, num2, add(num1, num2));
	    break;
	case 2:
	    printf("The difference between %d and %d is %d\n", num1, num2, subtract(num1, num2));
	    break;
	case 3:
	    printf("The product of %d and %d is %d\n", num1, num2, multiply(num1, num2));
	    break;
	case 4:
	    printf("The quotient of %d and %d is %d\n", num1, num2, divide(num1, num2));
	    break;
	default:
	    printf("Error: Invalid operation.");
    }
    return 0;
}

double calculate_series(int n) {
    double sum = 0;
    int i,fact,j;
    for (i = 1; i <= n; i++) {
	fact = 1;
	for (j = 1; j <= i; j++) {
	    fact *= j;
	}
	sum += 1.0 / fact;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The sum of the series is: %.4f\n", calculate_series(n));
    return 0;
}
const char* get_month_name(int month) {
    char* month_name;
    switch (month) {
	case 1:
	    month_name = "January";
	    break;
	case 2:
	    month_name = "February";
	    break;
	case 3:
	    month_name = "March";
	    break;
	case 4:
	    month_name = "April";
	    break;
	case 5:
	    month_name = "May";
	    break;
	case 6:
	    month_name = "June";
	    break;
	case 7:
	    month_name = "July";
	    break;
	case 8:
	    month_name = "August";
	    break;
	case 9:
	    month_name = "September";
	    break;
	case 10:
	    month_name = "October";
	    break;
	case 11:
	    month_name = "November";
	    break;
	case 12:
	    month_name = "December";
	    break;
	default:
	    month_name = "Invalid month number.";
    }
    return month_name;
}

int main() {
    int month;
    printf("Enter the number of a month: ");
    scanf("%d", &month);
    printf("The month is: %s\n", get_month_name(month));
    return 0;
} */

// practice 2
// WAP TO CREATE A PROGRAM TO CALC AREA OF TRIANGLE CIRCLE AND SQUARE AND TO CHECK WHO HAS HIGHEST PERIMETER USING FUNCTION
// WAP TO CREATE A PROGRAM TO PRINT GRADE OF A STUDENT AND TAKING MARKS AS INPUT USING FUNCTION
// WAP TO CREATE A FUNCTION THAT PRINTS FIBONACI SERIES
/*
#include <math.h>

// Function to calculate the area of a triangle
float calcTriangleArea(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to calculate the area of a circle
float calcCircleArea(float r) {
    return M_PI * pow(r, 2);
}

// Function to calculate the area of a square
float calcSquareArea(float a) {
    return pow(a, 2);
}

// Function to calculate the perimeter of a triangle
float calcTrianglePerimeter(float a, float b, float c) {
    return a + b + c;
}

// Function to calculate the perimeter of a square
float calcSquarePerimeter(float a) {
    return 4 * a;
}

// Function to calculate the perimeter of a circle
float calcCirclePerimeter(float r) {
    return 2 * M_PI * r;
}

int main() {
    float a, b, c, r, side,triPeri,triArea,cirArea,sqrArea,sqrPeri,cirPeri;
    printf("Enter the three sides of the triangle: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("Enter the radius of the circle: ");
    scanf("%f", &r);
    printf("Enter the side of the square: ");
    scanf("%f", &side);

    triArea = calcTriangleArea(a, b, c);
    cirArea = calcCircleArea(r);
    sqrArea = calcSquareArea(side);

    triPeri = calcTrianglePerimeter(a, b, c);
    sqrPeri = calcSquarePerimeter(side);
    cirPeri = calcCirclePerimeter(r);

    printf("Triangle Area:%.2f\n", triArea);
    printf("Circle Area: %.2f\n", cirArea);
    printf("Square Area: %.2f\n", sqrArea);

    printf("Triangle Perimeter: %.2f\n", triPeri);
    printf("Circle Perimeter: %.2f\n", cirPeri);
    printf("Square Perimeter: %.2f\n", sqrPeri);

    if (triPeri > sqrPeri && triPeri > cirPeri) {
	printf("Triangle has the highest perimeter.\n");
    } else if (sqrPeri > triPeri && sqrPeri > cirPeri) {
	printf("Square has the highest perimeter.\n");
    } else {
	printf("Circle has the highest perimeter.\n");
    }

    return 0;
}*/
   /*
char getGrade(int marks) {
    if (marks >= 90)
	return 'A';
    else if (marks >= 80)
	return 'B';
    else if (marks >= 70)
	return 'C';
    else if (marks >= 60)
	return 'D';
    else
	return 'F';
}

int main() {
    int marks;

    printf("Enter your marks: ");
    scanf("%d", &marks);

    printf("Your grade is %c\n", getGrade(marks));

    return 0;
}
#include <stdio.h>

void fibonacci(int n) {
    int i,num1 = 0, num2 = 1, nextNum;

    for (i = 0; i < n; i++) {
	printf("%d, ", num1);
	nextNum = num1 + num2;
	num1 = num2;
	num2 = nextNum;
    }
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}*/
//PRACTICE 3
#include <stdio.h>

int main()
{
    int a, b, c, *pa, *pb, *pc;


    pa= &a;
    pb= &b;
    pc= &c;
    printf("\nEnter three numbers:\n");
    scanf("%d%d%d", &a,&b,&c);
    if(*pa < *pb && *pa < *pc)
    {
	printf("Smallest is: %d\n", *pa);
	if (*pb<*pc){
	printf("LARGEST is: %d\n",*pc);
	}
	else{
	printf("LARGEST is: %d\n",*pb);
	}
    }
    else if(*pb < *pc && *pb < *pc)
    {
	printf("Smallest is: %d\n", *pb);
	if (*pa<*pc){
	printf("LARGEST is: %d\n",*pc);
	}
	else{
	printf("LARGEST is: %d\n",*pa);
	}
    }
    else
    {
	printf("Smallest is: %d\n", *pc);
	if (*pb<*pa){
	printf("LARGEST is: %d\n",*pa);
	}
	else{
	printf("LARGEST is: %d\n",*pb);
	}
    }
    return 0;
}