/*2.>Write a program to implement the midpoint line algorithm to
generate a  line with any slope and thickness. Implement the polyline command
using this  algorithm as a routine that displays the set of straight lines
between the  'n' input points. For n=1 the routine displays a single
point.*/


#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<stdio.h>

void swap(int &x,int &y)
{
	int t= x;
	x = y;
	y = t;
}
void plotpixel(int x,int y,int t,int flag)
{
	if(flag)
	{
		swap(x,y);
		x-=t/2;
		for(int i=0;i<t;i++)
			putpixel(x+i,y,WHITE);
	}
	else
	{
		y-=t/2;
		for(int i=0;i<t;i++)
			putpixel(x,y+i,CYAN);
	}
}

void bres(int x1,int y1,int x2,int y2,int t)
{
	int dx=abs(x1-x2),dy=abs(y1-y2),incy=1,flag=0;
	if(dy>dx)
	{
		swap(x1,y1);
		swap(x2,y2);
		swap(dx,dy);
		flag=1;
	}
	if(x1>x2)
	{
		swap(x1,x2);
		swap(y1,y2);
	}
	if(y1>y2)
		incy = -1;
	int d = 2*dy-dx;
	while(x1<x2)
	{
		plotpixel(x1,y1,t,flag);
		if(d<0)
			d+=2*dy;
		else
		{
			d+=2*(dy-dx);
			y1+=incy;
		}
		x1++;
	}
}
void main()
{
	int gd=DETECT,gm,x[10],y[10],t,n;
	printf("Enter the thickness==>");
	scanf("%d",&t);
	printf("Enter the no of points==>");
	scanf("%d",&n);
	printf("Enter the points==>");
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	if(n==1)
		plotpixel(x[0],y[0],t,0);
	else
		for(i=0;i<n-1;i++)
			bres(x[i],y[i],x[i+1],y[i+1],t);
		getch();
		closegraph();
}

/* 3.>Program to display a line graph using MIDPOINT LINE algorithm. The input to the program is a set of data
corresponding to the X and Y axes. Data parts are to be displayed as
asterisk(*) according to the input  specification.*/

#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define O_X 50
#define O_Y 50

void swap(int &x,int &y)
{
	int t=x;
	x=y;
	y=t;
}

void bres(int x1,int y1,int x2,int y2)
{
	int dx=abs(x1-x2),dy=abs(y1-y2),flag=0,incy=1;
	if(dy>dx)
	{
		swap(x1,y1);
		swap(x2,y2);
		swap(dx,dy);
		flag=1;
	}
	if(x1>x2)
	{
		swap(x1,x2);
		swap(y1,y2);
	}
	if(y1>y2)
		incy =-1;
	int d = 2*dy - dx;
	while(x1<x2)
	{
		if(flag)
			putpixel(y1+O_X,480-x1-O_Y,BLUE);
		else
			putpixel(x1+O_X,480-y1-O_Y,BLUE);
		if(d<0)
			d+=2*dy;
		else
		{
			d+=2*(dy-dx);
			y1+=incy;
		}
		x1++;
	}
}
void main()
{
	int gd=DETECT,gm,x[10],y[10],n;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter the number of points==>");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter point %d ==>",i+1);
		scanf("%d%d",&x[i],&y[i]);
	}
	initgraph(&gd,&gm,"c:\cpp\bgi");
	line(50,25,50,480-50);
	line(50,480-50,640-25,480-50);
	outtextxy(0,240,"Y-Axis");
	outtextxy(310,455,"X-Axis");
	for(i=0;i<n-1;i++)
		bres(x[i],y[i],x[i+1],y[i+1]);
	setcolor(RED);
	char s[10];
	for(i=0;i<n;i++)
	{
		outtextxy(x[i]+O_X-2,480-y[i]-O_Y-2,"*");
		outtextxy(x[i]+O_X+10,480-y[i]-O_Y+10,itoa(x[i],s,10));
		outtextxy(x[i]+O_X+35,480-y[i]-O_Y+10,",");
		outtextxy(x[i]+O_X+40,480-y[i]-O_Y+10,itoa(y[i],s,10));
	}
	getch();
	closegraph();
}

