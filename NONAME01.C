# include<stdio.h>
void main()
{int YOJ,CY,X,Y,d=5000;
 printf("enter year of joining:");
 scanf("%d",&YOJ);
 printf("enter current year:");
 scanf("%d",&CY);
 Y=CY-YOJ;
 if(Y>=3){printf("your GROSS SALARY is BASIC SALARY + %d",d);}
 else{printf("your GROSS SALARY is BASIC SALARY ONLY");}
 scanf("%d",&X);
}