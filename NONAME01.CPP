#include <stdio.h>
void main(){
 int a,b=5,c=11;
 printf("enter a number");
 scanf("%d",&a);
 if(a%b==0 && a%c==0){printf("number %d is divisible by %d and %d\n",a,b,c);
 }
 else{printf("number %d is not divisible by %d and %d\n",a,b,c);}
}