/*4.>Program to implement the MIDPOINT CIRCLE drawing algorithm to
draw a circle.Modify the algorithm to implement specified arc or sector./*

#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
int in(int x,int y,float start,float end)
{
	double a,angle;
	if(x!=0)
	{
		a=(double)y/x;
		angle=atan(fabs(a));
		if(x>0)
		{

			if(y<0)
				angle=2*M_PI-angle;
		}
		else
		{
			if(y>0)
				angle=M_PI-angle;
			else
				angle=M_PI+angle;
		}
	}
	else
	{
		angle=M_PI/2;
		if(y<0)
			angle+=M_PI;
	}

	if((angle>=start)&&(angle<=end))
		return(1);
	return(0);
}


void plot_points(int x,int y,int xc,int yc,float start,float end)
{
	if(in(x,y,start,end)==1)
		putpixel(xc + x,getmaxy()-(yc + y),WHITE);
	if(in(-x,y,start,end)==1)
		putpixel(xc - x,getmaxy()-(yc + y),WHITE);
	if(in(x,-y,start,end)==1)
		putpixel(xc + x,getmaxy()-(yc - y),WHITE);
	if(in(-x,-y,start,end)==1)
		putpixel(xc - x,getmaxy()-(yc - y),WHITE);
	if(in(y,x,start,end)==1)
		putpixel(xc + y,getmaxy()-(yc + x),WHITE);
	if(in(-y,x,start,end)==1)
		putpixel(xc - y,getmaxy()-(yc + x),WHITE);
	if(in(y,-x,start,end)==1)
		putpixel(xc + y,getmaxy()-(yc - x),WHITE);
	if(in(-y,-x,start,end)==1)
		putpixel(xc - y,getmaxy()-(yc - x),WHITE);
}

void bres_circle(int xc,int yc,int r,float startangle,float
endangle,int
c)
{
	int x = 0;
	int y = r;
	int d = 1 - r;
	int xstart = r * cos((M_PI * startangle) / 180);
	int ystart = r * sin((M_PI * startangle) / 180);
	int xend = r * cos((M_PI * endangle) / 180);
	int yend = r * sin((M_PI * endangle) /180);

	cout << "Xstart: " << xstart << endl;
	cout << "ystart: " << ystart << endl;
	cout << "xend: " << xend << endl;
	cout << "yend: " << yend << endl;
	startangle=(M_PI*startangle)/180;
	endangle=(M_PI*endangle)/180;
	while(x <= y)
	{
		plot_points(x,y,xc,yc,startangle,endangle);
		if(d < 0)
		{
			d += 2*x + 3;
			x++;
		}
		else
		{
			d += 2*(x-y)+5;
			x++;
			y--;
		}
	}
	if(c==1)
	{
		line(xc,getmaxy()-yc,xstart+xc,getmaxy()-(yc+ystart));
		line(xc,getmaxy()-yc,xend+xc,getmaxy()-(yend+yc));
	}
}

void main()
{
	int gd=DETECT,gm;
	int xc,yc,radius,c;
	float startangle,endangle;
	initgraph(&gd,&gm,"c:\tc\bgi");
	cout << "
Enter the co-ordinates of the center: ";
	cin >> xc >> yc;
	cout << "
Enter the radius of the circle: ";
	cin >> radius;
	cout<< "
Enter the startangle: ";
	cin >> startangle;
	cout << "
Enter the endangle: ";
	cin >> endangle;
	cout<<"enter 0 for arc and 1 for sector
";
	cin>>c;
	cleardevice();
	bres_circle(xc,yc,radius,startangle,endangle,c);
	getch();
	closegraph();
}

/*5.>Program to draw a rectangle and perform the following
     operations.
     1.Rotation about the origin followed by translation.
     2.Rotation about an arbitrary point.
     3.Apply X shear and Y shear on the rectangle.*/



#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

