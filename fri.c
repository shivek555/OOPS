/*
#include <stdio.h>
void main(){
int n,i,count=0,countcube=0,countsq=0,x;
printf("enter number of natural number you want");
scanf("%d",&n);
for (i=1;i<=n;i++)
{
printf("%d\n",i);
}
for (i=1;i<=n;i++)
{
count+=i;
}
printf("sum of %d natural number is %d\n",n,count);
for (i=1;i<=n;i++)
{
countsq+=(i*i);
}
printf("sum of square %d natural number is %d\n",n,countsq);
for (i=1;i<=n;i++)
{
countcube+=(i*i*i);
}
printf("sum of cube of %d natural number is %d\n",n,countcube);
scanf("%d\n",&x);
}
#include <stdio.h>

int main() {

   const int maxInput = 10;
   int i,Y;
   double number, average, sum = 0.0;

   for (i = 1; i <= maxInput; ++i) {
      printf("%d. Enter a number: ", i);
      scanf("%lf", &number);

      // go to jump if the user enters a negative number
      if (number < 0.0) {
	 goto jump;
      }
      sum += number;
   }

jump:
   average = sum / (i - 1);
   printf("Sum = %.2f\n", sum);
   printf("Average = %.2f", average);
   scanf("%d",&Y);
   return 0;
}
#include<stdio.h>
int main ()
{
  int n,m,count;
  printf ("enter a number to print table:");
  scanf ("%d",&n);

  count = 1;

start:
  if (count <= 10)
    {
      printf ("%d*%d=%d\n", n, count, n * count);
      count++;
      goto start;
    }
  scanf("%d",&m);
  return 0;
}  
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch,x;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (isalpha(ch))
	printf("%c is an alphabet.\n", ch);
    else if (isalnum(ch))
	printf("%c is a number.\n", ch);
    else if (isprint(ch))
	printf("%c is a special character.\n", ch);
    else
	printf("%c is not a printable character.\n", ch);
    scanf("%d",&x);
    return 0;
}
#include <stdio.h>
int main()
{
int amount, nohun, nofifty, noten, nofive, notwo, noone, total;
printf ("Enter the amount: ");
scanf("%d", &amount);
nohun = amount/100;
amount = amount % 100;
nofifty = amount/50;
amount = amount % 50;
noten = amount/10;
amount = amount %10;
nofive = amount/5;
amount = amount %5;
notwo = amount/2;
amount = amount %2;
noone = amount/1;
amount = amount %1;94
total = nohun + nofifty + noten + nofive + notwo + noone;
printf ("Smallest number of notes = %d\n", total);
return 0;
}*/
#include <stdio.h>
void main(){
char S,Q;
int yos,x;
printf("enter gender (M=male ,F=female),Year of service , Qualification(P=postgraduate and G=graduate)");
scanf("%c",&S);
scanf("%d",&yos);
scanf("%c",&Q);
if (S=='M'){
if (yos>=10){if (Q=='P'){printf("your salary is 11000 rs \n");}else{printf("your salary is 10000 rs \n");}}
else{if (Q=='P'){printf("your salary is 10000 rs \n");}else{printf("your salary is 7000 rs \n");}}
}
else{if (yos>=10){if (Q=='P'){printf("your salary is 12000 rs \n");}else{printf("your salary is 9000 rs \n");}}
else{if (Q=='P'){printf("your salary is 10000 rs \n");}else{printf("your salary is 6000 rs \n");}}}
scanf("%d,&x);
}