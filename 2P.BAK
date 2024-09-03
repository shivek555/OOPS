//IMPLEMENTATION OF OPPOSITE GAME
//first user1 should play with numpad keys
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<iostream.h>
#include<stdio.h>
#include<dos.h>



extern short int user1=1,user2=0;
extern short int array[8][8]={{0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,2,2,0,0,0},
                  {0,0,0,14,14,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0}};
extern short int sp_color=0; // to create generic functions
extern short int current_yellow=2,current_green=2;
extern short int color=0;
extern short int color_back=0;
extern short int write=0;    //to fill boxes during user profile execution
extern short int user1_validity_checked=0, user2_validity_checked=1;
//signals to check user's validity by condition(which avoid repeat calling of big function in while loop)
extern short int gameover1=0,gameover2=0; // if both got 1 means, end thegame(consider total_poxes)
extern short int total_boxes=0;           //to check whether all boxesfilled or not
extern short int print_box=0;   // to exe fillbox only called bu user profiles(to avoid printing of boxes while checking validity)
extern short int validity_enabler=0; //signal used to get validity of userby checking it in by entering fillbox()

//single player game variables
extern short int dir_array[8]={0,0,0,0,0,0,0,0};      //0 to 7 represent  corresponding directions
//extern short int max_dir=0;          //direction number which achieved  max value
extern short int max_pixel_i=0;      //this i and j is to store pixel     postion at which max_dir have to applay at final
extern short int max_pixel_j=0;
extern short int max_value=0;                //maximum value of the filled pixels among all directionl algorithms
void get_max(int i, int j);

int select_box(int ,int );
void delay();
void backbox(int ,int );
void update_array();
void initial_setup();
void sound1();
void sound2();
//TO DRAW BOX AROUND CENRAL PIXEL
void setbox(int i,int j)
{
  int x,y,count=0;
   for(x=i-17; x<= (i+18) ;x++)
     for(y=j-17; y<= (j+18); y++)
   { //count++;
    if(x==i-17 || x==i+18 || y==j-17 || y==j+18)
      {
    if((count++)%3==0)
    putpixel(x,y,WHITE);
      }
    }
}

// TO DRAW YELLOW AND green BALL INSIDE THE BOX
void fillbox(int i, int j,int c)
{
int x,y,s1,s2;
validity_enabler=1;
  if(print_box)
  {
   for(x=i-17+4; x<= (i+18-4) ;x++)
     for(y=j-17+4; y<= (j+18-4); y++)
      putpixel(x,y,c);


    s1=(x-70)/35;
    s2=(y-140)/35;
    array[s1][s2]=c;
  //  printf("%d ",c );
   }
}

void display_date()
{
// gotoxy(1,1);
  gotoxy(10,3);
  printf("");
  printf("		   T H E  G A M E  O P P O S I T E   ");
  printf("		*************************************");
gotoxy(10,28);
printf("%s",__DATE__);
printf("	 %s",__TIME__);
gotoxy(55,27);
}

void sound1()
{
int i;

  for(i=700;i<=800;i=i+25)
    {
    sound(i);
    delay(5);
    nosound();
     }

}




void movement(int *i, int *j,char ch)
{  //int x=*i,y=*j;
   // sound1();
    switch(ch)
    {case 118:
     case 50:                              //down key
           *j=*j+35;
           if(*j > (140+245))
        *j=140;
           break;
     case 100:
     case 52:                            //left key
         *i=*i-35;
          if(*i < 70)
          *i=70+245;
         break;

     case 103:
     case 54:                //right key
         *i=*i+35;
         if(*i > (70+245))
          *i=70;
         break;

     case 114:
     case 56:                       //up-key
           *j=*j-35;
           if(*j < 140)
           *j=140+245;
           break;
    }

}


    void whitebox(int i,int j)
    { int x,y;
     for(x=i-17+2; x<= (i+18-2) ;x++)
     for(y=j-17+2; y<= (j+18-2); y++)
      putpixel(x,y,15);

    }


    void backbox(int i, int j)
    {
      int x,y;
     for(x=i-17+2; x<= (i+18-2) ;x++)
       for(y=j-17+2; y<= (j+18-2); y++)
    {if(x==i-17+2 || x==i-17+3 || x==i+18-2 || x==i+18-3 || y==j-17+2 ||
y==j-17+3 || y==j+18-2 || y==j+18-3)
     putpixel(x,y,0);
    }
     print_box=1;         //eneble the printing of box
    fillbox(i,j,color_back);
    print_box=0;          //disable the printing of box
     }