int rect[4][2]={0,0,100,0,100,50,0,50};
void reset(int r[4][2])
{
	for(int i=0;i<4;i++)
	{
		r[i][0]=rect[i][0];
		r[i][1]=rect[i][1];
	}
}
void draw(int r[4][2])
{
	setcolor(LIGHTGREEN);
	setlinestyle(DOTTED_LINE,0,2);
	line(320,0,320,480);
	line(0,240,640,240);
	setlinestyle(SOLID_LINE,0,1);
	setcolor(RED);
	for(int i=0;i<3;i++)
		line(320+r[i][0],-r[i][1]+240,r[i+1][0]+320,-r[i+1][1]+240);
	line(r[0][0]+320,-r[0][1]+240,r[3][0]+320,-r[3][1]+240);
}
void rotate(int r[4][2],double angle)
{
	int x,y;
	for(int i=0;i<4;i++)
	{
		double x=r[i][0]*cos(angle)-r[i][1]*sin(angle);
		double y=r[i][0]*sin(angle)+r[i][1]*cos(angle);
		r[i][0]=x;
		r[i][1]=y;
	}
}
void translate(int r[4][2],int dx,int dy)
{
	for(int i=0;i<4;i++)
	{
		r[i][0]+=dx;
		r[i][1]+=dy;
	}
}
void shear(int r[4][2],int sx,int sy)
{
	for(int i=0;i<4;i++)
	{
		r[i][0] = r[i][0]+r[i][1]*sx;
		r[i][1] = r[i][1]+r[i][0]*sy;
	}
}

void main()
{
	int gd=DETECT,gm,r[4][2],angle,dx,dy;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	reset(r);
	printf("Rotation about origin followed by translation");
	printf("Enter the rotation angle:");
	scanf("%d",&angle);
	printf("Enter the translation vectors:");
	scanf("%d%d",&dx,&dy);
	rotate(r,angle*M_PI/180.0);
	draw(r);
	getch();
	translate(r,dx,dy);
	draw(r);
	getch();
	reset(r);
	cleardevice();
	printf("Rotation about arbitrary point");
	printf("Enter the rotation angle:");
	scanf("%d",&angle);
	printf("Enter the point of reference:");
	scanf("%d%d",&dx,&dy);
	putpixel(dx+320,240-dy,CYAN);
	translate(r,-dx,-dy);
	draw(r);
	getch();
	rotate(r,angle*M_PI/180.0);
	draw(r);
	getch();
	translate(r,dx,dy);
	draw(r);
	getch();
	reset(r);
	cleardevice();
	printf("Shearing of the rectangle");
	printf("Enter the x and y shear:");
	scanf("%d%d",&dx,&dy);
	shear(r,dx,dy);
	draw(r);
	getch();
	cleardevice();
	closegraph();
}

/*6.>Program to create a house like figure and perform the
     following operations.
     1.Scaling about the origin followed by translation.
     2.Scaling with reference to an arbitrary point.
     3.Reflect about the line y = mx + c.*/


#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

