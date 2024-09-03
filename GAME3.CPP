/* Spiral model */

#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
int main(void)
{
int gd,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
printf("enter the number of rings");
int n;
scanf("%d",&n);
cleardevice();
int r=0;
for(int i=0;i<=n;++i)
{
	arc(getmaxx()/2,getmaxy()/2,0,180,r);
	arc(getmaxx()/2+6,getmaxy()/2,180,360,r+6);
	r+=12;
}
getch();
closegraph();
return 0;
}