void delay()
{
int x,y,z;
for(x=0;x<20000;x++)
for(y=0;y<10000;y++);

}


/*ALGORITHMS TO CHECK SURROUNDING BOXES OF BOX UNDER CONSIDERATION, IN
ALL DIRECTIONS*/


   int checkdown(int x, int y)
   {
    if(y > (140+245))   //boundary checking
     { write=0;
       return(0);
     }

     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

               //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
             //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkdown(x,(y+35));       //recursive calling
       }
      if(write)
       {
       dir_array[0]=dir_array[0]+1;  //one value get incremented per one box fill

       fillbox(x,y,color);
       fillbox(x,y-35, color);
     if(user1)
     color_back=YELLOW;   //back box color should be re-defined(if modified  anything means)
     if(user2)
     color_back=GREEN;
       }
       return(0);
    }


    int checkup(int x, int y)
    {
      if(y < 140)   //boundary checking
     { write=0;
       return(0);
     }

     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];;  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

	       //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
	     //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkup(x,(y-35));       //recursive calling
       }
      if(write)
       {
     dir_array[1]=dir_array[1]+1;  //one value get incremented per one box fill

       fillbox(x,y,color);
       fillbox(x,y+35, color);
     if(user1)
     color_back=YELLOW;   //back box color should be re-defined(if modifiedanything means)
     if(user2)
     color_back=GREEN;
       }
       return(0);
    }


    int checkleft(int x, int y)
    {
      if(x< 70)   //boundary checking
     { write=0;
       return(0);
     }

     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

	       //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
	     //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkleft((x-35),y);       //recursive calling
       }
      if(write)
       {
     dir_array[2]=dir_array[2]+1;  //one value get incremented per one box fill

       fillbox(x,y,color);
       fillbox((x+35) ,y, color);
     if(user1)
     color_back=YELLOW;   //back box color should be re-defined(if modifiedanything means)
     if(user2)
     color_back=GREEN;
       }
       return(0);
    }



    int checkright(int x, int y)
    {
      if(x > (70+245))   //boundary checking
     { write=0;
       return(0);
     }

     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

               //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
             //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkright((x+35),y);       //recursive calling
       }
      if(write)
       {
       dir_array[3]=dir_array[3]+1;  //one value get incremented per onebox fill

       fillbox(x,y,color);
       fillbox((x-35) ,y, color);
     if(user1)
     color_back=YELLOW;   //back box color should be re-defined(if modifiedanything means)
     if(user2)
     color_back=GREEN;
       }
       return(0);
    }



    int checkdia1(int x, int y)         //starts from clock wise
    {
      if((x > (70+245)) || ( y < (140)))   //boundary checking
     { write=0;
       return(0);
     }

     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

               //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
             //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkdia1((x+35),(y-35));       //recursive calling
       }
      if(write)
       {
       dir_array[4]=dir_array[4]+1;  //one value get incremented per onebox fill

       fillbox(x,y,color);
       fillbox((x-35) ,(y+35), color);
     if(user1)
     color_back=YELLOW;   //back box color should be re-defined(if modifiedanything means)
     if(user2)
     color_back=GREEN;
       }
       return(0);
    }



    int checkdia2(int x, int y)
    {
      if((x > (70+245)) || ( y > (140+245)))   //boundary checking
     { write=0;
       return(0);
     }

     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

	       //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
	     //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkdia2((x+35),(y+35));       //recursive calling
       }
      if(write)
       {
    dir_array[5]=dir_array[5]+1;  //one value get incremented per one box  fill

       fillbox(x,y,color);
       fillbox((x-35) ,(y-35), color);
     if(user1)
     color_back=YELLOW;   //back box color should be re-defined(if modifiedanything means)
     if(user2)
     color_back=GREEN;
       }
       return(0);
    }


    int checkdia3(int x, int y)
    {
      if((x <70) || ( y > (140+245)))   //boundary checking
     { write=0;
       return(0);
     }
     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

	       //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
	     //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkdia3((x-35),(y+35));       //recursive calling
       }
      if(write)
       {
       dir_array[6]=dir_array[6]+1;  //one value get incremented per one   box fill

       fillbox(x,y,color);
       fillbox((x+35) ,(y-35), color);
     if(user1)
      {color_back=YELLOW;   //back box color should be re-defined(if modifiedanything means)

      }
     if(user2)
      {color_back=GREEN;
      }
       }
       return(0);
    }



     int checkdia4(int x, int y)
    {
      if((x <70) || ( y < 140))   //boundary checking
     { write=0;
       return(0);
     }
     int s1,s2;
     s1=(x-70)/35;
     s2=(y-140)/35;
    int color1=array[s1][s2];  //checking for next blank box

    if(color1==BLACK)
    {
     write=0;
     return 0;
    }

	       //reading next pixel,(1st time, it will be white)
    if(color1==color)    //color should be re-defined in user-profile
      {
	     //if it contains no element in its sorroundings
       return(0);
       }
    if(color1==sp_color)
      {
       write=1;
       checkdia4((x-35),(y-35));       //recursive calling
       }
      if(write)
       {
    dir_array[7]=dir_array[7]+1;  //one value get incremented per one box fill

       fillbox(x,y,color);
       fillbox((x+35) ,(y+35), color);
     if(user1)
       { color_back=YELLOW;   //back box color should be re-defined(ifmodified anything means)
		   //to check whether user1 striked even he is valid, by comparing  it with its previous value
       }
     if(user2)
      {
       color_back=GREEN;
      }

    }
       return(0);
    }



