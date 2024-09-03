

 //*********************** HEADER FILES ********************

#include<iostream.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>

//*********************************************************
//********************* Function Prototypes ***************

void abcd(int,int,int);
void make(int,int,int,int,int);
int subh(int,int,int,int);
void dispday();
void getpos(int);
int mainmenu();
void calender();
void bricks();
void exhi();
int mn(int);
int days31(int);
int yess(int);
int days30(int);
int days29(int);
int days28(int);
void thank(void);

//***********************************************************

int x,y;//Global variables.

 void main()
{
  enum days{fri=1,sat,sun,mon,tue,wed,thu};
  char month;
  int i,m,y,d,day,n,k,flag1=0,nwe2=0,nwe3=0,nwe4=0,nwe1=0;
  clrscr();
 // ******Graphics initialisation********
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s
", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

 //  *******************************************************

  calender();

  while(!flag1)//While-loop for executing as many times user wishes.
 {
   cleardevice();
   n=mainmenu(); //For generating the menu list.

   cleardevice();
   clrscr();
 //For user's choice.
  switch(n)
 {
   //**********For Printing Only Day**********

   case 1:
	  cout<<"YEAR(enter full year between 1901-2050.) ";
	  cin>>y;
	  int yeass;
	  //*****For checking validity ofinput(year).*****
	  yeass=yess(y);
	  while(yeass==1)
	  {
	  if(yeass)
	   {
	    cin>>y;
	    yeass=yess(y);
	   }//end if.
	  }//end while.

	  //***********************************************

	  cout<<"MONTH(enter in number.) ";
	  cin>>m;
	  int ys;
	  //*****For checking validity ofinput(month).*****
	   ys=mn(m);
	   while(ys==1)
	  {
	  if(ys)
	   {
	    cin>>m;
	    ys=mn(m);
	   }//end if.
	  }//end while.

	  //**********************************************

	  cout<<"DATE ";
	  cin>>d;
	  //*****For checking validity ofinput(date).*****
	  if(m==4||m==6||m==9||m==11)
	  nwe2=days30(d);
	    while(nwe2==1)
	  {
	  if(nwe2)
	   {
	    cin>>d;
	    nwe2=days30(d);
	   }
	  }
	  if((y%4==0)&&(m==2))
	  nwe3=days29(d);

	    while(nwe3==1)
	  {
	  if(nwe3)
	   {
	    cin>>d;
	    nwe3=days29(d);
	   }
	  }
	  if((y%4!=0)&&(m==2))
	  nwe4=days28(d);
	    while(nwe4==1)
	  {
	  if(nwe4)
	   {
	    cin>>d;
	    nwe4=days28(d);
	   }
	  }
	  nwe1= days31(d);
	  while(nwe1==1)
	  {
	  if(nwe1)
	   {
	    cin>>d;
	    nwe1=days31(d);
	   }//end if.
	  }//end while.

	  //************************************************

	  //******* Assigning first day to each year *******
	  if(y==1999||y==2021||y==1993||y==2010||y==2004||y==1982||y==1971
	  ||y==1965||y==1954||y==1948||y==1976||y==1943||y==1937||y==1926
	  ||y==1920||y==1909||y==1915||y==2027||y==2038||y==2049||y==2032)
	  i=fri;
	  if(y==1994||y==2005||y==2011||y==2022||y==2016||y==1983||y==1977
	  ||y==1966||y==1955||y==1944||y==1960||y==1988||y==1938||y==1927
	  ||y==1921||y==1932||y==1904||y==1910||y==2033||y==2039||y==2050
	  ||y==2044)
	  i=sat;
	  if(y==1995||y==2000||y==2017||y==2006||y==1989||y==1978||y==1967
	  ||y==1961||y==1950||y==1944||y==1972||y==1939||y==1933||y==1922
	  ||y==1916||y==1911||y==1905||y==2034||y==2045||y==2028)
	  i=sun;
	  if(y==2007||y==2018||y==2012||y==2001||y==1990||y==1979||y==1973
	  ||y==1962||y==1951||y==1945||y==1956||y==1984||y==1934||y==1923
	  ||y==1917||y==1928||y==1906||y==2029||y==2035||y==2046||y==2040)
	  i=mon;
	  if(y==1991||y==1985||y==1974||y==1963||y==1957||y==1946||y==1968
	  ||y==1996||y==2019||y==2013||y==2002||y==1935||y==1939||y==1918
	  ||y==1940||y==1912||y==1907||y==2024||y==2030||y==2041||y==2047)
	  i=tue;
	  if(y==1997||y==1914||y==2003||y==2008||y==1986||y==1975||y==1969
	  ||y==1958||y==1947||y==1952||y==1980||y==1941||y==1930||y==1919
	  ||y==1924||y==1913||y==1902||y==2025||y==2031||y==2042||y==2036)
	  i=wed;
	  if(y==2009||y==1998||y==2015||y==2020||y==1987||y==1981||y==1970
	  ||y==1959||y==1953||y==1964||y==1992||y==1942||y==1931||y==1925
	  ||y==1936||y==1908||y==1914||y==1903||y==2026||y==2037||y==2043
	  ||y==2048)
	  i=thu;
	  //**************************************************************

	  //***** Calculating first day of each month ******
	  if((y%4==0)&&(m==2||m==1))//for leap years.
	    {
	    if(m==2)
	    m=8;
	     if(m==1)
	     m=4;
	   }

	  if(m==1||m==10)
	    i=i+0;
	  if(m==5)
	    i=i+1;
	  if(m==8)
	    i=i+2;
	 if(m==3||m==2||m==11)
	    i=i+3;
	 if(m==6)
	    i=i+4;
	 if(m==12||m==9)
	    i=i+5;
	 if(m==7||m==4)
	    i=i+6;
	 //*******************************************************

	 //***** For calculating the required day *********

	 d=d%7;
	 day=i+d-1;
	 if(day>=7)
	 day=day%7;
	 if(day==0)
	 day=day+7;
	 //************************************************

	settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
	cleardevice();

	//***** For printing the required day *************
	switch(day)
       {
	 case 1:outtextxy(15,230,"THE DAY IS FRIDAY !");
		  break;
	 case 2:outtextxy(15,230,"THE DAY IS SATURDAY !");
		  break;
	 case 3:outtextxy(15,230,"THE DAY IS SUNDAY !");
		  break;
	 case 4:outtextxy(15,230,"THE DAY IS MONDAY !");
		  break;
	 case 5:outtextxy(15,230,"THE DAY IS TUESDAY !");
		  break;
	 case 6:outtextxy(15,230,"THE DAY IS WEDNESDAY !");
		  break;
	 case 7:outtextxy(15,230,"THE DAY IS THURSDAY !");
		 break;
       }
       //**********************************************************

       getch();
       cleardevice();
       flag1=0;
       cleardevice();
       break;
   case 2: cout<<"YEAR(enter a year between 1901-2050.) ";
	   cin>>y;
	   //*****For checking validity ofinput(year)*****
	   yeass=yess(y);
	   while(yeass==1)
	  {
	  if(yeass)
	   {
	    cin>>y;
	    yeass=yess(y);
	   }
	  }
	  //************************************************

	   cout<<"MONTH(enter in digit.) ";
	   cin>>m;
	   //*****For checking validity ofinput(month)*****
	   ys=mn(m);
	   while(ys==1)
	  {
	  if(ys)
	   {
	    cin>>m;
	    ys=mn(m);
	   }
	  }
	  //************************************************

	  clrscr();

	  //******* Assigning first day to each year *******
	  if(y==1999||y==2021||y==1993||y==2010||y==2004||y==1982||y==1971
	  ||y==1965||y==1954||y==1948||y==1976||y==1943||y==1937||y==1926
	  ||y==1920||y==1909||y==1915||y==2027||y==2038||y==2049||y==2032)
	  i=fri;
	  if(y==1994||y==2005||y==2011||y==2022||y==2016||y==1983||y==1977
	  ||y==1966||y==1955||y==1944||y==1960||y==1988||y==1938||y==1927
	  ||y==1921||y==1932||y==1904||y==1910||y==2033||y==2039||y==2050
	  ||y==2044)
	  i=sat;
	  if(y==1995||y==2000||y==2017||y==2006||y==1989||y==1978||y==1967
	  ||y==1961||y==1950||y==1944||y==1972||y==1939||y==1933||y==1922
	  ||y==1916||y==1911||y==1905||y==2034||y==2045||y==2028)
	  i=sun;
	  if(y==2007||y==2018||y==2012||y==2001||y==1990||y==1979||y==1973
	  ||y==1962||y==1951||y==1945||y==1956||y==1984||y==1934||y==1923
	  ||y==1917||y==1928||y==1906||y==2029||y==2035||y==2046||y==2040)
	  i=mon;
	  if(y==1991||y==1985||y==1974||y==1963||y==1957||y==1946||y==1968
	  ||y==1996||y==2019||y==2013||y==2002||y==1935||y==1939||y==1918
	  ||y==1940||y==1912||y==1907||y==2024||y==2030||y==2041||y==2047)
	  i=tue;
	  if(y==1997||y==1914||y==2003||y==2008||y==1986||y==1975||y==1969
	  ||y==1958||y==1947||y==1952||y==1980||y==1941||y==1930||y==1919
	  ||y==1924||y==1913||y==1902||y==2025||y==2031||y==2042||y==2036)
	  i=wed;
	  if(y==2009||y==1998||y==2015||y==2020||y==1987||y==1981||y==1970
	  ||y==1959||y==1953||y==1964||y==1992||y==1942||y==1931||y==1925
	  ||y==1936||y==1908||y==1914||y==1903||y==2026||y==2037||y==2043
	  ||y==2048)
	  i=thu;
	  //*************************************************************

	  int m1;
	  m1=m;
	  if((y%4==0)&&(m==2||m==1))
	   {
	    if(m==2)
	     m=8;
	    if(m==1)
	     m=4;
	   }
	  if(m==1||m==10)
	    i=i+0;
	  if(m==5)
	    i=i+1;
	  if(m==8)
	    i=i+2;
	 if(m==3||m==2||m==11)
	    i=i+3;
	 if(m==6)
	    i=i+4;
	 if(m==12||m==9)
	    i=i+5;
	 if(m==7||m==4)
	    i=i+6;
	 int day=i;
	 if(day>=7)
	 day=day%7;
	 if(day==0)
	 day=day+7;
	 abcd(m1,day,y);
	 flag1=0;
	 break;
   case 3:thank();
	  cleardevice();
	  closegraph();
	  exit(0);
	  break;
 }
 flag1=0;
 }
 closegraph();
}
void abcd(int m,int i,int y)
{
 int nd,firstday;
 if (m==1) nd=31;
 if (m==2)
 {
  if (y%4==0)
      nd=29;
  else
      nd=28;
 }
 if (m==3) nd=31;
 if (m==4) nd=30;
 if (m==5) nd=31;
 if (m==6) nd=30;
 if (m==7) nd=31;
 if (m==8) nd=31;
 if (m==9) nd=30;
 if (m==10) nd=31;
 if (m==11) nd=30;
 if (m==12) nd=31;
 if (i==1) firstday=6;
 if (i==2) firstday=7;
 if (i==3) firstday=1;
 if (i==4) firstday=2;
 if (i==5) firstday=3;
 if (i==6) firstday=4;
 if (i==7) firstday=5;

 subh(firstday,m,nd,y);

}
//???????????????????????????????????????????????????

