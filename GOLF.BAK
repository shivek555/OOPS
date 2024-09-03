#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<time.h>

int
get,i,x,y,rotate,ddel,button,betc=0,betc1=0,betc2=0,beta=0,dd=0,won,wwon=0
,wx,wy,dnx[50],dny[50];
float l=1,k=1,x1[50],y1[50],pi=3.1415,cal;
char c[10],d[10];
long int 
ptotalcredit=5000,ntotalcredit=5000,dcredit,wamount=0,lamount=0;

union REGS ii,o; //FOR THE MOUSE REQUIRED

/********************FUNCTION PROTOTYPES************************/
void title(void);
void mainscreen(void);
void drawcircle(void);
void roulletecolor(void);
void roulletemove(void);
void dialnumber(int);
void checkbetcondition(int);
void wonamount(int);
void loseamount(void);
void drawbettingmat(void);
void drawbettingamount(void);
void drawexit(void);
void drawplay(void);
void drawhelp(void);
void displaycredit(void);

void back(void);
void more(void);
int wondisplay(void);
int betdisplay(void);
int amountdisplay(void);

int play(void);
int helpmenu(void);
int morehelpmenu(void);
void gameover(void);
int initmouse(void);
int showmouseptr(void);
//void restrictmouseptr(int);
//void getmousepos(int);
/********************FUNCTION PROTOTYPES************************/


/******************** MOUSE FUNCTION ************************/
initmouse()
{
ii.x.ax=0;
int86(0x33,&ii,&o);
return(o.x.ax);
}

showmouseptr()
{
ii.x.ax=1;
int86(0x33,&ii,&o);
return 0;
}

restrictmouseptr(int x1,int y1,int x2,int y2)
{
ii.x.ax=7;
ii.x.cx=x1;
ii.x.dx=x2;
int86(0x33,&ii,&o);
ii.x.ax=8;
ii.x.cx=y1;
ii.x.dx=y2;
int86(0x33,&ii,&o);
}

