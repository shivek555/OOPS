#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter value of a:");
    scanf("%d",&a);
    printf("enter value of b:");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;
    printf("New value of a is %d and value of b is %d",a,b);
    return 0;
}