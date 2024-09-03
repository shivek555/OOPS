
/*Bar Graph */

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
int main(void)
{
int a[10];
int gd,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
cleardevice();
printf("enter the number of values");
int n;
scanf("%d",&n);
printf("enter values one by one ");
for(int i=0;i<n;++i)
scanf("%d",&a[i]);
cleardevice();
int x=70,m=30;
char *s;
for(i=0;i<n;++i)
{
	bar3d(x,getmaxy()-50-(5*a[i]),x+m,getmaxy()-50,8,6);
	outtextxy(x+15,getmaxy()-70-(5*a[i]),itoa(a[i],s,10));
	x+=m+30;
}
getch();
return 0;
}

