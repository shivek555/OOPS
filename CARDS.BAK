#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void Screen();
void Rule();
void Shuffle();
void Player1();
void Player2();
void check();

char player1_name[50]={'/0'};
char player2_name[50]={'/0'};
char player1_card[500]={'/0'};
char player2_card[500]={'/0'};
char choice1;
char choice2;
int player1_card_no[500];
int player2_card_no[500];
int no_assigned[500];
int last_turn_won=0,l1,l2,p_one=0,index1,index2,win=0;
int p_two=0,value_of_card1,value_of_card2,last_turn;

void main()
{
	int i;
	char ch;
	clrscr();
	Rule();
	do
	{
		clrscr();
		Shuffle();
		clrscr();
		l1=strlen(player1_name);
		l2=strlen(player2_name);
		Player1();
		Player2();
		if(value_of_card2>value_of_card1)
		{
			last_turn_won=2;

			p_two=p_two+1;
			player2_card[p_two]=choice1;
			player2_card_no[p_two]=value_of_card1;

			player1_card[index1]='*';
			player1_card_no[index1]=-1;

			Screen();

			printf("%s WINS THE BET!! Press any key........",player2_name);
			getch();
			choice1='/0';
			choice2='/0';

		}
		else
		{
			last_turn_won=1;

			p_one=p_one+1;
			player1_card[p_one]=choice2;
			player1_card_no[p_one]=value_of_card2;

			player2_card[index2]='*';
			player2_card_no[index2]=-1;

			Screen();
			printf("%s WINS THE BET!! Press any key.....",player1_name);
			getch();
			choice1='/0';
			choice2='/0';
		}
		for(;;)
		{
			win=0;
			check();
			if(win==1)
				break;
			switch(last_turn_won)
			{
				case 1:
					Player1();
					last_turn=1;
					break;
				case 2:
					Player2();
					last_turn=2;
					break;
			}
			if(last_turn==1)
				Player2();
			else
				Player1();
			if(value_of_card2>value_of_card1)
			{
				last_turn_won=2;

				p_two=p_two+1;
				player2_card[p_two]=choice1;
				player2_card_no[p_two]=value_of_card1;
				value_of_card1=0;
				value_of_card2=0;
				player1_card[index1]='*';
				player1_card_no[index1]=-1;

				Screen();
				printf("%s WINS THE BET!! Press any key......",player2_name);
				getch();
				choice1='/0';
				choice2='/0';
			}
			else
			{
				last_turn_won=1;

				p_one=p_one+1;
				player1_card[p_one]=choice2;
				player1_card_no[p_one]=value_of_card2;
				value_of_card1=0;
				value_of_card2=0;
				player2_card[index2]='*';
				player2_card_no[index2]=-1;

				Screen();
				printf("%s WINS THE BET!! Press any key......",player1_name);
				getch();
				choice1='/0';
				choice2='/0';
			}
		}
		getch();
		clrscr();
		printf("DO YOU WANT TO PLAY AGAIN(y/n) ? ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
	getch();
}

void Screen()
{

	int i;
	clrscr();
	printf("A      2      Z\n");
	printf("---------------\n");
	printf("");
	printf("PLAYER 1 ");
	for(i=1;i<=l1+4;i++)
		printf("*");
	printf("? %s ?",player1_name);
	for(i=1;i<=l1+4;i++)
		printf("*");
	printf("CARDS: ");
	for(i=1;i<=p_one;i++)
	{
		if(player1_card[i]!='*')
			printf("%c ",player1_card[i]);
		else
			continue;
	}
	printf("");
	for(i=1;i<=79;i++)
		printf("-");
	printf("PLAYER 2");
	for(i=1;i<=l2+4;i++)
		printf("*");
	printf("? %s ? ",player2_name);
	for(i=1;i<=l2+4;i++)
		printf("*");
	printf("CARDS: ");
	for(i=1;i<=p_two;i++)
	{
		if(player2_card[i]!='*')
			printf("%c ",player2_card[i]);
		else
			continue;
	}
	printf("");
	for(i=1;i<=79;i++)
		printf("-");
	printf("			PLAYER1   PLAYER2");
	printf("			-----------------");
	printf("			?");
	printf("  %c",choice1);
	printf("   ?");
	printf("   %c",choice2);
	printf("   ?");
	printf("			-----------------");
}
void Rule()
{
	printf("				A      2      Z\n");
	printf("***************");
	printf("\n");
	printf("This game is played between two players.Each player will be given");
	printf("13 cards with alphabet written on them.Each card will have a distinct");
	printf("value between 0 and 1000.These numbers are not visible to the players.");
	printf("Each player is required to throw a card on his turn.If the card thrown");
	printf("by a player has higher value than the card thrown by the former player");
	printf("then that card is won by the player of the highest card value.Then it");
	printf("his turn to throw a card nest.Player with all the card is the winner.");
	printf("Press any key........");
	getch();
}

void Shuffle()
{
	int seed1,seed2,i,j,k,m=0,x,rd,rd1,flag1=0,flag=0;
	printf("Enter the name of the player 1 : ");
	gets(player1_name);
	printf("Enter the name of the player 2 : ");
	gets(player2_name);
	do
	{
		printf("%s,PLEASE ENTER A NO.(BETWEEN 1 AND 1000) TO SHUFFLE YOUR CARDS:",player1_name);
		scanf("%d",&seed1);
		if(seed1<1 || seed1>1000)
			printf("WRONG ENTRY!!");
	}while(seed1<1 || seed1>1000);
	do
	{
		printf("%s,PLEASE ENTER A NO.(BETWEEN 1 AND 1000)DIFFERENT",player2_name);
		printf("FROM %s TO SHUFFLE YOUR CARDS :",player1_name);
		scanf("%d",&seed2);
		if(seed2==seed1 || seed2<1 || seed2>1000)
			printf("WRONG ENTRY!!");
		getch();
	}while(seed2==seed1 || seed2<1 || seed2>1000);

	/*Shuffling the card of player 1*/
	srand(seed1);
	for(i=1;i<=13;i++)
	{
		do
		{
			flag1=0;
			rd1=rand()%1000+1;
			for(k=1;k<=p_one;k++)
			{
				if(rd1==player1_card_no[k])
					flag1++;
			}
		}while(flag1>0);
		flag1=0;
		player1_card_no[i]=rd1;
		no_assigned[++m]=player1_card_no[i];
		p_one=p_one+1;
		player1_card[p_one]=(char)(64+i);
	}

	/*Shuffling the card of player 2*/
	srand(seed2);
	for(i=1;i<=13;i++)
	{
		do
		{
			flag=0;
			rd=rand()%1000+1;
			for(j=1;j<=13;j++)
			{
				if(rd==no_assigned[j])
					flag++;
				else
				{
					for(k=1;k<=p_two;k++)
					{
						if(rd==player2_card_no[k])
							flag++;
					}

				}
			}
		}while(flag>0);
		flag=0;
		player2_card_no[i]=rd;
		no_assigned[++m]=player2_card_no[i];
		p_two=p_two+1;
		player2_card[p_two]=(char)(77+i);
	}
}

void Player1()
{
	char ch1;

	int flag=0,i;
	clrscr();
	do
	{
		choice1='/0';
		Screen();
		printf("TURN FOR %s :",player1_name);
		printf("Enter your choice : ");
		fflush(stdin);
		scanf("%c",&ch1);
		choice1=toupper(ch1);
		for(i=1;i<=p_one;i++)
		{
			if(player1_card[i]==choice1)
			{
			       value_of_card1=player1_card_no[i];
			       index1=i;
			       flag=1;
			       break;
			}
			else
				continue;
		}
	}while(flag==0);
}

void Player2()
{
	int i,flag=0;
	char ch2;
	clrscr();
	do
	{
		choice2='/0';
		Screen();
		printf("TURN FOR %s :",player2_name);
		printf("Enter your choice : ");
		scanf("%c",&ch2);
		choice2=toupper(ch2);
		for(i=1;i<=p_two;i++)
		{
			if(player2_card[i]==choice2)
			{
			       value_of_card2=player2_card_no[i];
			       index2=i;
			       flag=1;
			       break;
			}
			else
				continue;
		}
	}while(flag==0);
}

void check()
{
	int i;
	int flag1=0,flag2=0;
	for(i=1;i<=p_one;i++)
	{
		if(player1_card[i]=='*')
			flag1++;
	}
	if(flag1==p_one)
	{
		printf("CONGRATULATIONS %s !! YOU HAVE WON.",player2_name);
		win=1;
		return;
	}
	for(i=1;i<=p_two;i++)
	{
		if(player2_card[i]=='*')
			flag2++;
	}
	if(flag2==p_two)
	{
		printf("CONGRATULATIONS %s !! YOU HAVE WON.",player1_name);
		win=1;
		return;
	}
	win=0;
}