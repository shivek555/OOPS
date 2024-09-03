/*1.>Program to implement the following using built-in
     functions available in the library.

     1.Kite flying.
     2.Bar graph.
     3.Spiral model.
     4.Fish movement.
     5.Rotation of wheel.
     6.Moving car.*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
 int main()
 {
 int gd=DETECT,gm;
 int y=480,x=0;
 int rad=0;
 int start=0,end=90;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 if (graphresult()!=grOk)
 {
 fprintf(stderr,"main:unable to load graph");
 exit(1);
 }
  while(!kbhit())
 {
 cleardevice();
start-=4;
end-=4;
if(x<640)
x+=4;
else
x=0;
if(y>0)
y-=4;
else
y=480;
setcolor(3);
setfillstyle(SOLID_FILL,RED);
setlinestyle(DOTTED_LINE,1,1);
line(x,y,x-40,y-40);
line(x-40,y-40,x,y-80);
line(x,y-80,x+40,y-40);
line(x+40,y-40,x,y);
line(x,y,x-7,y+10);
line(x-7,y+10,x+8,y+10);
line(x,y,x+7,y+10);
line(x,y+10,x,y+50);
line(x-40,y-40,x+40,y-40);
line(x,y-80,x,y);
line(x,y-40,640,480);
delay(100); }
//closegraph();
return 0;
 }