void check_all_dir(int x, int y, int print)
{
       if(print==1)   //in case of this function called by userprofilesthen onlly print
       print_box=1;
       else print_box=0;
      write=0;
       update_array();
       checkdown(x,(y+35));
       checkup(x,(y-35));
       checkleft((x-35), y);
       checkright((x+35),y);
       checkdia1(x+35, y-35);
       checkdia2(x+35, y+35);
       checkdia3(x-35, y+35);
       checkdia4(x-35, y-35);


}

      void update_array()
      {
       int i,j;
    current_yellow=0;        //reset values
    current_green=0;         // no use of previous yellow and green
    for(i=0;i<8;i++)
     for(j=0;j<8;j++)
      {
	if(array[i][j]==14) current_yellow++;
	if(array[i][j]==2) current_green++;
      }
      total_boxes=current_yellow+current_green;
      }


      int user1_validity()               //should return 1 on success
      { int i,j;
       int col1,col2;
       col1=color;
       col2=sp_color;
       color=YELLOW;
       sp_color=GREEN;
       write=0;
       validity_enabler=0;
       update_array();                 // no need, remove it later on
       for(i=70; i<=(70+245); i=i+35)
     for(j=140; j<=(140+245); j=j+35)
      {
	  if(validity_enabler)  //which cannot reach after checking  array[7][7]
	return(1);  //if user1 valid to fill box
	   int s1,s2;
	   s1=(i-70)/35;
	   s2=(j-140)/35;

	if(array[s1][s2]==0)
	  check_all_dir(i,j,0);
      }
      if(validity_enabler)
       return(1);                   //which is to check whether      validity_enabler got rised after checking for array[7][7]
      color=col1;
      sp_color=col2;
      return(0);
       }




      int user2_validity()               //should return 1 on success
      { int i,j;
      int col1,col2;
      col1=color;
      col2=sp_color;
       color=GREEN;
       sp_color=YELLOW;
       write=0;
       validity_enabler=0;
       update_array();              // no need, remove it later on
       for(i=70; i<=(70+245); i=i+35)
     for(j=140; j<=(140+245); j=j+35)
      {
       if(validity_enabler)
	 return(1);  //if user1 valid to fill box
	  int s1,s2;
	  s1=(i-70)/35;
	  s2=(j-140)/35;

       if(array[s1][s2]==0)
	 check_all_dir(i,j,0);
      }

       if(validity_enabler)
       return(1);                   //which is to check whether validity_enabler got rised after checking for array[7][7]

       color=col1;
       sp_color=col2;
      return(0);
       }






   //press esc to come out of the following loop

