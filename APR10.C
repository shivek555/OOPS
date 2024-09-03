#include <stdio.h>
#include <conio.h>
int main(){

struct student{
int roll_no;
char name [80];
float fees;
char DOB [80];
} ;
struct student studi;
clrscr();
printf("\n Enter the roll number: ");
scanf("%d", &studi.roll_no);
printf("\n Enter the name: ");
scanf("%s", studi.name);
printf("\n Enter the fees: ");
scanf("%f", &studl.fees);
printf("\n Enter the DOB:");
scanf("%s", studi. DOB);
printf("\n ***STUDENTS DETAILS***");
printf("\n ROLL No. %d", studi.roll_no);
printf("\n NAME", studi.name);
printf("\n FEeS %f", studi.fees);
printf("\n DOBs", studi. DOB);
getch();
return 0;
}