int subh(int fd,int m,int nod,int yr )
{
   cleardevice();
   setfillstyle(1,7);
   bar(10,10,640,450);
   make(10,10,640,450,1);
   make(11,11,639,449,1);
   make(12,12,638,448,1);
   make(15,15,635,55,2);
   setcolor(8);
   settextstyle(1,0,4);
   outtextxy(257,17,"Calendar");
   outtextxy(256,16,"Calendar");
   setcolor(15);
   outtextxy(255,15,"Calendar");

   make(15,58,635,445,2);
   make(16,59,634,444,2);

   make(80,70,547,100,1);
   setfillstyle(1,7);
   for(int i=80;i<=500;i+=70)
   {
    for(int j=110;j<=400;j+=50)
    {
     bar(i,j,i+47,j+40);
     make(i,j,i+47,j+40,1);
    }
   }

   dispday();
   int p;
   char *dy;

   if(fd==1) p=1;
   if(fd==2) p=2;
   if(fd==3) p=3;
   if(fd==4) p=4;
   if(fd==5) p=5;
   if(fd==6) p=6;
   if(fd==7) p=7;
   int om=m;
   int t=nod;

   for(i=1;i<=nod;i++)
   {
    getpos(p);
    p++;
    sprintf(dy,"%d",i);
    outtextxy(x,y,dy);
    if(nod==0)
       nod=t;
   }
 char mon[10];
 //-------------------------------------
 if (om==1) strcpy(mon,"January");
 if (om==2) strcpy(mon,"February");
 if (om==3) strcpy(mon,"March");
 if (om==4) strcpy(mon,"April");
 if (om==5) strcpy(mon,"May");
 if (om==6) strcpy(mon,"June");
 if (om==7) strcpy(mon,"July");
 if (om==8) strcpy(mon,"August");
 if (om==9) strcpy(mon,"September");
 if (om==10) strcpy(mon,"October");
 if (om==11) strcpy(mon,"November");
 if (om==12) strcpy(mon,"December");
 //-------------------------------------

   char *yar;
   settextstyle(1,0,4);
   outtextxy(200,65,mon);

   sprintf(yar,"%d",yr);
   outtextxy(380,65,yar);
   getch();
   return 0;
}
void getpos(int p)
{
 if (p==1)  {  x=99;  y=162; }
 if (p==2)  {  x=168;  y=162; }
 if (p==3)  {  x=237;  y=162; }
 if (p==4)  {  x=306;  y=162; }
 if (p==5)  {  x=375;  y=162; }
 if (p==6)  {  x=444;  y=162; }
 if (p==7)  {  x=513;  y=162; }
 if (p==8)  {  x=99;  y=212; }
 if (p==9)  {  x=168;  y=212; }
 if (p==10) {  x=237;  y=212; }
 if (p==11) {  x=306;  y=212; }
 if (p==12) {  x=375;  y=212; }
 if (p==13) {  x=444;  y=212; }
 if (p==14) {  x=513;  y=212; }
 if (p==15) {  x=99;  y=262; }
 if (p==16) {  x=168;  y=262; }
 if (p==17) {  x=237;  y=262; }
 if (p==18) {  x=306;  y=262; }
 if (p==19) {  x=375;  y=262; }
 if (p==20) {  x=444;  y=262; }
 if (p==21) {  x=513;  y=262; }
 if (p==22) {  x=99;  y=312; }
 if (p==23) {  x=168;  y=312; }
 if (p==24) {  x=237;  y=312; }
 if (p==25) {  x=306;  y=312; }
 if (p==26) {  x=375;  y=312; }
 if (p==27) {  x=444;  y=312; }
 if (p==28) {  x=513;  y=312; }
 if (p==29) {  x=99;  y=372; }
 if (p==30) {  x=168;  y=372; }
 if (p==31) {  x=237;  y=372; }
 if (p==32) {  x=306;  y=372; }
 if (p==33) {  x=375;  y=372; }
 if (p==34) {  x=444;  y=372; }
 if (p==35) {  x=513;  y=372; }
 if (p==36) {  x=99;  y=162; }
 if (p==37) {  x=168;  y=162; }
}

