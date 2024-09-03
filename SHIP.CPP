#include <stdio.h>
#include<conio.h>
#include "graphics.h"
#include<alloc.h>
#include<dos.h>
#include<stdlib.h>

void exitmessage(void);
void lost(void);

void main()
{
 randomize();
 int gd=DETECT,gm,no=0,area,maxx,maxy,chance=0;
 int ch,x=25,y=25,xdir=1,ydir=1,x1=20,y1,x1dir=0,area1;
 void *buff,*cuff;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,RED);
 circle(50,50,15);                //
 floodfill(50,50,WHITE);
 arc(25,25,335,360,40);
 arc(75,25,180,205,40);
 circle(42,45,2);
 circle(54,45,2);
 setfillstyle(SOLID_FILL,BLACK);
 floodfill(42,45,15);
 floodfill(54,45,15);		//draw devil
 setcolor(10);
 area=imagesize(25,25,75,75);
 buff=malloc(area);
 getimage(25,25,75,75,buff);
 putimage(25,25,buff,XOR_PUT);  //erase devil
 maxx=getmaxx();
 maxy=getmaxy();
 y1=maxy/2;
 setcolor(15);
 setfillstyle(SOLID_FILL,15);
 rectangle(10,y1,12,y1+2);                 //
 floodfill(11,y1+1,15);                    //draw bullet
 area1=imagesize(10,y1,12,y1+2);
 cuff=malloc(area1);
 getimage(10,y1,12,y1+2,cuff);
 putimage(10,y1,cuff,XOR_PUT);  //erase bullet
 setcolor(14);
 rectangle(0,0,maxx,maxy);
 setviewport(1,1,maxx-1,maxy-1,1);
 settextstyle(1,0,3);
 settextjustify(1,1);
 delay(4000);
 setcolor(15);
 while(no<100)
  {
   putpixel(random(maxx),random(maxy),random(16));
   no++;
  }
 outtextxy(maxx/2,30,"...the world is coming to an end...");
 outtextxy(maxx/2,80,"...the devil is going to destoy the universe...");
 outtextxy(maxx/2,130,"...destroy the devil before it destroys us...");
 outtextxy(maxx/2,180,"...ALL THE BEST...");
 delay(2000);
 outtextxy(maxx/2,270,"use 6 to shoot the devil");
 outtextxy(maxx/2,310,"use 8 & 2 to move gun vertically");
 outtextxy(maxx/2,360,"You have only 10 bullets");
 outtextxy(maxx/2,450,"press any key to continue....");
 getch();
 flushall();
 do
 {
  clearviewport();
  gotoxy(33,1);
  printf("Bullets Left: %d",10-chance);
  no=0;
  while(no<100)
  {
   putpixel(random(maxx),random(maxy),random(16));
   no++;
  }
  if(kbhit())
  {
   ch=getch();
   if(ch==54)                      //shoot bullet
   {
    x1dir=1;
    chance++;
   }
   if(ch==56&&x1dir==0)            //move gun up
    y1=y1-10;
   if(ch==50&&x1dir==0)            //move gun down
    y1=y1+10;
   if(ch==27)
    exitmessage();
  }
  fillellipse(10,y1+1,5,3);
  putimage(x1,y1,cuff,XOR_PUT);       //draw bullet
  delay(10);
  putimage(x1,y1,cuff,XOR_PUT);       //erase bullet
  x1=x1+10*x1dir;
  putimage(x,y,buff,XOR_PUT);         //draw devil
  delay(30);
  putimage(x,y,buff,XOR_PUT);         //erase devil
  x=x+(xdir*random(30));
  y=y+(ydir*random(20));
  if(x>=maxx-71)                      //keep devil within screen
  {
   xdir*=-1;
   x=maxx-71;
  }
  if(x<=175&&xdir==1)
   x=175;
  if(x<=175&&xdir==-1)
   xdir*=-1;
  if(y>=maxy-71)
  {
   ydir*=-1;
   y=maxy-71;
  }
  if(y<=30)
  {
   ydir*=-1;
   y=30;
  }                                    //
  if(x1>=maxx-3||x<=1)                 //failed chance
  {
   x1=20;
   x1dir=0;
  }
  if(y1>=maxy-20)                      //keep gun within screen
   y1=maxy-21;
  if(y1<=20)
   y1=21;                              //
  if(x1<=x+40&&x1>=x+12&&y1<=y+38&&y1>=y+10)         //successful hit
  {
   moveto(maxx/2,maxy/2);
   outtextxy(maxx/2,maxy/2,"...YOU'VE...WON...");
   sound(500);
   delay(5000);
   nosound();
   delay(3000);
   exit(0);
  }
 }
 while(chance<=10);
 if(chance==211)
  lost();
 getch();
 closegraph();
 restorecrtmode();
}

void exitmessage()
{
 char cho;
 outtextxy(getmaxx()/2,getmaxy()/2,"EXIT : Y or N...");
 delay(100);
 flushall();
 cho=getch();
 if(cho=='y'||cho=='Y')
  exit(0);
 else
 if(cho=='n'||cho=='N')
 {
  clearviewport;
  return;
 }
}

void lost()
{
 outtextxy(getmaxx()/2,getmaxy()/2-50,"Your bullets are over");
 outtextxy(getmaxx()/2,getmaxy()/2,"The devil destroys the world");
}
