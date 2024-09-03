#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>

union REGS i, o;
int left = 265, top = 250;

void initialize_graphics_mode()
{
  int gd = DETECT, gm, error;

  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  error = graphresult();

  if (error != grOk)
  {
    perror("Error ");
    printf("Press any key to exit...\n");
    getch();
    exit(EXIT_FAILURE);
  }
}

void showmouseptr()
{
  i.x.ax = 1;
  int86(0x33,&i,&o);
}

void hidemouseptr()
{
  i.x.ax = 2;
  int86(0x33,&i,&o);
}

void getmousepos(int *x,int *y)
{
  i.x.ax = 3;
  int86(0x33,&i,&o);

  *x = o.x.cx;
  *y = o.x.dx;
}

void draw_bar()
{
  hidemouseptr();
  setfillstyle(SOLID_FILL,CYAN);
  bar(190,180,450,350);
  showmouseptr();
}

void draw_button(int x, int y)
{
  hidemouseptr();
  setfillstyle(SOLID_FILL,MAGENTA);
  bar(x,y,x+100,y+30);
  moveto(x+5,y);
  setcolor(YELLOW);
  outtext("Press me");
  showmouseptr();
}
void draw_button1(int x1, int y1)
{
  hidemouseptr();
  setfillstyle(SOLID_FILL,WHITE);
  bar(x1,y1,x1+300,y1+80);
  setcolor(BLACK);
  outtextxy(x1,y1,"YOUR MOUSE IS ON BUTTON ");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(x1+280,55,"X");
  showmouseptr();
}

void draw()
{
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(100,451,"Project by Shivek S Mittal");
  setcolor(BLUE);
  rectangle(0,0,639,450);
  setcolor(RED);
  setfillstyle(XHATCH_FILL,GREEN);
  setcolor(BLUE);
  bar(1,1,75,449);
  bar(565,1,638,449);
  showmouseptr();
  draw_bar();
  draw_button(left,top);
}

void initialize()
{
  initialize_graphics_mode();

  if( !initmouse() )
  {
    closegraph();
    printf("Unable to initialize the mouse");
    printf("Press any key to exit...\n");
    getch();
    exit(EXIT_SUCCESS);
  }

  draw();
}

int initmouse()
{
  i.x.ax = 0;
  int86(0x33,&i,&o);
  return ( o.x.ax );
}

void get_input()
{
  int x, y;

  while(1)
  {
    getmousepos(&x,&y);

    /* mouse pointer in left of button */

    if( x >= (left) && y >= (top) && y <= (top+30) && x < (left+100) )
    {
     draw_button1(250,0);
     if(x>=(250+280)&& y>=(55)&&y<=80&&x<(250+300))
     {
      initialize_graphics_mode();
     }
    }
    if (kbhit())
    {
      if (getkey() == 1)
	exit(EXIT_SUCCESS);
    }
  }
}

int getkey()
{
  i.h.ah = 0;
  int86(22,&i,&o);

  return( o.h.ah );
}

main()
{
  initialize();

  get_input();
  return 0;
}