int select_box(int i, int j)            //cursor block
{

int x,y,t1,t2;
char ch;
int gdriver=DETECT,gmode=0;
initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");


initial_setup();
gotoxy(0,0);
gotoxy(52,13);
printf("%d%d",current_yellow,current_green); //to display
gotoxy(0,0);



   while(1)
   { x=i;
     y=j;
    char ch;
    display_date();
    color_back=getpixel(i,j);
    update_array();
    whitebox(i,j);
  update_array();

	 //TO CHECK USER 1 VALIDITY

      if((!user1_validity_checked) && user1)    //if user1 validity not yet checked
       {   user1_validity_checked=1;
       int color_back_retriver=color_back;

       if(user1_validity())
	{ user1=1;
          user2=0;
          gameover1=0;
        gotoxy(0,0);            //to display validity below score board
        gotoxy(50,15);
        printf(" play1");
        gotoxy(0,0);
       gotoxy(64,15);
       printf("        ");
       gotoxy(0,0);
        }

      else                     //disable user1 and eneble user2
      {
       user1=0;
       user2=1;
       gameover1=1;
       user2_validity_checked=0;
         gotoxy(0,0);            //to display validity below score board
         gotoxy(50,15);
         printf(" NO   ");
         gotoxy(0,0);
      }
      color_back=color_back_retriver;


       }

       //TO CHECK USER2 VALIDITY

       if((!user2_validity_checked) && user2)
     {
        int color_back_retriver=color_back;
      user2_validity_checked=1;
      if(user2_validity())
         {
          user2=1;
          user1=0;
          gameover2=0;
          gotoxy(0,0);            //to display validity below score board
          gotoxy(64,15);
          printf("   play2");
          gotoxy(0,0);
          gotoxy(50,15);
          printf("      ");
          gotoxy(0,0);;
         }

      else
         {
         gameover2=1;
         user2=0;
         user1=1;
         user1_validity_checked=0;
                 //to display validity below score board
         gotoxy(64,15);
         printf(" NO    ");

         }
          color_back=color_back_retriver;

     }

       if((gameover1==1) && (gameover2==1) || total_boxes==64 ||
current_yellow==0 || current_green==0)
    {
    update_array();
      gotoxy(1,1);
       if( current_yellow > current_green)
      printf("**************** USER1 IS THE WINNER*************");

     else if(current_yellow<current_green)

      printf("**************** USER2 IS THE WINNER*************");

      else
      printf("************ M A T C H  IS  D R A W *************");
      printf(" **************** G A M E  O V E R*************");
      return(0);
    }


    ch=getch();
    if(ch==27) break;  //ESC butten  action

    if(ch==13 && user1)            //if enter key pressed by user1
      {       int yellow_p, yellow_c;
	   color=YELLOW;
	   sp_color=GREEN;
	   write=0;
	  update_array(); // update previous values of array
	  yellow_p=current_yellow;

	   int s1,s2;
	   s1=(x-70)/35;
	   s2=(y-140)/35;
	   if(array[s1][s2]==0)        //if current box is empty

	   check_all_dir(x,y,1);      // calls 8 directional alg

	   update_array();  //update rescent values of array
	   yellow_c=current_yellow;

	   if(yellow_c != yellow_p) //if user really strikes any box, thenonly switch to yser2
	{
	   user1=0;
	   user2=1;
	   user2_validity_checked=0;
	   sound1();
	   gotoxy(52,13);
	   printf("%d			%d",current_yellow,current_green); //todisplay initial score

	}

      }


    if(ch==102 && user2)          //if f key pressed by user2
      {
      int green_c, green_p;
       color=GREEN;
       sp_color=YELLOW;

       write=0;
       update_array();
       green_p=current_green;    //saved green value, bfore filling new boxes


    int s1,s2;
    s1=(x-70)/435;
    s2=(y-140)/35;
    if(array[s1][s2]==0)        //if current box is empty
    check_all_dir(x,y,1);

       update_array();
       green_c=current_green;   //new green values
      if(green_c != green_p)
    {
     sound1();
     user2=0;
     user1=1;
     user1_validity_checked=0;
     gotoxy(52,13);
     printf("%d			%d",current_yellow,current_green); //to display initial score
    }
      }

    movement(&i,&j,ch);               //movemwnts to the curser block

    backbox(x,y);                     //fill box with its previous color
    }                                       //press arrow keys of NUM_PAD
  return(0);
}



void initial()
{ print_box=1;
   fillbox(175,245,2);
   fillbox(210,245,2);
   fillbox(175,280,14);
   fillbox(210,280,14);
   print_box=0;
}