void dispday()
{
 setcolor(0);
 settextstyle(1,0,2);
 outtextxy(85,120,"Sun");
 outtextxy(155,120,"Mon");
 outtextxy(225,120,"Tue");
 outtextxy(295,120,"Wed");
 outtextxy(365,120,"Thu");
 outtextxy(438,120,"Fri");
 outtextxy(508,120,"Sat");
}

void make(int x1,int y1,int x2,int y2,int m)
{
 if(m==1)
    setcolor(15);
 if(m==2)
    setcolor(8);

 line(x1,y1,x2,y1);
 line(x1,y1,x1,y2);

 if(m==1)
    setcolor(8);
 if(m==2)
    setcolor(15);

 line(x1,y2,x2,y2);
 line(x2,y2,x2,y1);

}

int mainmenu()
	{  int i=0;
	   setcolor(5);
	  settextstyle(SMALL_FONT,HORIZ_DIR,6);
	    for(int j=-55;j<600;j+=100)
	    outtextxy(j,0,"      *********     ");
	    for(j=-55;j<600;j+=100)

	    outtextxy(j,450,"      *********     ");

	  settextstyle(SMALL_FONT,VERT_DIR,6);
	    for( j=-33;j<365;j+=100)
	    outtextxy(0,j,"      *********     ");
	    outtextxy(0,360,"     ***      ");
	    for(j=-35;j<365;j+=100)
	    outtextxy(625,j,"      *********     ");
	    outtextxy(625,360,"     ***      ");
	    setcolor(12);
	   rectangle(15,15,625,450);
	   rectangle(17,17,623,448);
	   settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	   outtextxy(100,190,"1.FOR FINDING DAY");
	   outtextxy(100,230,"2.FOR WHOLE MONTH'S CALENDAR");
	   outtextxy(100,270,"3.QUIT");
	   outtextxy(100,135,"INFORMATION FROM CALENDAR :-");
	   settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	   outtextxy(150,30,"MAIN MENU");
	   settextstyle(SMALL_FONT,HORIZ_DIR,5);
	   outtextxy(200,383,"ENTER  CHOICE....(1-3)-");
	   int n;
	   gotoxy(50,25);

	   cin>>n;
	   return(n);
	   }