int house[9][2] = {
50,50,75,50,75,75,100,75,100,50,125,50,125,100,87,125,50,100};
void reset(int h[9][2])
{
	for(int i=0;i<9;i++)
	{
		h[i][0] = house[i][0];
		h[i][1] = house[i][1];
	}
}
void draw(int h[9][2])
{
	setcolor(CYAN);
	setlinestyle(DOTTED_LINE,0,2);
	line(320,0,320,480);
	line(0,240,640,240);
	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,2);
	for(int i=0;i<8;i++)
		line(h[i][0]+320,240-h[i][1],h[i+1][0]+320,240-h[i+1][1]);
	line(h[0][0]+320,240-h[0][1],h[8][0]+320,240-h[8][1]);
}
void scale(int r[9][2],int sx,int sy)
{
	for(int i=0;i<9;i++)
	{
		r[i][0] = sx*r[i][0];
		r[i][1] = sy*r[i][1];
	}
}
void translate(int h[9][2],int dx,int dy)
{
	for(int i=0;i<9;i++)
	{
		h[i][0] = h[i][0]+dx;
		h[i][1] = h[i][1]+dy;
	}
}
void rotate(int r[9][2],float angle)
{
	int x,y;
	for(int i=0;i<9;i++)
	{
		x = r[i][0]*cos(angle) - r[i][1]*sin(angle);
		y = r[i][0]*sin(angle) + r[i][1]*cos(angle);
		r[i][0] = x;
		r[i][1] = y;
	}
}
void reflect(int r[9][2],float m,int c)
{
	for(int i=0;i<9;i++)
		r[i][1] += -c;
		draw(r);
	int x,y;
	double angle=M_PI/2-atan(m);
	rotate(r,angle);
	for(i=0;i<9;i++)
		r[i][0] = - r[i][0];
	angle=-angle;
	rotate(r,angle);
	for(i=0;i<9;i++)
		r[i][1] += c;draw(r);getch();
}
void main()
{
	int gd=DETECT,gm,h[9][2],sx,sy,x,y;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	reset(h);
	draw(h);
	printf("Scaling wrt origin");
	printf("Enter the scaling factors sx,sy:");
	scanf("%d%d",&sx,&sy);
	scale(h,sx,sy);
	draw(h);
	getch();
	cleardevice();
	reset(h);
	draw(h);
	printf("Scaling about an arbitrary point");
	printf("Enter the point:");
	scanf("%d%d",&x,&y);
	putpixel(x+320,240-y,RED);
	translate(h,-x,-y);
	scale(h,sx,sy);
	translate(h,x,y);
	draw(h);
	getch();
	cleardevice();
	reset(h);
	draw(h);
	printf("Reflection about y=mx+c
");
	printf("Enter the values of m & c:");
	scanf("%d%d",&x,&y);
	reflect(h,(float)x,y);
	draw(h);
	getch();
	closegraph();
}

/*7.>Program to implement the COHEN-SUTHERLAND line clipping
algorithm.Make provision to specify the input line, window for clipping
and view port for displaying the clipped image.(use built in line and
rectangle functions)*/



#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0

typedef unsigned int outcode;
typedef unsigned char boolean;
struct point
{
	double x,y;
};
struct line
{
	struct point p1,p2;
};
enum{TOP = 0x1,BOTTOM = 0x2,RIGHT = 0x4,LEFT = 0x8};
outcode Compoutcode(double x,double y,double xmin,double xmax,double
ymin,double ymax)
{
	outcode code = 0;
	if(y > ymax)
		code|=TOP;
	else
		if(y < ymin)
			code|=BOTTOM;
	if(x>xmax)
		code|=RIGHT;
	else
		if(x<xmin)
			code|=LEFT;
	return code;
}
void LineClipAndDraw(double &x0,double &y0,double &x1,double &y1,double
xmin,double xmax,double ymin,double ymax)
{
	outcode outcode0,outcode1,outcodeOut;
	boolean accept = TRUE,done = FALSE;
	outcode0 = Compoutcode(x0,y0,xmin,xmax,ymin,ymax);
	outcode1 = Compoutcode(x1,y1,xmin,xmax,ymin,ymax);
	do
	{
		if(!(outcode0|outcode1))
		{
			accept = TRUE;
			done = TRUE;
		}
		else
			if(outcode0 & outcode1)
				done = TRUE;
			else
			{
				double x,y;
				outcodeOut = outcode0?outcode0:outcode1;
				if(outcodeOut&TOP)
				{
					x = x0+(x1-x0)*(ymax-y0)/(y1-y0);
					y = ymax;
				}
				else
					if(outcodeOut & BOTTOM)
					{
						x = x0 + (x1-x0)*(ymin-y0)/(y1-y0);
						y = ymin;
					}
					else
						if(outcodeOut & RIGHT)
						{
							y = y0 + (y1-y0)*(xmax-x0)/(x1-x0);
							x = xmax;
						}
						else
						{
							y = y0 + (y1 - y0)*(xmin - x0)/(x1-x0);
							x = xmin;
						}
						if(outcodeOut == outcode0)
						{
							x0 = x;
							y0 = y;
							outcode0 = Compoutcode(x0,y0,xmin,xmax,ymin,ymax);
						}
						else
						{
							x1 = x;
							y1 = y;
							outcode1 = Compoutcode(x1,y1,xmin,xmax,ymin,ymax);
						}
			}
	}while(done == FALSE);
	if(accept)
		line(x0,y0,x1,y1);
}
void WToVP(double &c,double min,double max,double vmin,double vmax)
{
	double vc;
	vc = (vmax - vmin)/(max - min);
	vc *= (c - min);
	vc += vmin;
	c = vc;
}

void main()
{
	int gmode = DETECT,gdriver;
	struct line lines[10];
	int n;
	double xmin,xmax;
	double ymin,ymax;
	double xscale,yscale;
	double vxmin,vxmax;
	double vymin,vymax;
	int i;
	initgraph(&gmode,&gdriver,"c:/tc/bgi");
	cout << "Enter the number of lines: " << endl;
	cin >> n;
	cout << "Enter the endpoints of the lines: " << endl;
	for(i=0;i<n;i++)
	{
		cout << i+1 << ".";
		cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> 
lines[i].p2.y;
	}
	cout << "Enter the Top Left of the clip window: ";
	cin >> xmin >> ymin;
	cout << "Enter the Bottom Right of the clip window: ";
	cin >> xmax >> ymax;
	cout << "Enter the Top Left of the viewport: ";
	cin >> vxmin >> vymin;
	cout << "Enter the Bottom Right of the viewport: ";
	cin >> vxmax >> vymax;
	cleardevice();
	for(i =0;i<n;i++)
		line(lines[i].p1.x,lines[i].p1.y,lines[i].p2.x,lines[i].p2.y);
	rectangle(xmin,ymin,xmax,ymax);
	getch();
	cleardevice();
	rectangle(xmin,ymin,xmax,ymax);
	for(i =0;i<n;i++)

LineClipAndDraw(lines[i].p1.x,lines[i].p1.y,lines[i].p2.x,lines[i].p2.y,xm
in,xmax,ymin,ymax);
	getch();
	for(i = 0;i<n;i++)
	{
		WToVP(lines[i].p1.x,xmin,xmax,vxmin,vxmax);
		WToVP(lines[i].p1.y,ymin,ymax,vymin,vymax);
		WToVP(lines[i].p2.x,xmin,xmax,vxmin,vxmax);
		WToVP(lines[i].p2.y,ymin,ymax,vymin,vymax);
	}
	cleardevice();
	rectangle(vxmin,vymin,vxmax,vymax);
	for(i=0;i<n;i++)
		line(lines[i].p1.x,lines[i].p1.y,lines[i].p2.x,lines[i].p2.y);
	getch();
	closegraph();
}

/*8.>Write a program to implement Bezier curve for  the given set of
control points*/

#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<conio.h>
int x1,y1,x2,y2,x3,y3,x4,y4;
void bezier_curve(int,int,int,int,int,int,int,int);
void main()
{
	x1=50,y1=200,x2=200,y2=50,x3=400,y3=400,x4=450,y4=150;
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"c:\tc\bgi");
	bezier_curve(x1,y1,x2,y2,x3,y3,x4,y4);
	getch();
}
void bezier_curve(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int 
y4)
{
	putpixel(x2,y2,15);
	putpixel(x3,y3,15);
	for(float t = 0; t < 1; t += 0.0005)
	{
		float xt = (1-t)*(1-t)*(1-t)*x1 + 3*t*(1-t)*(1-t)*x2
								+ 3*t*t*(1-t)*x3 + t*t*t*x4;
		float yt = (1-t)*(1-t)*(1-t)*y1 + 3*t*(1-t)*(1-t)*y2
								+ 3*t*t*(1 - t)*y3 + t*t*t*y4;
		putpixel(xt,yt,3);
		line(x1,y1,x2,y2);
		line(x2,y2,x4,y4);
		line(x4,y4,x3,y3);
		line(x3,y3,x1,y1);
	}
}

