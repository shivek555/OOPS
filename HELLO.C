#include <stdio.h>
/*void main()
{
	int a;
	printf("enter a number");
	scanf("%d",&a);
if (a%5==0&&a%11==0){printf("%d is divisible by 5 and 11",a);}
else{printf("%d is not divisible by 5 and 11",a);}
}*/
int main() {
    int day,x;

    // Input the day number (1 to 7)
    printf("Enter a day number (1-7): ");
    scanf("%d", &day);

    // Check and print the corresponding day name
    if (day==1) {
	    printf("SUNDAY\n");
	    }
	else if(day==2){
	    printf("MONDAY\n");
	    }
	else if(day==3){
	    printf("TUESDAY\n");
	    }
	else if(day==4){
	    printf("WEDNESDAY\n");}

	else if(day==5){
	    printf("THURSDAY\n");  }

	else if(day==6){
	    printf("FRIDAY\n");     }

	else if(day==7){
	    printf("SATURDAY\n");    }

	else{
	    printf("Invalid day number. Please enter a number between 1 and 7.\n");}
	scanf("%d",&x);
    return 100;
}