void calender()
{
int x=140,y=190,r,st=0,end=10,st1=0,end1=10,s=1,ch;

while(!kbhit())
{
 sound(s*300);
//for(int i=1;i<=15;i++)

arc(310,210,st,end,260);
arc(310,210,st1,end1,250);
arc(310,210,st,end,240);
arc(310,210,st1,end1,230);
arc(310,210,st,end,220);
arc(310,210,st1,end1,210);
arc(310,210,st,end,200);
arc(310,210,st1,end1,190);
arc(310,210,st,end,180);
arc(310,210,st1,end1,170);
arc(310,210,st,end,160);
arc(310,210,st1,end1,150);
arc(310,210,st,end,140);
arc(310,210,st1,end1,130);
arc(310,210,st,end,120);
arc(310,210,st1,end1,110);
arc(310,210,st,end,100);
arc(310,210,st1,end1,90);
arc(310,210,st,end,80);
arc(310,210,st1,end1,70);
arc(310,210,st,end,60);
arc(310,210,st1,end1,50);
arc(310,210,st,end,40);
arc(310,210,st1,end1,30);
arc(310,210,st,end,20);
arc(310,210,st1,end1,10);
arc(310,210,st,end,0);
if(s==25)  //20
s=1;
x=10;  //10
y=190;     //190
//for(int i=1;i<=15;i++)
setcolor(YELLOW);//YELLOW
settextstyle(TRIPLEX_FONT,HORIZ_DIR,s++);
outtextxy(x,y,"CALENDAR");
delay(180); //180
cleardevice();
st=end;
end+=20;
st1=end1;
end1+=20;

}
getch();
nosound();
}


