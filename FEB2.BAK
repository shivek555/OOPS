// C program for the above approach
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void outline()
{
	int u = 400;

	// Storing Box Outline
	rectangle(700, 300, 1000, 900);

	// Vertical Lines To Make
	// Divisions
	line(800, 300, 800, 900);
	line(900, 300, 900, 900);

	// Making Horizontal Line Using
	// While Function
	while (u <= 900) {
		line(700, u, 1000, u);
		u = u + 100;
	}

	// Printing The Instruction
	// On Screen
	settextstyle(10, 0, 3);
	outtextxy(20, 100, "FOR MOVE LEFT PRESS 'l'");
	outtextxy(20, 200, "FOR MOVE RIGHT PRESS 'r'");
	outtextxy(20, 300, "FOR MOVE MIDDLE PRESS 'm'");
}

// Driver Code
void main()
{
	int gd = DETECT, gm;

	// Initialize of gdriver with
	// DETECT macros
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");

	// Declaring & Initialising Variables
	int a = 800, b = 50, c = 900, d = 150,
		x, left[10], right[10], mid[10],
		up = 5, low = 2, lb = 900, mb = 900,
		rb = 900, i = 0, j = 0, k = 0,
		score = 0, p;
	char z, str[3];

	// Calling outline() function
	outline();

	// Creating Infinite Loop To Make
	// Continuous Use OF Game
	while (1) {
		// Creating & Naming The
		// Brick Box
		settextstyle(8, 0, 2);
		outtextxy(800, 10, "Brick Box");
		rectangle(a, b, c, d);

		// Generating Random Color Number
		x = (rand() % (up - low + 1)) + low;
		setfillstyle(SOLID_FILL, x);
		floodfill(a + 5, d - 5, 15);

		// Getting Input To Move Bricks
		z = getch();

		// Operations For Place The Bricks
		// In Left Side
		if (z == 'l') {
			// Creating & Naming The Left
			// Sub-Box
			settextstyle(8, 0, 2);
			outtextxy(630, 10, "Left Sub-Box");

			rectangle(a - 150, b, c - 150, d);
			floodfill(a - 55, d - 5, 15);
			delay(200);
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(a - 55, d - 5, 15);
			rectangle(a - 100, lb - 100,
					c - 100, lb);
			setfillstyle(SOLID_FILL, x);
			floodfill(a - 5, lb - 5, 15);
			delay(200);

			// Decreasing The Base Of
			// Left Side
			lb = lb - 100;

			// Storing Corresponding Color
			// In Left[] Array
			left[i] = x;
			i++;

			// Process To Check Is There Any
			// Matching In The Left Side By
			// Upside Down
			if (left[0] == left[1]) {
				lb = 900;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a - 5, lb - 5, 15);
				floodfill(a - 5, lb - 105, 15);
				score = score + 10;
				i = 0;
				left[1] = 0;
			}
			else if (left[1] == left[2]) {
				lb = 800;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a - 5, lb - 5, 15);
				floodfill(a - 5, lb - 105, 15);
				score = score + 10;
				i = 1;
				left[2] = 0;
			}
			else if (left[2] == left[3]) {
				lb = 700;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a - 5, lb - 5, 15);
				floodfill(a - 5, lb - 105, 15);
				score = score + 10;
				i = 2;
				left[3] = 0;
			}
			else if (left[3] == left[4]) {
				lb = 600;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a - 5, lb - 5, 15);
				floodfill(a - 5, lb - 105, 15);
				score = score + 10;
				i = 3;
				left[4] = 0;
			}
			else if (left[4] == left[5]) {
				lb = 500;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a - 5, lb - 5, 15);
				floodfill(a - 5, lb - 105, 15);
				score = score + 10;
				i = 4;
				left[5] = 0;
			}
			else
				p = 0;

			// Loop Breaking Condition For
			// Left Side
			if (lb < 400)
				break;
		}

		// Operations For Place The Bricks
		// In Right Side
		else if (z == 'r') {
			// Creating & Naming The Left
			// Sub-Box
			settextstyle(8, 0, 2);
			outtextxy(970, 10, "Right Sub-Box");

			rectangle(a + 150, b, c + 150, d);
			floodfill(a + 155, d - 5, 15);
			delay(200);
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(a + 155, d - 5, 15);
			rectangle(a + 100, rb - 100,
					c + 100, rb);
			setfillstyle(SOLID_FILL, x);
			floodfill(a + 105, rb - 5, 15);
			delay(200);

			// Decreasing The Base Of
			// Right Side
			rb = rb - 100;

			// Storing Corresponding Color
			// In Right[] Array
			right[j] = x;
			j++;

			// Process to Check Is There Any Matching
			// In The Right Side By Upside Down
			if (right[0] == right[1]) {
				rb = 900;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 105, rb - 5, 15);
				floodfill(a + 105, rb - 105, 15);
				score = score + 10;
				j = 0;
				right[1] = 0;
			}
			else if (right[1] == right[2]) {
				rb = 800;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 105, rb - 5, 15);
				floodfill(a + 105, rb - 105, 15);
				score = score + 10;
				j = 1;
				right[2] = 0;
			}
			else if (right[2] == right[3]) {
				rb = 700;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 105, rb - 5, 15);
				floodfill(a + 105, rb - 105, 15);
				score = score + 10;
				j = 2;
				right[3] = 0;
			}
			else if (right[3] == right[4]) {
				rb = 600;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 105, rb - 5, 15);
				floodfill(a + 105, rb - 105, 15);
				score = score + 10;
				j = 3;
				right[4] = 0;
			}
			else if (right[4] == right[5]) {
				rb = 500;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 105, rb - 5, 15);
				floodfill(a + 105, rb - 105, 15);
				score = score + 10;
				j = 4;
				right[5] = 0;
			}
			else
				p = 0;

			// Loop Breaking Condition For
			// Right Side
			if (rb - 100 < 300)
				break;
		}

		// Operations For Place The Bricks
		// In Middle Side
		else {
			rectangle(a, mb - 100, c, mb);
			floodfill(a + 5, mb - 5, 15);
			delay(200);

			// Decreasing The Base Of
			// Middle Side
			mb = mb - 100;

			// Storing Corresponding Color In
			// Mid[] Array
			mid[k] = x;
			k++;

			// Process To Check Is There Any
			// Matching In The Middle Side
			// By Upside Down
			if (mid[0] == mid[1]) {
				mb = 900;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 5, mb - 5, 15);
				floodfill(a + 5, mb - 105, 15);
				score = score + 10;
				k = 0;
				mid[1] = 0;
			}
			else if (mid[1] == mid[2]) {
				mb = 800;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 5, mb - 5, 15);
				floodfill(a + 5, mb - 105, 15);
				score = score + 10;
				k = 1;
				mid[2] = 0;
			}
			else if (mid[2] == mid[3]) {
				mb = 700;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 5, mb - 5, 15);
				floodfill(a + 5, mb - 105, 15);
				score = score + 10;
				k = 2;
				mid[3] = 0;
			}
			else if (mid[3] == mid[4]) {
				mb = 600;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 5, mb - 5, 15);
				floodfill(a + 5, mb - 105, 15);
				score = score + 10;
				k = 3;
				mid[4] = 0;
			}
			else if (mid[4] == mid[5]) {
				mb = 500;
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(a + 5, mb - 5, 15);
				floodfill(a + 5, mb - 105, 15);
				score = score + 10;
				k = 4;
				mid[5] = 0;
			}
			else
				p = 0;

			// Loop Breaking Condition For
			// Middle Side
			if (mb - 100 < 300)
				break;
		}

		// Time Delay
		delay(200);

		// Display Score Whenever There Is
		// Any Match
		sprintf(str, "%d", score);
		outtextxy(100, 600, "SCORE: ");
		outtextxy(100, 700, str);
	}

	// Time Delay
	delay(500);

	// Clearing The Screen When Game
	// Is Over
	cleardevice();

	// Holding screen for a while
	getch();

	// Close the initialized gdriver
	closegraph();
}
