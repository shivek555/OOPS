#include<stdio.h>
int main()
{
    int a,b,c=0;
    printf("enter first number:");
    scanf("%d",&a);
    printf("enter the number you want to add in first number:");
    scanf("%d",&b);
    c=a+b;
    printf("sum of two numbers given is : %d\n",c);
    c=a-b;
    printf("substraction of two numbers given is : %d\n",c);
    c=a*b;
    printf("miltiplication of two numbers given is : %d\n",c);
    c=a/b;
    printf("division of two numbers given is : %d",c);
    return 0;
}