void thank()
{
  clrscr();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,6); //6
	   setcolor(10);//11
	   settextstyle(0,0,6);
	   outtextxy(86,10,"THANK YOU");
	   setcolor(1);
	   outtextxy(92,16,"THANK YOU");
	   setcolor(3);
	   outtextxy(89,13,"THANK YOU");
	   settextstyle(0,0,4);
	   setcolor(1);
	   outtextxy(32,80,"PROJECT MADE BY :-");
	   setcolor(3);
	   outtextxy(29,77,"PROJECT MADE BY :-");
	   setcolor(11);
	   settextstyle(2,0,7);
	   setcolor(2);
	   outtextxy(30,130,"           PARIKSHIT KUMAR SINGH ");
	   setcolor(15);
	   outtextxy(32,130,"           PARIKSHIT KUMAR SINGH ");
	   setcolor(14);
	   outtextxy(30,145,"B.TECH(1st yr) in Computer Science Engineering");
	   setcolor(0);
	   outtextxy(32,145,"B.TECH(1st yr) in Computer Science Engineering");
	   outtextxy(32,160,"     email:parikshitkumarsingh@yahoo.com");
	   setcolor(10);
	   outtextxy(30,175,"   G.I.E.T-Gunupur,RAYAGADA,ORISSA-765022");
	   setcolor(0);
	   outtextxy(32,175,"   G.I.E.T-Gunupur,RAYAGADA,ORISSA-765022");
	   settextstyle(0,0,4);
	   setcolor(1);
	   outtextxy(26,210,"ACKNOWLEDGEMENTS :-");
	   setcolor(3);
	   outtextxy(23,210,"ACKNOWLEDGEMENTS :-");
	   setcolor(3);
	   settextstyle(0,0,2);
	   setcolor(11);
	   outtextxy(26,260,"MR. MURLI KRISHNA SENAPATI");
	   settextstyle(0,0,2);
	   setcolor(11);
	   outtextxy(26,300,"MR. S SUBBA RAO");
	   settextstyle(0,0,2);
	   setcolor(11);
	   outtextxy(26,340,"MR. S.K LABALA");
	   settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
	   setcolor(6);
	   outtextxy(226,360,"GOOD BYE !!");

	   getch();


}