void putbox()    //which fixes central points of each box and call function to draw the box
{
  for(int i=70;i<350;i=i+35)
   for(int j=140;j<420;j=j+35)
     {
//       putpixel(i,j,RED);   //to create a red dot at center of each box
       setbox(i,j);
     }
}


void outline(int ch)
{
  int x,y;
	 //starts from 51(70-17-2),121(140-17-2)
     for(x=50; x<=(51+284); x++)
      for(y=120; y<=(121+284); y++)
if(x==50 || x==51 || x==334 || x==335 || y==120 || y==121 || y==404 ||
y==405)
     putpixel(x,y,ch);
}



void get_max(int i, int j)
{
int x;
int max=0;

   for(x=0;x<8;x++)
    max=max+dir_array[x];

    if(max_value<max)
    {
     max_value=max;
     max_pixel_i=i;
     max_pixel_j=j;
    }
}


void print_computer()
{
int x,y;
update_array();
x=max_pixel_i;
y=max_pixel_j;

print_box=1;
color_back=GREEN;
check_all_dir(x,y,1);
}


int single_player_game()
{
int gdriver=DETECT,gmode=0;
initgraph(&gdriver, &gmode, "c:\tc\bgi");
int i=70;
int j=140;
int x,y;
initial_setup();
gotoxy(0,0);
gotoxy(52,13);
printf("%d			%d   ",current_yellow,current_green); //to display initial score
gotoxy(0,0);

while(1)
   { x=i;
     y=j;
    char ch;
    display_date();
    color_back=getpixel(i,j);
    update_array();
    whitebox(i,j);
  update_array();
    gotoxy(0,0);
    gotoxy(52,13);



         //TO CHECK USER 1 VALIDITY

      if((!user1_validity_checked) && user1)    //if user1 validity not yet checked
       {   user1_validity_checked=1;
       int color_back_retriver=color_back;
       if(user1_validity())
	{ user1=1;
	  user2=0;
	  gameover1=0;
	gotoxy(1,1);            //to display validity below score board
	gotoxy(50,15);
	printf(" play1");
	gotoxy(1,1);
	gotoxy(64,15);
	printf("         ");
	gotoxy(1,1);
	}

      else                     //disable user1 and eneble user2
      {
       user1=0;
       user2=1;
       gameover1=1;
       user2_validity_checked=0;
	 gotoxy(1,1);            //to display validity below score board
	 gotoxy(50,15);
	 printf(" NO   ");
	 gotoxy(1,1);
      }
      color_back=color_back_retriver;


       }



    ch=getch();
    if(ch==27) break;  //ESC butten  action

    if(ch==13 && user1)            //if enter key pressed by user1
      {       int yellow_p, yellow_c;
           color=YELLOW;
           sp_color=GREEN;
           write=0;
          update_array(); // update previous values of array
          yellow_p=current_yellow;

           int s1,s2;
           s1=(x-70)/35;
           s2=(y-140)/35;
           if(array[s1][s2]==0)        //if current box is empty

           check_all_dir(x,y,1);      // calls 8 directional alg

           update_array();  //update rescent values of array
           yellow_c=current_yellow;

	   if(yellow_c != yellow_p) //if user really strikes any box, then only switch to yser2
	{
	   sound1();
	   user1=0;
	   user2=1;
	   user2_validity_checked=0;

	   gotoxy(52,13);
	   printf("%d			%d      ",current_yellow,current_green);
//to display initial score
      //  printf("%d			%d   ",current_yellow,current_green);
	}

      }

       gotoxy(0,0);
       gotoxy(52,13);

       //TO CHECK USER2 VALIDITY

       if((!user2_validity_checked) && user2)
     {
	int color_back_retriver=color_back;
      user2_validity_checked=1;
      if(user2_validity())
	 {
	  user2=1;
	  user1=0;
	  gameover2=0;
		//to display validity below score board
	  gotoxy(64,15);
	  printf("computer");
	  gotoxy(50,15);
	  printf("      ");

	 }

      else
	 {
	 gameover2=1;
	 user2=0;
	 user1=1;
	 user1_validity_checked=0;
		       //to display validity below score board
	 gotoxy(64,15);
	 printf("  NO    ");

	 }
	  color_back=color_back_retriver;

     }

       if((gameover1==1) && (gameover2==1) || total_boxes==64 ||
current_yellow==0 || current_green==0)
    {

      gotoxy(1,1);
      update_array();
     if( current_yellow > current_green)
      printf("**************** USER1 IS THE WINNER*************");

    else if(current_yellow<current_green)
      printf(" ************ * COMPUTER IS THE WINNER*************");

      else
      printf(" ************ M A T C H  IS  D R A W *************");
       gotoxy(1,1);
      printf("**************** G A M E  O V E R*************");
      return(0);
    }



    if(user2)          //its the turn of computer
      {
     // int green_c, green_p;

     int m,n;
     int color_back_retriver=color_back;
       color=GREEN;
       sp_color=YELLOW;
       max_value=0;

       write=0;
       update_array();

    for(int t=0;t<8; t++) //restting of direction values
      dir_array[t]=0;

		//priority part hv to b written


       for(m=0;m<8;m++)
    for(n=0;n<8;n++)
     if(array[m][n]==0)
       { int a,b;
         a=70+(m*35);
         b=140+(n*35);

         for(int t=0;t<8;t++)
           dir_array[t]=0;

         check_all_dir(a,b,0);

         get_max(a,b);
       }

     delay();          //let the user1 see his results
     delay();
     print_computer(); //if comp(user2) valid means i wil print automaticallywithout
	       // user interaction, so not checking for pixel color upgradation of array[][]
     sound1();

    color_back=color_back_retriver;
    if(getpixel(i,j)==GREEN)            //if white box interacts with newly paved green boxes means, xtract back color and proceed
      color_back=GREEN;

     user2=0;
     user1=1;
     user1_validity_checked=0;
     update_array();
     gotoxy(52,13);
     printf("%d			  %d       ",current_yellow,current_green); //to display initial score
   //  printf("%d			%d   ",current_yellow,current_green);
     }


    movement(&i,&j,ch);               //movemwnts to the curser block

    backbox(x,y);                     //fill box with its previous color
		      //press arrow keys of NUM_PAD

     } //end of while loop

  return(0);
}