/*9.>Write a program to implement 3-D rotation with respect to z-axis and appropriate data structure to
     implement the wire frame.*/


#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#define O -50
double rec1[5][2] = { 200,100,300,100,300,200,200,200,200,100};
double rec2[5][2] = {
200+O,100-O,300+O,100-O,300+O,200-O,200+O,200-O,200+O,100-O};
double angle = 5.0*M_PI/180;
double midx1 = (rec1[0][0]+rec1[1][0])/2;
double midy1 = (rec1[1][1]+rec1[2][1])/2;
double midx2 = (rec2[0][0]+rec2[1][0])/2;
double midy2 = (rec2[1][1]+rec2[2][1])/2;
void rotate()
{
	int i;
	double x1,y1;
	setlinestyle(1,0,1);
	setcolor(YELLOW);
	for(i=0;i<5;i++)
	{
		x1 = midx1 + (rec1[i][0]-midx1)*cos(angle) -
(rec1[i][1]-midy1)*sin(angle);
		y1 = midy1 + (rec1[i][0]-midx1)*sin(angle) +
(rec1[i][1]-midy1)*cos(angle);
		rec1[i][0] = x1 ;
		rec1[i][1] = y1;
		x1 = midx2 + (rec2[i][0]-midx2)*cos(angle) -
(rec2[i][1]-midy2)*sin(angle);
		y1 = midy2 + (rec2[i][0]-midx2)*sin(angle) +
(rec2[i][1]-midy2)*cos(angle);
		rec2[i][0] = x1 ;
		rec2[i][1] = y1;
	}
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	outtextxy(170,20," REVOLVING CUBE ");
	setlinestyle(SOLID_LINE,1,1);
	line(175,65,455,65);
	setlinestyle(DOTTED_LINE,1,1);
	for(i=0;i<4;i++)
	{
		line(100+rec1[i][0],rec1[i][1]+50,100+rec2[i][0],rec2[i][1]+50);
		line(100+rec1[i][0],rec1[i][1]+50,100+rec1[i+1][0],rec1[i+1][1]+50);
		line(100+rec2[i][0],rec2[i][1]+50,100+rec2[i+1][0],rec2[i+1][1]+50);
	}
	delay(50);
	cleardevice();
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setlinestyle(1,0,1);
	setcolor(YELLOW);
	/*for(int i=0;i<4;++i)
	{
		line(100+rec1[i][0],rec1[i][1]+50,100+rec2[i][0],rec2[i][1]+50);
		line(100+rec1[i][0],rec1[i][1]+50,100+rec1[i+1][0],rec1[i+1][1]+50);
		line(100+rec2[i][0],rec2[i][1]+50,100+rec2[i+1][0],rec2[i+1][1]+50);
	}
	getch();*/
	cleardevice();
	while(!kbhit())
		rotate();
	closegraph();
}

