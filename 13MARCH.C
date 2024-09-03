#include<stdio.h>
/*
void main(){
int i,j;
for (i=1; i<=5;i++)
{for (j=1;j<=i ;j++)
{
 printf("%d",j);
}
printf("\n");
}
}

int main() 
{ 

    int rows = 5;
    int i,j,k;


    // first loop is for printing the rows

    for (i = 0; i < rows; i++) {

  

        // loop for printing leading whitespaces 

	for (j = 0; j < 2 * (rows - i) - 1; j++) {

            printf(" "); 

	}



	// loop for printing * character

	for( k = 0; k <= i; k++) {

	    printf("* ");

	}

	printf("\n");

    }

    return 0;
}*/
#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int spaces = 2 * x - 2;
int 1,j;
    for( i = 1; i <= x;i++)
    {
      for(j = 0;j < i;j++)
      {
        printf("*");
      }
      for(j=0;j<spaces;j++)
      {
        printf(" ");
      }
      for(j =0;j<i;j++)
      {
        printf("*");
      }
      printf("\n");
      spaces-=2;
    }
    spaces = 0;
    for(i = x; i > 0;i--)
    {
      for(j = 0;j < i;j++)
      {
        printf("*");
      }
      for(j=0;j<spaces;j++)
      {
        printf(" ");
      }
      for(j =0;j<i;j++)
      {
        printf("*");
      }
      printf("\n");
      spaces+=2;
    }
    
    
}