/* Rotation of wheel */
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
int main()
{
int gd=DETECT,gm;
int x=0;
int start=0,end=90;
int rad=50;
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
if (graphresult()!=grOk)
{
fprintf(stderr,"main:unable to load graph");
exit(1);
}
while(!kbhit())
{
cleardevice();
setbkcolor(8);
start-=4;
end+=4;
if (x<640+rad)
x+=1;
else x=0;
setfillstyle(SOLID_FILL,BLACK);
pieslice(x,240,start,end,rad);
pieslice(x,240,start -180,end -180,rad);
circle(x,240,rad);
delay(500);
}
closegraph();
return 0;
}
