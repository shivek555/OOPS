#include<stdio.h>
int main()
{
    int r,c,a;
    printf("enter radius of the circle:");
    scanf("%d",&r);
    c=2*22/7*r;
    printf("circumference of circle is : %d\n",c);
    a=22/7*r*r;
    printf("area of circle is : %d",a);
    return 0;
}