getmousepos(int *button,int *x,int *y)
{
ii.x.ax=3;
int86(0x33,&ii,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}

/******************** MOUSE FUNCTION ************************/



void main()
{
int maxx,maxy;
int gm=DETECT,gd;
clrscr();
initgraph(&gm,&gd,"C:\\TURBOC3\\BGI");

title();
fromhelpmenu:cleardevice();
/************************THE GAME BEGINS***************************///
delay(500);
maxx=getmaxx();
maxy=getmaxy();
if(initmouse()==0)
 {
  closegraph();
  restorecrtmode();
  printf("Mouse driver not loaded");
  exit(1);
 }
restrictmouseptr(0,0,maxx,maxy);
mainscreen();

while(1)
{
 //gotoxy(55,1);
 //printf("BETc= %02d",betc);
 //gotoxy(1,1);
 //printf("BETa= %04d",beta);
 //gotoxy(55,2);
 //printf("X=%03d Y=%03d",x,y);
 //gotoxy(20,1);
 //printf("WON=%02d",won);

 getmousepos(&button,&x,&y);

 setcolor(2);
 wondisplay();
 amountdisplay();
 betdisplay();
 if((button &1)==1)
  {
   setcolor(0);
   wondisplay();
   amountdisplay();
   betdisplay();
   settextstyle(0,0,0);
  /**********************BETTING SELECTION************************/
   if((x>25&&x<57)&&(y>325&&y<350))
    {
     betc=1;
    }
   if((x>57&&x<90)&&(y>325&&y<350))
    {
     betc=2;
    }
   if((x>90&&x<123)&&(y>325&&y<350))
    {
     betc=3;
    }
   if((x>123&&x<156)&&(y>325&&y<350))
    {
     betc=4;
    }
   if((x>156&&x<189)&&(y>325&&y<350))
    {
     betc=5;
    }
   if((x>189&&x<221)&&(y>325&&y<350))
    {
     betc=6;
    }
   if((x>221&&x<254)&&(y>325&&y<350))
    {
     betc=7;
    }
   if((x>254&&x<287)&&(y>325&&y<350))
    {
     betc=8;
    }
   if((x>287&&x<319)&&(y>325&&y<350))
    {
     betc=9;
    }
   if((x>321&&x<352)&&(y>325&&y<350))
    {
     betc=19;
    }
   if((x>352&&x<385)&&(y>325&&y<350))
    {
     betc=20;
    }
   if((x>385&&x<418)&&(y>325&&y<350))
    {
     betc=21;
    }
   if((x>418&&x<451)&&(y>325&&y<350))
    {
     betc=22;
    }
   if((x>451&&x<483)&&(y>325&&y<350))
    {
     betc=23;
    }
   if((x>483&&x<517)&&(y>325&&y<350))
    {
     betc=24;
    }
   if((x>517&&x<550)&&(y>325&&y<350))
    {
     betc=25;
    }
   if((x>550&&x<582)&&(y>325&&y<350))
    {
     betc=26;
    }
   if((x>582&&x<615)&&(y>325&&y<350))
    {
     betc=27;
    }
/*****************************************************************/
   if((x>25&&x<57)&&(y>350&&y<375))
    {
     betc=10;
    }
   if((x>57&&x<90)&&(y>350&&y<375))
    {
     betc=11;
    }
   if((x>90&&x<123)&&(y>350&&y<375))
    {
     betc=12;
    }
   if((x>123&&x<156)&&(y>350&&y<375))
    {
     betc=13;
    }
   if((x>156&&x<189)&&(y>350&&y<375))
    {
     betc=14;
    }
   if((x>189&&x<221)&&(y>350&&y<375))
    {
     betc=15;
    }
   if((x>221&&x<254)&&(y>350&&y<375))
    {
     betc=16;
    }
   if((x>254&&x<287)&&(y>350&&y<375))
    {
     betc=17;
    }
   if((x>287&&x<319)&&(y>350&&y<375))
    {
     betc=18;
    }
   if((x>321&&x<352)&&(y>350&&y<375))
    {
     betc=28;
    }
   if((x>352&&x<385)&&(y>350&&y<375))
    {
     betc=29;
    }
   if((x>385&&x<418)&&(y>350&&y<375))
    {
     betc=30;
    }
   if((x>418&&x<451)&&(y>350&&y<375))
    {
     betc=31;
    }
   if((x>451&&x<483)&&(y>350&&y<375))
    {
     betc=32;
    }
   if((x>483&&x<517)&&(y>350&&y<375))
    {
     betc=33;
    }
   if((x>517&&x<550)&&(y>350&&y<375))
    {
     betc=34;
    }
   if((x>550&&x<582)&&(y>350&&y<375))
    {
     betc=35;
    }
   if((x>582&&x<615)&&(y>350&&y<375))
    {
     betc=36;
    }
/*************************************************************/
   if((x>25&&x<173)&&(y>375&&y<400))
    {
     betc=37;
    }
   if((x>173&&x<319)&&(y>375&&y<400))
    {
     betc=38;
    }
   if((x>25&&x<173)&&(y>400&&y<425))
    {
     betc=39;
    }
   if((x>173&&x<319)&&(y>400&&y<425))
    {
     betc=40;
    }
/***************************************************/
   if((x>321&&x<615)&&(y>375&&y<400))
    {
     betc=41;
    }
   if((x>321&&x<615)&&(y>400&&y<425))
    {
     betc=42;
    }
/****************************************************/
   if((x>25&&x<173)&&(y>425&&y<450))
    {
     betc=43;
    }
   if((x>173&&x<319)&&(y>425&&y<450))
    {
     betc=44;
    }
   if((x>321&&x<467)&&(y>425&&y<450))
    {
     betc=45;
    }
   if((x>467&&x<615)&&(y>425&&y<450))
    {
     betc=46;
    }
/*****************************************************/

/**************************AMOUNT SELECTION**********************/
   if((x>10&&x<89)&&(y>25&&y<50))
    {
     beta=10;
    }
   if((x>10&&x<89)&&(y>50&&y<75))
    {
     if(ntotalcredit<500)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=50;
    }
   if((x>10&&x<89)&&(y>75&&y<100))
    {
     if(ntotalcredit<100)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=100;
    }
   if((x>10&&x<89)&&(y>100&&y<125))
    {
     if(ntotalcredit<200)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=200;
    }
   if((x>10&&x<89)&&(y>125&&y<150))
    {
     if(ntotalcredit<300)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=300;
    }
   if((x>10&&x<89)&&(y>150&&y<175))
    {
     if(ntotalcredit<400)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=400;
    }
   if((x>10&&x<89)&&(y>175&&y<200))
    {
     if(ntotalcredit<500)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=500;
    }
   if((x>10&&x<89)&&(y>200&&y<225))
    {
     if(ntotalcredit<1000)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=1000;
    }
/************************************************************/
   if((x>91&&x<170)&&(y>25&&y<50))
    {
     if(ntotalcredit<1500)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=1500;
    }
   if((x>91&&x<170)&&(y>50&&y<75))
    {
     if(ntotalcredit<2000)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=2000;
    }
   if((x>91&&x<170)&&(y>75&&y<100))
    {
     if(ntotalcredit<2500)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=2500;
    }
   if((x>91&&x<170)&&(y>100&&y<125))
    {
     if(ntotalcredit<3000)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=3000;
    }
   if((x>91&&x<170)&&(y>125&&y<150))
    {
     if(ntotalcredit<3500)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=3500;
    }
   if((x>91&&x<170)&&(y>150&&y<175))
    {
     if(ntotalcredit<4000)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=4000;
    }
   if((x>91&&x<170)&&(y>175&&y<200))
    {
     if(ntotalcredit<4500)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=4500;
    }
   if((x>91&&x<170)&&(y>200&&y<225))
    {
     if(ntotalcredit<5000)
      {
       gotoxy(5,17);
       printf("INSUFFICIENT AMOUNT!!!");
      }
     else
      beta=5000;
    }

/******************************************************/
   if((x>475&&x<525)&&(y>75&&y<125))  //PLAY rectangle(475,75,525,125);
    {
     play();
     if(ntotalcredit<10)
      {
       goto line;
      }
    }
   if((x>575&&x<625)&&(y>20&&y<60))  //EXIT rectangle(575,20,625,60)
    {
     gameover();
     goto line;
    }
   if((x>475&&x<525)&&(y>20&&y<60))  //HELP rectangle(475,20,525,60);
    {
     helpmenu();
     goto fromhelpmenu;
    }
  }
}

line:
} //END OF MAIN

/****************************THE TITLE OF THE PROGRAM***************/
void title()
{
int m,n,b,v,h,g,count;
count=380;

for(h=1;h<=14;h++)
{
 count-=10;
 for(g=220;g<=count;g++)
 {
  setcolor(h);
  setlinestyle(0,0,3);
  circle(320,240,g);
  setcolor(15);
  circle(320,240,219);
  setfillstyle(1,h+1);
  floodfill(320,240,15);
  setcolor(0);
  settextstyle(4,0,7);
  outtextxy(160,90,"WELCOME");
  outtextxy(270,160,"TO");
  outtextxy(140,240,"COMPUTER");
  outtextxy(170,320,"GRAPHIC");
 }
}
getch();
delay(500);
for(m=0,n=479,b=0,v=639;m<639,n>0,b<479,v>0;m++,n--,b++,v--)
{
 setlinestyle(0,0,0);
 setcolor(0);
 delay(10);
 line(m,0,639,n);
 line(0,b,v,479);
}

delay(300);

setcolor(4);
settextstyle(4,0,9);
outtextxy(80,300,"ROULLETE");
settextstyle(0,0,0);
setlinestyle(0,0,0);
drawcircle();
roulletecolor();
roulletemove();
getch();

delay(500);
setcolor(0);
for(m=0,n=640;m<640,n>=0;m++,n--)
{
 delay(2);
 line(m,0,n,480);
}
for(m=0,n=480;m<480,n>=0;m++,n--)
{
 delay(2);
 line(0,m,640,n);
}

delay(500);
settextstyle(4,0,3);
setusercharsize(7,3,4,1);
for(i=0;i<1;i++)
{
 delay(500);
 setcolor(4);
 outtextxy(275,140,"05");
 delay(500);
 setcolor(0);
 outtextxy(275,140,"05");
}
for(i=0;i<1;i++)
{
 delay(500);
 setcolor(4);
 outtextxy(275,140,"04");
 delay(500);
 setcolor(0);
 outtextxy(275,140,"04");
}
for(i=0;i<1;i++)
{
 delay(500);
 setcolor(4);
 outtextxy(275,140,"03");
 delay(500);
 setcolor(0);
 outtextxy(275,140,"03");
}
for(i=0;i<1;i++)
{
 delay(500);
 setcolor(4);
 outtextxy(275,140,"02");
 delay(500);
 setcolor(0);
 outtextxy(275,140,"02");
}
for(i=0;i<1;i++)
{
 delay(500);
 setcolor(4);
 outtextxy(275,140,"01");
 delay(500);
 setcolor(0);
 outtextxy(275,140,"01");
}
delay(1000);
settextstyle(0,0,0);
}
/************************THE TITLE OF THE PROGRAM***************/





/*************************** PLAY FUNCTION ******************/
int play()
{
roulletemove();
randomize();
won=((rand()%36)+1);
//gotoxy(20,1);
//printf("WON=%02d",won);

setcolor(2);
amountdisplay();
betdisplay();

wwon=won;
wondisplay();

wx=dnx[won]+5;  // FOR PLACING THE BALL
wy=dny[won];
delay(50);
setcolor(15);
circle(wx,wy,7);
setfillstyle(1,15);
floodfill(wx,wy,15);
delay(2000);
dd=0;
checkbetcondition(won);
if(dd==0)
 {
  loseamount();
 }
displaycredit();
delay(1000);
if(beta<500&&beta>0)
 {
  delay(300);
 }
if(beta==0)
 {
  delay(500);
 }
if(won%2==0)
 {
  setcolor(4);
  circle(wx,wy,7);
  setfillstyle(1,4);
  floodfill(wx,wy,4);
 }
else
 {
  setcolor(0);
  circle(wx,wy,7);
  setfillstyle(1,0);
  floodfill(wx,wy,0);
 }

settextstyle(0,0,0);
drawcircle();
roulletecolor();
dialnumber(11);
delay(500);
setcolor(0);
amountdisplay();
betdisplay();

beta=0;
betc=0;
won=0;
if(ntotalcredit<10)
 {
  gameover();
  return 0;
 }
return 0;
}
/*************************** PLAY FUNCTION ******************/


/***************** DISPLAYS ***************************/
int amountdisplay()
{
settextstyle(1,0,0);
setusercharsize(1,1,1,1);
itoa(beta,c,10);
outtextxy(545,145,c);
return 0;
}

int wondisplay()
{
settextstyle(3,0,0);
setusercharsize(2,1,2,1);
if(wwon<10)
 {
  itoa(wwon,c,10);
  outtextxy(565,180,c);
 }
else
 {
  itoa(wwon,c,10);
  outtextxy(545,180,c);
 }
return 0;
}

int betdisplay()
{
settextstyle(1,0,0);
setusercharsize(2,3,2,3);
if(betc<37)
 {
  itoa(betc,c,10);
  outtextxy(570,273,c);
 }
if(betc==37)
 {
  betc1=1;
  betc2=9;
  itoa(betc1,c,10);
  outtextxy(545,273,c);
  outtextxy(575,273,"-");
  itoa(betc2,c,10);
  outtextxy(595,273,c);
 }
if(betc==38)
 {
  betc1=10;
  betc2=18;
  itoa(betc1,c,10);
  outtextxy(545,273,c);
  outtextxy(575,273,"-");
  itoa(betc2,c,10);
  outtextxy(595,273,c);
 }
if(betc==39)
 {
  betc1=19;
  betc2=27;
  itoa(betc1,c,10);
  outtextxy(545,273,c);
  outtextxy(575,273,"-");
  itoa(betc2,c,10);
  outtextxy(595,273,c);
 }
if(betc==40)
 {
  betc1=28;
  betc2=36;
  itoa(betc1,c,10);
  outtextxy(545,273,c);
  outtextxy(575,273,"-");
  itoa(betc2,c,10);
  outtextxy(595,273,c);
 }
if(betc==41)
 {
  betc1=1;
  betc2=18;
  itoa(betc1,c,10);
  outtextxy(545,273,c);
  outtextxy(575,273,"-");
  itoa(betc2,c,10);
  outtextxy(595,273,c);
 }
if(betc==42)
 {
  betc1=19;
  betc2=36;
  itoa(betc1,c,10);
  outtextxy(545,273,c);
  outtextxy(575,273,"-");
  itoa(betc2,c,10);
  outtextxy(595,273,c);
 }
if(betc==43)
 {
  outtextxy(562,273,"RED");
 }
if(betc==44)
 {
  outtextxy(553,273,"BLACK");
 }
if(betc==45)
 {
  outtextxy(560,273,"EVEN");
 }
if(betc==46)
 {
  outtextxy(563,273,"ODD");
 }
return 0;
}
/***************** DISPLAYS ***************************/





/************************ MAIN SCREEN **************************/
void mainscreen()
{
drawcircle();
roulletecolor();
dialnumber(11);
drawbettingmat();
drawbettingamount();
drawexit();
drawplay();
drawhelp();
setcolor(2);
outtextxy(500,155,"BET");
outtextxy(490,170,"AMOUNT");
outtextxy(445,220,"LUCKY NUMBER");
outtextxy(510,285,"BET");
rectangle(540,150,630,180);
rectangle(540,190,630,260);
rectangle(540,270,630,300);
showmouseptr();
displaycredit();
}
/************************ MAIN SCREEN **************************/

/******************** DRAW CIRCLE **********************/
void drawcircle()
{
int j,Q;
Q=360/36;
setcolor(15);
circle(320,150,140);
l=1;
k=1;
for(j=0;j<36;j++)
 {
  x1[l++]=320+140*cos(j*((Q*pi)/180));
  y1[k++]=150-140*sin(j*((Q*pi)/180));
  line(x1[j+1],y1[j+1],320,150);
 }
}
/******************** DRAW CIRCLE **********************/




//************ROULLETE COLORING*********************//
void roulletecolor()
{
i=15;
setfillstyle(1,4);
floodfill(400,125,i); //2
floodfill(390,95,i); //4
floodfill(370,70,i); //6
floodfill(340,60,i); //8
floodfill(310,60,i); //10
floodfill(280,70,i); //12
floodfill(255,85,i); //14
floodfill(235,110,i); //16
floodfill(230,140,i); //18
floodfill(230,170,i); //20
floodfill(240,200,i); //22
floodfill(265,220,i); //24
floodfill(295,230,i); //26
floodfill(325,235,i); //28
floodfill(355,230,i); //30
floodfill(380,210,i); //32
floodfill(395,185,i); //34
floodfill(400,155,i); //36

setfillstyle(1,0);
floodfill(400,140,i); //1
floodfill(395,110,i); //3
floodfill(380,80,i); //5
floodfill(355,65,i); //7
floodfill(325,60,i); //9
floodfill(295,65,i); //11
floodfill(265,75,i); //13
floodfill(245,95,i); //15
floodfill(230,125,i); //17
floodfill(230,155,i); //19
floodfill(235,185,i); //21
floodfill(250,210,i); //23
floodfill(280,225,i); //25
floodfill(310,230,i); //27
floodfill(340,230,i); //29
floodfill(365,220,i); //31
floodfill(390,200,i); //33
floodfill(400,170,i); //35
}
//************ROULLETE COLORING*********************//


/************ROULLETE ROTATING*********************/
void roulletemove()
{

int j,del;
randomize();
rotate=((rand()%50)+5);
if(ddel==0)
 {
  rotate=50;
 }
ddel=1;
//gotoxy(15,2);
//printf("%02d",rotate);

delay(500);
del=5;
for(j=1;j<=rotate;j++)
{
i=15;
delay(del);
setfillstyle(1,0);
floodfill(400,125,i); //2
floodfill(390,95,i); //4
floodfill(370,70,i); //6
floodfill(340,60,i); //8
floodfill(310,60,i); //10
floodfill(280,70,i); //12
floodfill(255,85,i); //14
floodfill(235,110,i); //16
floodfill(230,140,i); //18
floodfill(230,170,i); //20
floodfill(240,200,i); //22
floodfill(265,220,i); //24
floodfill(295,230,i); //26
floodfill(325,235,i); //28
floodfill(355,230,i); //30
floodfill(380,210,i); //32
floodfill(395,185,i); //34
floodfill(400,155,i); //36

setfillstyle(1,4);
floodfill(400,140,i); //1
floodfill(395,110,i); //3
floodfill(380,80,i); //5
floodfill(355,65,i); //7
floodfill(325,60,i); //9
floodfill(295,65,i); //11
floodfill(265,75,i); //13
floodfill(245,95,i); //15
floodfill(230,125,i); //17
floodfill(230,155,i); //19
floodfill(235,185,i); //21
floodfill(250,210,i); //23
floodfill(280,225,i); //25
floodfill(310,230,i); //27
floodfill(340,230,i); //29
floodfill(365,220,i); //31
floodfill(390,200,i); //33
floodfill(400,170,i); //35
dialnumber(11);

delay(del);
setfillstyle(1,4);
floodfill(400,125,i); //2
floodfill(390,95,i); //4
floodfill(370,70,i); //6
floodfill(340,60,i); //8
floodfill(310,60,i); //10
floodfill(280,70,i); //12
floodfill(255,85,i); //14
floodfill(235,110,i); //16
floodfill(230,140,i); //18
floodfill(230,170,i); //20
floodfill(240,200,i); //22
floodfill(265,220,i); //24
floodfill(295,230,i); //26
floodfill(325,235,i); //28
floodfill(355,230,i); //30
floodfill(380,210,i); //32
floodfill(395,185,i); //34
floodfill(400,155,i); //36

setfillstyle(1,0);
floodfill(400,140,i); //1
floodfill(395,110,i); //3
floodfill(380,80,i); //5
floodfill(355,65,i); //7
floodfill(325,60,i); //9
floodfill(295,65,i); //11
floodfill(265,75,i); //13
floodfill(245,95,i); //15
floodfill(230,125,i); //17
floodfill(230,155,i); //19
floodfill(235,185,i); //21
floodfill(250,210,i); //23
floodfill(280,225,i); //25
floodfill(310,230,i); //27
floodfill(340,230,i); //29
floodfill(365,220,i); //31
floodfill(390,200,i); //33
floodfill(400,170,i); //35
dialnumber(11);
del=del+1;
}
}
/************ROULLETE ROTATING*********************/


/*****************NUMBER ON THE DIAL******************************/
void dialnumber(int ch)
{
int j=1;
setcolor(ch);

itoa(j,c,10);
outtextxy(440,135,c); //1
j++;

itoa(j,c,10);
outtextxy(435,115,c); //2
j++;

itoa(j,c,10);
outtextxy(425,95,c); //3
j++;

itoa(j,c,10);
outtextxy(415,75,c); //4
j++;

itoa(j,c,10);
outtextxy(400,60,c); //5
j++;

itoa(j,c,10);
outtextxy(385,45,c); //6
j++;

itoa(j,c,10);
outtextxy(365,35,c); //7
j++;

itoa(j,c,10);
outtextxy(345,25,c); //8
j++;

itoa(j,c,10);
outtextxy(325,20,c); //9
j++;

itoa(j,c,10);
outtextxy(303,20,c); //10
j++;

itoa(j,c,10);
outtextxy(280,25,c); //11
j++;

itoa(j,c,10);
outtextxy(260,32,c); //12
j++;

itoa(j,c,10);
outtextxy(240,40,c); //13
j++;

itoa(j,c,10);
outtextxy(225,55,c); //14
j++;

itoa(j,c,10);
outtextxy(210,75,c); //15
j++;

itoa(j,c,10);
outtextxy(200,95,c); //16
j++;

itoa(j,c,10);
outtextxy(190,115,c); //17
j++;

itoa(j,c,10);
outtextxy(185,135,c); //18
j++;

itoa(j,c,10);
outtextxy(185,155,c); //19
j++;

itoa(j,c,10);
outtextxy(190,180,c); //20
j++;

itoa(j,c,10);
outtextxy(195,200,c); //21
j++;

itoa(j,c,10);
outtextxy(207,220,c); //22
j++;

itoa(j,c,10);
outtextxy(222,235,c); //23
j++;

itoa(j,c,10);
outtextxy(240,250,c); //24
j++;

itoa(j,c,10);
outtextxy(260,260,c); //25
j++;

itoa(j,c,10);
outtextxy(280,270,c); //26
j++;

itoa(j,c,10);
outtextxy(302,275,c); //27
j++;

itoa(j,c,10);
outtextxy(325,275,c); //28
j++;

itoa(j,c,10);
outtextxy(347,270,c); //29
j++;

itoa(j,c,10);
outtextxy(365,260,c); //30
j++;

itoa(j,c,10);
outtextxy(385,250,c); //31
j++;

itoa(j,c,10);
outtextxy(402,237,c); //32
j++;

itoa(j,c,10);
outtextxy(418,220,c); //33
j++;

itoa(j,c,10);
outtextxy(427,200,c); //34
j++;

itoa(j,c,10);
outtextxy(435,180,c); //35
j++;

itoa(j,c,10);
outtextxy(440,155,c); //36
j++;
/****************CO-ORDINATES OF ORIGINAL NUMBER ON DIAL*************/

j=1;

dnx[j]=440;
dny[j]=135;
j++;      //1

dnx[j]=435;
dny[j]=115;
j++;      //2

dnx[j]=425;
dny[j]=95;
j++;      //3

dnx[j]=415;
dny[j]=75;
j++;      //4

dnx[j]=400;
dny[j]=60;
j++;      //5

dnx[j]=385;
dny[j]=45;
j++;      //6

dnx[j]=365;
dny[j]=35;
j++;      //7

dnx[j]=345;
dny[j]=25;
j++;      //8

dnx[j]=325;
dny[j]=20;
j++;      //9

dnx[j]=303;
dny[j]=20;
j++;      //10

dnx[j]=280;
dny[j]=25;
j++;      //11

dnx[j]=260;
dny[j]=32;
j++;      //12

dnx[j]=240;
dny[j]=40;
j++;      //13

dnx[j]=225;
dny[j]=55;
j++;      //14

dnx[j]=210;
dny[j]=75;
j++;      //15

dnx[j]=200;
dny[j]=95;
j++;      //16

dnx[j]=190;
dny[j]=115;
j++;      //17

dnx[j]=185;
dny[j]=135;
j++;      //18

dnx[j]=185;
dny[j]=155;
j++;      //19

dnx[j]=190;
dny[j]=180;
j++;      //20

dnx[j]=195;
dny[j]=200;
j++;      //21

dnx[j]=207;
dny[j]=220;
j++;      //22

dnx[j]=222;
dny[j]=235;
j++;      //23

dnx[j]=240;
dny[j]=250;
j++;      //24

dnx[j]=260;
dny[j]=260;
j++;      //25

dnx[j]=280;
dny[j]=270;
j++;      //26

dnx[j]=302;
dny[j]=275;
j++;      //27

dnx[j]=325;
dny[j]=275;
j++;      //28

dnx[j]=347;
dny[j]=270;
j++;      //29

dnx[j]=365;
dny[j]=260;
j++;      //30

dnx[j]=385;
dny[j]=250;
j++;      //31

dnx[j]=402;
dny[j]=237;
j++;      //32

dnx[j]=418;
dny[j]=220;
j++;      //33

dnx[j]=427;
dny[j]=200;
j++;      //34

dnx[j]=435;
dny[j]=180;
j++;      //35

dnx[j]=440;
dny[j]=155;
j++;      //36

}
/*****************NUMBER ON THE DIAL******************************/


//***********************BETTING MAT*************************//
void drawbettingmat()
{
outtextxy(280,310,"BETTING MAT");
setcolor(15);
setlinestyle(0,0,3);
rectangle(25,325,615,450);
line(320,325,320,450);
setlinestyle(0,0,0);
line(25,350,615,350);
line(25,375,615,375);
line(25,400,615,400);
line(25,425,615,425);

cal=32.7778;
for(i=1;i<=18;i++)
{
 line(25+(i*cal),325,25+(i*cal),375);
}

for(i=1;i<=9;i++)
{
 if(i%2==0)
  {
   setfillstyle(1,4);
   floodfill((25+(i*cal))-20,337.5,15);
  }
 itoa(i,c,10);
 outtextxy((25+(i*cal))-20,337.5,c);
}

for(i=19;i<=27;i++)
{
 if(i%2==0)
  {
   setfillstyle(1,4);
   floodfill((25+((i-9)*cal))-20,337.5,15);
  }
 itoa(i,c,10);
 outtextxy((25+((i-9)*cal))-20,337.5,c);
}

for(i=10;i<=18;i++)
{
 if(i%2==0)
  {
   setfillstyle(1,4);
   floodfill((25+((i-10)*cal))+10,362.5,15);
  }
 itoa(i,c,10);
 outtextxy((25+((i-10)*cal))+10,362.5,c);
}

for(i=28;i<=36;i++)
{
 if(i%2==0)
  {
   setfillstyle(1,4);
   floodfill((25+((i-19)*cal))+10,362.5,15);
  }
 itoa(i,c,10);
 outtextxy((25+((i-19)*cal))+10,362.5,c);
}

cal=147.5;
for(i=1;i<=2;i++)
{
 line(25+(i*cal),375,25+(i*cal),425);
}

setfillstyle(1,4);
floodfill(70,385,15);
setfillstyle(1,4);
floodfill(215,410,15);
outtextxy(70,385,"1 -- 9");
outtextxy(215,385,"10 -- 18");
outtextxy(60,410,"19 -- 27");
outtextxy(215,410,"28 -- 36");


setfillstyle(1,4);
floodfill(440,385,15);
outtextxy(447,385,"1 -- 18");
outtextxy(440,410,"19 -- 36");

cal=147.5;
for(i=1;i<=4;i++)
{
 line(25+(i*cal),425,25+(i*cal),450);
}
setfillstyle(1,4);
floodfill(80,435,15);
setfillstyle(1,4);
floodfill(375,435,15);
outtextxy(80,435,"RED");
outtextxy(220,435,"BLACK");
outtextxy(375,435,"EVEN");
outtextxy(520,435,"ODD");
}
//***********************BETTING MAT*************************//


//**************************BETTING AMOUNT********************//
void drawbettingamount()
{
setcolor(11);
outtextxy(45,10,"BETTING AMOUNT");
setcolor(15);
setlinestyle(0,0,3);
rectangle(10,25,170,225);
setfillstyle(1,1);
floodfill(100,200,15);
setlinestyle(0,0,3);
line(90,25,90,225);
cal=25;
for(i=1;i<=8;i++)
{
 setlinestyle(0,0,0);
 line(10,25+(cal*i),170,25+(cal*i));
}
outtextxy(45,37,"10");
outtextxy(45,62,"50");
outtextxy(40,87,"100");
outtextxy(40,112,"200");
outtextxy(40,137,"300");
outtextxy(40,162,"400");
outtextxy(40,187,"500");
outtextxy(35,212,"1000");
outtextxy(115,37,"1500");
outtextxy(115,62,"2000");
outtextxy(115,87,"2500");
outtextxy(115,112,"3000");
outtextxy(115,137,"3500");
outtextxy(115,162,"4000");
outtextxy(115,187,"4500");
outtextxy(115,212,"5000");
}
/**************************BETTING AMOUNT********************/


/******************** CHECK BET CONDITION ***********************/
void checkbetcondition(int c)
{

if(c==betc)
 {
  wonamount(36); //36 times
  dd++;
 }

if(c>=1&&c<=9)
 {
  if(betc==37)
    {
     wonamount(4); //4 times
     dd++;
    }
 }

if(c>=10&&c<=18)
 {
  if(betc==38)
   {
    wonamount(4); //4 times
    dd++;
   }
 }


if(c>=19&&c<=27)
 {
  if(betc==39)
    {
     wonamount(4); //4 times
     dd++;
    }
 }

if(c>=28&&c<=36)
 {
  if(betc==40)
   {
    wonamount(4); //4 times
    dd++;
   }
 }

if(c>=1&&c<=18)
 {
  if(betc==41)
   {
    wonamount(2);  //2 times
    dd++;
   }
 }

if(c>=19&&c<=36)
 {
  if(betc==42)
    {
     wonamount(2);//2 times
     dd++;
    }
 }

if(c%2==0)
 {
  if(betc==45||betc==43)
   {
    wonamount(2);  //2 times
    dd++;
   }
 }

if(c%2==1)
 {
  if(betc==46||betc==44)
   {
    wonamount(2);   //2 times
    dd++;
   }
 }
}
/******************** CHECK BET CONDITION ***********************/



/************************ WON AMOUNT *********************/
void wonamount(int d)
{
 wamount=(d*beta)-beta;
 ntotalcredit=ptotalcredit+wamount;
}
/************************ WON AMOUNT *********************/


/****************** LOSE AMOUNT***********************/
void loseamount()
{
 if(betc>=1&&betc<=46)
  {
   lamount=beta;
   ntotalcredit=ptotalcredit-lamount;
  }
}
/****************** LOSE AMOUNT***********************/


/************************DISPLAY THE TOTAL CREDIT*********************/
void displaycredit()
{
setcolor(11);
settextstyle(0,0,0);
outtextxy(410,308,"TOTAL CREDIT=");
if(dd==0)
 {
  for(dcredit=ptotalcredit;dcredit>=ntotalcredit;dcredit--)
   {
    delay(3);
    gotoxy(66,20);
    printf("%09ld",dcredit);
   }
 }
else
 {
  for(dcredit=ptotalcredit;dcredit<=ntotalcredit;dcredit++)
   {
    delay(3);
    gotoxy(66,20);
    printf("%09ld",dcredit);
   }
 }
 ptotalcredit=ntotalcredit;
}
/************************DISPLAY THE TOTAL CREDIT*********************/


//******************EXIT************************//
void drawexit()
{
setcolor(15);
setlinestyle(0,0,3);
rectangle(575,20,625,60);
setfillstyle(1,2);
floodfill(580,40,15);
outtextxy(585,38,"EXIT");
setlinestyle(0,0,0);
}
//***************************EXIT***************//


//**************PLAY***********************//
void drawplay()
{
setcolor(15);
setlinestyle(0,0,3);
rectangle(475,75,525,125);
setfillstyle(1,4);
floodfill(500,100,15);
outtextxy(485,98,"PLAY");
setlinestyle(0,0,0);
}
//**************PLAY***********************//

//*******************HELP BUTTON**********************//
void drawhelp()
{
setcolor(15);
setlinestyle(0,0,3);
rectangle(475,20,525,60);
setfillstyle(1,5);
floodfill(490,40,15);
outtextxy(485,38,"HELP");
setlinestyle(0,0,0);
}
//*******************HELP BUTTON**********************//


/*********** BACK BUTTON *********************/
void back()
{
setcolor(15);
setlinestyle(0,0,3);
rectangle(575,20,625,60);
setfillstyle(1,5);
floodfill(580,40,15);
settextstyle(0,0,0);
outtextxy(585,38,"BACK");
setlinestyle(0,0,0);
}
/*********** BACK BUTTON *********************/


/*********** MORE HELP BUTTON *********************/
void more()
{
setcolor(15);
setlinestyle(0,0,3);
rectangle(575,120,625,160);
setfillstyle(1,1);
floodfill(580,140,15);
settextstyle(0,0,0);
outtextxy(585,138,"MORE");
setlinestyle(0,0,0);
}
/*********** MORE HELP BUTTON *********************/



/************* HELP MENU**********************/

int helpmenu()
{
i=9;
delay(10);
cleardevice();
back();
more();
setcolor(4);
setlinestyle(0,0,3);
rectangle(200,10,390,70);
setlinestyle(0,0,0);
settextstyle(1,0,4);
setusercharsize(2,1,2,1);
outtextxy(220,0,"HELP");
settextstyle(3,0,0);
setusercharsize(1,2,1,2);
setcolor(4);
outtextxy(170,80,"ROULETTE");
setcolor(i);
outtextxy(245,80,"is a game of probability.");
setcolor(4);
outtextxy(5,100,"PLAY:");
setlinestyle(0,0,3);
line(4,120,40,120);
setcolor(i);
outtextxy(5,125,"On clicking this option the player can start playing the game.");
setcolor(4);
outtextxy(5,150,"HELP:");
setlinestyle(0,0,3);
line(4,170,35,170);
setcolor(i);
outtextxy(5,175,"Here the basic instructions needed for playing the game would be available.");
setcolor(4);
outtextxy(5,200,"EXIT:");
setlinestyle(0,0,3);
line(4,220,30,220);
setcolor(i);
outtextxy(5,225,"By selecting this particular option the user can quit the game.");
setcolor(4);
outtextxy(5,250,"GAME DESCRIPTION :");
setlinestyle(0,0,3);
line(4,270,140,270);
setcolor(i);
outtextxy(5,275,"Initially the player will be given");
setcolor(4);
outtextxy(240,275,"5000");
setlinestyle(2,0,3);
line(237,294,282,294);
setcolor(i);
outtextxy(290,275,"points which he will be using to bet.");
outtextxy(5,295,"The basic motto is to EARN POINTS by betting on the various options available.");
setcolor(4);
outtextxy(5,315,"ROULETTE");
setcolor(i);
outtextxy(80,315,"is a game which is often found in casinos.");
outtextxy(5,335,"The roulette is a circular disc which is made up of 36 sectors with numbers of");
setcolor(4);
outtextxy(5,355,"1 to 36");
setcolor(i);
outtextxy(70,355,"written on it with alternate sectors having black and red colours.");
outtextxy(5,375,"The roulette is rotated and a");
setcolor(15);
outtextxy(230,375,"White");
setcolor(i);
outtextxy(275,375,"ball is tossed.");
outtextxy(5,395,"The player bets in which sector the ball would land and stay there till the ");
outtextxy(5,415,"roulette stops rotating.");
outtextxy(5,435,"The player wins or looses the points according to the position of the ball on");
outtextxy(5,455,"the roulette.");
setlinestyle(0,0,0);
settextstyle(0,0,0);
while(1)
 {
  getmousepos(&button,&x,&y);
  if((button &1)==1)
   {
    if((x>575&&x<625)&&(y>120&&y<160))  //MORE
rectangle(575,20,625,60);
     {
      morehelpmenu();
      return 0;
     }
   if((x>575&&x<625)&&(y>20&&y<60))  //BACK rectangle(575,20,625,60);
    {
     return 0;
    }
   }
 } //END OF WHILE
} //END OF HELPMENU
/************* HELP MENU**********************/





/*************MORE HELP MENU**********************/
int morehelpmenu()
{
i=9;
delay(100);
cleardevice();
back();
setcolor(4);
setlinestyle(0,0,3);
rectangle(200,10,390,70);
setlinestyle(0,0,0);
settextstyle(1,0,4);
setusercharsize(2,1,2,1);
outtextxy(220,0,"HELP");
settextstyle(3,0,0);
setusercharsize(1,1,1,1);
outtextxy(5,90,"RULES:");
line(5,130,95,130);

settextstyle(3,0,0);
setusercharsize(1,2,1,2);

setcolor(i);
outtextxy(5,135,"In this game the various options for betting are as follows :");
setcolor(4);
outtextxy(5,155,"1.");
setcolor(i);
outtextxy(20,155,"One can bet on individual numbers and if the outcomeis true then he would");
outtextxy(20,175," be given points in the ratio of");
setcolor(4);
outtextxy(260,175,"1:36");
outtextxy(5,195,"2.");
setcolor(i);
outtextxy(20,195,"One can bet whether the ball would end on a black or red sector.An award of");
setcolor(4);
outtextxy(20,215,"1:2");
setcolor(i);
outtextxy(50,215,"would be given if the outcome is true.");
setcolor(4);
outtextxy(5,235,"3.");
setcolor(i);
outtextxy(20,235,"Betting can be done as to whether the ball would land on an even or odd no.");
outtextxy(20,255,"Again an award of");
setcolor(4);
outtextxy(170,255,"1:2");
setcolor(i);
outtextxy(200,255,"would be given if the outcome is true.");
setcolor(4);
outtextxy(5,275,"4.");
setcolor(i);
outtextxy(20,275,"Betting can be done in range of numbers in which the ball might end up landing.");
outtextxy(20,295," The ranges would be divided into four regions:");
setcolor(4);
outtextxy(20,315,"1 to 9, 10 to 18, 19 to 27 and 28 to 36.");
setcolor(i);
outtextxy(20,335,"An award of");
setcolor(4);
outtextxy(117,335,"1:4");
setcolor(i);
outtextxy(145,335,"would be given if true or player would loose the amount betted.");
setcolor(4);
outtextxy(5,355,"5.");
setcolor(i);
outtextxy(20,355,"Also ranges can be chosen between");
setcolor(4);
outtextxy(290,355,"1 to 18  or  19 to 36.");
setcolor(i);
outtextxy(20,375,"If the outcome is true an award of");
setcolor(4);
outtextxy(305,375,"1:2");
setcolor(i);
outtextxy(335,375,"would be given.");
setcolor(4);
settextstyle(1,0,4);
setusercharsize(2,1,2,1);
outtextxy(100,400,"ALL THE BEST!!!");
setlinestyle(0,0,0);
settextstyle(0,0,0);
setusercharsize(1,2,1,2);

while(1)
 {
  getmousepos(&button,&x,&y);
  if((button &1)==1)
   {
    if((x>575&&x<625)&&(y>20&&y<60))  //BACK rectangle(575,20,625,60);
     {
      return 0;
     }
   }
 } //END OF WHILE
}// END OF MORE HELP
/*************MORE HELP MENU**********************/

/*********************** GAMEOVER ********************/
void gameover()
{
int m,n;
delay(2000);
setcolor(0);
for(m=0,n=640;m<640,n>=0;m++,n--)
{
 delay(5);
 line(m,0,n,480);
}
for(m=0,n=480;m<480,n>=0;m++,n--)
{
 delay(5);
 line(0,m,640,n);
}
delay(500);
settextstyle(3,0,5);
setcolor(10);
outtextxy(20,200,"SORRY!!! YOUR GAME IS OVER");
settextstyle(0,0,0);
drawexit();
showmouseptr();
while(1)
 {
  getmousepos(&button,&x,&y);
   if((button &1)==1)
    {
     if((x>575&&x<625)&&(y>20&&y<60))  //EXIT rectangle(575,20,625,60);
      {
       break;
      }
    }
 }
return;
}
/*********************** GAMEOVER ********************/


/*
for(j=1;j<=10;j++)
{
 delay(500);
 setfillstyle(1,4);
 floodfill(360,140,15); //2
 delay(500);
 setfillstyle(1,0);
 floodfill(360,140,15); //2
}
*/


/*
floodfill(360,140,i); //2
floodfill(360,120,i); //4
floodfill(360,100,i); //6
floodfill(340,80,i);  //8
floodfill(308,80,i);  //10
floodfill(300,100,i); //12
floodfill(285,120,i); //14
floodfill(270,130,i); //16
floodfill(255,145,i); //18
floodfill(240,170,i); //20
floodfill(210,220,i); //22
floodfill(260,230,i); //24
floodfill(300,230,i); //26
floodfill(325,230,i); //28
floodfill(355,220,i); //30
floodfill(365,200,i); //32
floodfill(370,175,i); //34
floodfill(360,155,i); //36

delay(500);
setfillstyle(1,0);
i=15;
floodfill(360,140,i); //2
floodfill(360,120,i); //4
floodfill(360,100,i); //6
floodfill(340,80,i);  //8
floodfill(308,80,i);  //10
floodfill(300,100,i); //12
floodfill(285,120,i); //14
floodfill(270,130,i); //16
floodfill(255,145,i); //18
floodfill(240,170,i); //20
floodfill(210,220,i); //22
floodfill(260,230,i); //24
floodfill(300,230,i); //26
floodfill(325,230,i); //28
floodfill(355,220,i); //30
floodfill(365,200,i); //32
floodfill(370,175,i); //34
floodfill(360,155,i); //36
*/

/*
for(i=1;i<=6;i++)
 {
  itoa(i,c,10);
  outtextxy(x1[i]-20,y1[i]-10,c);
 }
for(i=7;i<=8;i++)
 {
  itoa(i,c,10);
  outtextxy(x1[i]-20,y1[i],c);
 }
i=9;
itoa(i,c,10);
outtextxy(x1[9]-15,y1[9]+3,c);
for(i=10;i<=12;i++)
 {
  itoa(i,c,10);
  outtextxy(x1[i]-16,y1[i]+9,c);
 }
for(i=14;i>=13;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i]-10,y1[i]+10,c);
 }
for(i=18;i>=15;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i],y1[i]+10,c);
 }
for(i=23;i>=19;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i]+10,y1[i]+3,c);
 }
for(i=27;i>=24;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i]+7,y1[i]-5,c);
 }
for(i=29;i>=28;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i]+5,y1[i]-10,c);
 }
for(i=31;i>=30;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i],y1[i]-15,c);
 }
for(i=33;i>=32;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i]-5,y1[i]-15,c);
 }
for(i=36;i>=34;i--)
 {
  itoa(i,c,10);
  outtextxy(x1[i]-10,y1[i]-15,c);
 }
*/


/*
floodfillouttextxy(400,125,"*"); //2
floodfillouttextxy(390,95,"*"); //4
floodfillouttextxy(370,70,"*"); //6
floodfillouttextxy(340,60,"*"); //8
floodfillouttextxy(310,60,"*"); //10
floodfillouttextxy(280,70,"*"); //12
floodfillouttextxy(255,85,"*"); //14
floodfillouttextxy(235,110,"*"); //16
floodfillouttextxy(230,140,"*"); //18
floodfillouttextxy(230,170,"*"); //20
floodfillouttextxy(240,200,"*"); //22
floodfillouttextxy(265,220,"*"); //24
floodfillouttextxy(295,230,"*"); //26
floodfillouttextxy(325,235,"*"); //28
floodfillouttextxy(355,230,"*"); //30
floodfillouttextxy(380,210,"*"); //32
floodfillouttextxy(395,185,"*"); //34
floodfillouttextxy(400,155,"*"); //36

setcolor(4);
floodfillouttextxy(400,140,"*"); //1
floodfillouttextxy(395,110,"*"); //3
floodfillouttextxy(380,80,"*"); //5
floodfillouttextxy(355,65,"*"); //7
floodfillouttextxy(325,60,"*"); //9
floodfillouttextxy(295,65,"*"); //11
floodfillouttextxy(265,75,"*"); //13
floodfillouttextxy(245,95,"*"); //15
floodfillouttextxy(230,125,"*"); //17
floodfillouttextxy(230,155,"*"); //19
floodfillouttextxy(235,185,"*"); //21
floodfillouttextxy(250,210,"*"); //23
floodfillouttextxy(280,225,"*"); //25
floodfillouttextxy(310,230,"*"); //27
floodfillouttextxy(340,230,"*"); //29
floodfillouttextxy(365,220,"*"); //31
floodfillouttextxy(390,200,"*"); //33
floodfillouttextxy(400,170,"*"); //35
*/

/*
void changedial(int z)
{

int w,dnxx[100],dnyy[100];
for(w=z;w<=(2*rotate);w++)
 {
  dnxx[w]=dnx[w+1];
  dnyy[w]=dny[w+1];
  itoa(w,c,10);
  outtextxy(dnxx[z],dnyy[z],c);
 }
}*/

/*
{
settextstyle(4,0,7);
setusercharsize(3,1,3,1);
//setbkcolor(11);
setcolor(2);
setlinestyle(1,0,3);
rectangle(1,1,639,479);
outtextxy(70,150,"Welcome To");
//outtextxy(65,175," JIGAR'S");
//outtextxy(100,295,"Program...");
delay(1000);
for(m=0,n=479,b=0,v=639;m<639,n>0,b<479,v>0;m++,n--,b++,v--)
{
 setlinestyle(0,0,0);
 setcolor(0);
 delay(5);
 line(m,0,639,n);
 line(0,b,v,479);
}
//cleardevice();
//setbkcolor(0);
}
*/