int mn(int m)
    {
      if(m>12||m<1)
      {
	cout<<"Error in entering data!";
	cout<<"Enter the month correctly :";
	return(1);
      }
       else
       return(0);
    }

 int days31(int d)
   {
     if(d>31||d<1)
     {
      cout<<"Error in entering data!";
      cout<<"Enter the date correctly :";
      return(1);
     }
      else
     return(0);
   }

 int yess(int ab)
  {
   if(ab<1901||ab>2050)
    {
     cout<<"Error in entering data!";
     cout<<"Enter the year between 1901-2050 :";
     return(1);
    }
    else
    return(0);
  }

int days30(int rat)
 {
   if(rat>30||rat<1)
   {
    cout<<"Error in entering data!"<<endl;
    cout<<"Enter the date correctly :";
    return(1);
   }
   else
    return(0);
 }
int days28(int cat)
 {
   if(cat>28||cat<1)
   {
    cout<<"Error in entering data!"<<endl;
    cout<<"Enter the date correctly :";
    return(1);
   }
   else
    return(0);
 }

int days29(int dog)
 {
   if(dog>29||dog<1)
   {
    cout<<"Error in entering data-It is a leap year!"<<endl;
    cout<<"Enter the date correctly :";
    return(1);
   }
   else
    return(0);
 }
