/* Fish movement */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
 int main()
 {
 int gd=DETECT,gm;
 int x=0;
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
if(x<640-rad)
x+=10;
else
x=0;
//if(y<480)
//y+=4;
//else
//y=0;
setfillstyle(EMPTY_FILL,BLACK);
 arc(x,180,30,150,50);
 arc(x,130,210,330,50);
 line(x-42,155,x-80,130);
 line(x-42,155,x-80,180);
 line(x-80,180,x-80,130);
 circle(x+20,150,5);
 circle(x+60,155,7);
 circle(x+63,130,5);
 circle(x+66,110,3);
 arc(x,300,30,150,50);
 arc(x,253,210,330,50);
delay(100);
}closegraph(); return 0;}

