 # include <stdio.h>
int main(){
 /*float a;
 float f;
 float b;
 float c;
 float d;
 float e;
 float g;*/
 int c1;
 char a;
 int d;
 int b;
 int c;
 printf("enter number a");
 scanf("%d",&d);
 printf("enter number b");
 printf("%d",&b);
 c=b;
 b=d;
 d=c;
 printf("%d,%d",a,b);

/* printf("enter radius of circle: ");
 scanf("%f",&a);
 f=22/7*a*a;
 printf("area of circle is %f\n",f);
 printf("enter length of rectangle: ");
 scanf("%f",&d);
 printf("enter breadth of rectangle: ");
 scanf("%f",&b);
 c=d*b;
 printf("area of rectangle is %f\n",c);
 printf("enter length of triangle: ");
 scanf("%f",&e);
 g=sqrt((.75))*e*e;
 printf("area of eqvi triangle is %f:",g);*/
printf(" enter the letter of which you wanna know ascii value:");
scanf("%c",&a);
printf("ASCII value of %c = %d", a, a);
 scanf("%d",&c1);
 return 0;
}