void display_instr()
{
printf("This is the game already implemented in Nokia 2300 set. you are the user1 always and got to play using YELLOW color.");
printf("first is user1  turn, you have to put the white box at appropriate place and have to press ENTER(num pad) key to fill the boxes with yellow,");
printf("so that your cursor current position should be at empty box and contains Green boxes in between your cursor and another Yellow box,that yellow box belongs to ");
printf("upward,downward,leftside,rightside or any diagonal direction to your cursor.");
printf("Same thing to user2 also, he got to play with Greenboxe's. ");
printf("USER1 CONTROL KEYS:");
printf("*******************");
printf("The directional keys in num-pad and enter key in num-pad");
printf("USER2 CONTROL KEYS:");
printf("*********************");
printf(" D = left movement \n  R = up-ward movement\n G = right movement\n V= down-ward movement\n F = Enter key");
getch();
clrscr();
}

int preamble()
{ int options;
    while(1)
     {
    printf(" SELECT YOUR OPTION ");
    printf("******************");
    printf(" 1. Instructions\n 2. Single player\n game(player2=computer)");
    printf(" 3. Two player game \n");
    printf(" 4. Exit from the game ");
    scanf("%d",&options);
    clrscr();
    switch(options)
     {
      case 1:display_instr(); break;
      case 2: single_player_game(); return(0);
      case 3:select_box(70,140); return(0);
      case 4:exit(0);
      default: printf("please enter the valid choice");

     }
     }

}

void initial_setup()
{
outline(RED);
putbox();     //INITILLY DRAW OUTLINE BOX
initial();    //INITIAL FILLED BOX DRAWING
int x,y;
gotoxy(50,9);
printf("user1	      user2");
gotoxy(0,0);

		  //print user1 yellow box(above score)
for(x=400; x<=420 ;x++)
     for(y=162; y<= 182; y++)
      putpixel(x,y,14);

for(x=545; x<=565 ;x++)         //to print user2 green box
     for(y=162; y<= 182; y++)
      putpixel(x,y,2);

}

main()
{
//int gdriver=DETECT,gmode=0;
clrscr();
  preamble();      //OPTIONS GIVEN MENU

   getch();

   closegraph();

//   printf("GAME OVER");

     return 0;
}