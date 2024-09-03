#include<stdio.h>
int main()
{
    int x,a;
    printf("enter a number: ");
    scanf("%d",&x);
    if(x<0)
        a=-1;
    if(x==0)
        a=0;
    if (x>0)
        a=1;
    switch(a)
    {
        case -1: printf("%d is a negetive number",x); break;
        case 0: printf("%d is a zero",x); break;
        case 1: printf("%d is a positive number",x); break;
    }
    return 0;
}