/*10.>Program to fill any given polygon using scan-line area fillng algorithm.*/


#include <stdio.h>
#include <conio.h>
#include <graphics.h>
struct node
{
	int x;
	int y;
	struct node *next;
};
struct node *first,*p,*last;
int x,y;
void insert(int x,int y)
{
	struct node *get;
	get=new node;
	get->x=x;
	get->y=y;
	get->next=NULL;
	last->next=get;
	last=get;
}

void ffill(int x,int y,int background_color,int fill_color)
{
	if(background_color==fill_color)
		return;
	last=first=new node;
	first->x=x;
	first->y=y;
	first->next=NULL;
	while(first!=NULL)
	{
		putpixel(x,y,fill_color);
		if(getpixel(x,y-1)==background_color)
		{
			putpixel(x,y-1,fill_color);
			insert(x,y-1);
		}
		if(getpixel(x+1,y)==background_color)
		{
			putpixel(x+1,y,fill_color);
			insert(x+1,y);
		}
		if(getpixel(x,y+1)==background_color)
		{
			putpixel(x,y+1,fill_color);
			insert(x,y+1);
		}
		if(getpixel(x-1,y)==background_color)
		{
			putpixel(x-1,y,fill_color);
			insert(x-1,y);
		}
		p=first;
		first=first->next;
		delete p;
		x=first->x;
		y=first->y;
	}
}
void main()
{
	int backcolor,x,y,color,gdriver=DETECT,gmode,n,poly[20];
	printf("Enter the points");
	for(int i=0;i<6;i++)
		scanf("%d",&poly[i]);
	printf("enter the Fill Color");
	scanf("%d",&color);
	initgraph(&gdriver,&gmode,"c:\cpp\bgi");
	line(poly[0],poly[1],poly[2],poly[3]);
	line(poly[2],poly[3],poly[4],poly[5]);
	line(poly[4],poly[5],poly[0],poly[1]);
	backcolor=getpixel(x,y);

ffill((poly[0]+poly[2]+poly[4])/3,(poly[1]+poly[3]+poly[5])/3,backcolor,co
lor);
	getch();
}