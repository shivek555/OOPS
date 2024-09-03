// C program for the above approach 
#include <conio.h> 
#include <graphics.h> 
#include <stdio.h> 

// Driver Code 
void main() 
{ 
	int gd = DETECT, gm; 

	// Initialize of gdriver with 
	// DETECT macros 
	initgraph(&gd, &gm, "C:\\turboc3\\bgi"); 

	// Declared Variables 
	int a = 390, b = 390, c = 700; 

	// Left Side 
	// Lower Base 
	line(300, 1000, 450, 1000); 

	// Inside Decoration 
	line(300, 1000, 480, 940); 
	line(450, 1000, 330, 940); 

	// 1st Base 
	line(330, 940, 480, 940); 

	// Inside Decoration 
	line(330, 940, 510, 880); 
	line(480, 940, 360, 880); 

	// 2nd Base 
	line(360, 880, 510, 880); 

	// Inside Decoration 
	line(360, 880, 540, 820); 
	line(390, 820, 510, 880); 

	// 3rd Base 
	line(390, 820, 540, 820); 

	// Left Tangent 
	line(300, 1000, 390, 820); 

	// Right Tangent 
	line(450, 1000, 540, 820); 

	// Joining Line 
	line(390, 820, 810, 820); 

	// Half Circle 
	ellipse(600, 900, 15, 165, 90, 80); 

	// Right Side 
	// Lower Base 
	line(750, 1000, 900, 1000); 

	// Inside Decoration 
	line(750, 1000, 870, 940); 
	line(720, 940, 900, 1000); 

	// 1st Base 
	line(720, 940, 870, 940); 

	// Inside Decoration 
	line(720, 940, 840, 880); 
	line(870, 940, 690, 880); 

	// 2nd Base 
	line(690, 880, 840, 880); 

	// Inside Decoration 
	line(690, 880, 810, 820); 
	line(840, 880, 660, 820); 

	// 3rd Base 
	line(660, 820, 810, 820); 

	// Left Tangent 
	line(750, 1000, 660, 820); 

	// Right Tangent 
	line(900, 1000, 810, 820); 

	// Rectangles For Decoration 
	rectangle(390, 800, 810, 820); 
	rectangle(380, 780, 820, 800); 
	rectangle(390, 760, 810, 780); 

	// Triangle Decoration 
	while (a <= 790) { 
		line(a, 820, a + 10, 800); 
		line(a + 10, 800, a + 20, 820); 
		a = a + 20; 
	} 

	// Vertical Line Decoration 
	while (b <= 810) { 
		line(b, 760, b, 780); 
		b = b + 20; 
	} 

	// Left Side 
	// Upper Base 
	line(410, 760, 530, 760); 

	// Inside Decoration 
	line(410, 760, 560, 700); 
	line(530, 760, 440, 700); 

	// 1st Base 
	line(440, 700, 560, 700); 

	// Inside Decoration 
	line(440, 700, 590, 640); 
	line(560, 700, 470, 640); 

	// 2nd base 
	line(470, 640, 590, 640); 

	// Left Tangent 
	line(410, 760, 470, 640); 

	// Right Tangent 
	line(540, 760, 590, 640); 

	// Right Side 
	// Upper Base 
	line(670, 760, 790, 760); 

	// Inside Decoration 
	line(670, 760, 760, 700); 
	line(790, 760, 640, 700); 

	// 1st Base 
	line(640, 700, 760, 700); 

	// Inside Decoration 
	line(640, 700, 730, 640); 
	line(760, 700, 610, 640); 

	// 2nd Base 
	line(610, 640, 730, 640); 

	// Left Tangent 
	line(670, 760, 610, 640); 

	// Right Tangent 
	line(790, 760, 730, 640); 

	// Joining Line 
	line(470, 640, 730, 640); 

	// Rectangle For Decoration 
	rectangle(460, 620, 740, 640); 
	rectangle(470, 600, 730, 620); 

	// Redeclaring Variable 
	b = 470; 

	// Vertical Line Decoration 
	while (b <= 730) { 
		line(b, 600, b, 620); 
		b = b + 10; 
	} 

	// Redeclaring Variable 
	a = 600; 
	b = 500; 

	// Middle Line 
	line(600, 600, 600, 140); 

	// Upper Most Decoration 
	while (b >= 240) { 
		if (b == c) 
			break; 
		else { 
			line(b, a, c, a); 
			line(b, a, c - 10, a - 40); 
			line(b + 10, a - 40, c, a); 
			a = a - 40; 
			b = b + 10; 
			c = c - 10; 
		} 
	} 

	// Tangent Lines 
	line(500, 600, 590, 240); 
	line(700, 600, 610, 240); 
	rectangle(590, 200, 610, 240); 

	// Holding The Screen For A While 
	getch(); 

	// Close the initialized gdriver 
	closegraph(); 
} 
