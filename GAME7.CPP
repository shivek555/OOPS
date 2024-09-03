
/* Moving car */

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
int main()
{
 int gd=DETECT,gm;
 int x=0;
 int start=0,end=90;
 int rad=30;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  if(graphresult()!=grOk)
  {
   fprintf(stderr,"main:unable to load");
   exit(1);
  }
  while(!kbhit())
  {
   cleardevice();
   start-=4;
   end-=4;
   if(x<640-rad)
    x+=1 ;
   else x=0;
    setfillstyle(SOLID_FILL,BLUE);
    pieslice(x,240,start,end,rad);
    pieslice(x,240,start-180,end-180,rad);
    circle(x,240,rad);
    setfillstyle(SOLID_FILL,BLUE);
    pieslice(x+120,240,start,end,rad);
    pieslice(x+120,240,start-180,end-180,rad);
    circle(x+120,240,rad);
    line(x+rad,240,x-rad+120,240);
    line(x-rad,240,x-rad-45,240);
   line(x+rad+120,240,x+rad+210,240);
    line(x-rad-45,240,x-60,180);
    line(x-60,180,x-10,180);
    line(x-10,180,x+rad,150);
    line(x+rad,150,x+130,150);
    line(x+130,150,x+150+10,180);
    line(x+160,180,x+210,180);
    line(x+210,180,x+240,240);
    delay(150);} closegraph();return 0;}

