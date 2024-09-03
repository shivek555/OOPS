#include <stdio.h>
/*
int grade_steel(float hardness, float carbon_content, float tensile_strength) {
    int grade = 5;
    int conditions_met = 0;

    if (hardness > 50) {
        conditions_met++;
    }

    if (carbon_content < 0.7) {
        conditions_met++;
    }

    if (tensile_strength > 5600) {
        conditions_met++;
    }

    if (conditions_met == 3) {
        grade = 10;
    } else if (conditions_met == 2) {
        if (hardness > 50 && carbon_content < 0.7) {
            grade = 9;
        } else if (carbon_content < 0.7 && tensile_strength > 5600) {
            grade = 8;
        } else if (hardness > 50 && tensile_strength > 5600) {
            grade = 7;
        }
    } else if (conditions_met == 1) {
        grade = 6;
    }

    return grade;
}

int main() {
    float hardness, carbon_content, tensile_strength;

    printf("Enter hardness: ");
    while (scanf("%f", &hardness) != 1) {
        printf("Invalid input. Enter hardness: ");
        while (getchar() != '\n');
    }

    printf("Enter carbon content: ");
    while (scanf("%f", &carbon_content) != 1) {
        printf("Invalid input. Enter carbon content: ");
        while (getchar() != '\n');
    }

    printf("Enter tensile strength: ");
    while (scanf("%f", &tensile_strength) != 1) {
        printf("Invalid input. Enter tensile strength: ");
        while (getchar() != '\n');
    }

    int grade = grade_steel(hardness, carbon_content, tensile_strength);

    printf("Grade of the steel is: %d\n", grade);

    return 0;
}*/

int grade_steel(float hardness, float carbon_content, float tensile_strength) {
    int grade = 5;
    int conditions_met = 0;

    if (hardness > 50) {
        conditions_met++;
    }

    if (carbon_content < 0.7) {
	conditions_met++;
    }

    if (tensile_strength > 5600) {
	conditions_met++;
    }

    switch (conditions_met) {
	case 3:
	    grade = 10;
	    break;
	case 2:
	    switch (hardness > 50) {
		case 1:
		    switch (carbon_content < 0.7) {
			case 1:
			    grade = 9;
			    break;
			case 0:
			    grade=7;
			    break;
		    }
		    break;
		case 0:
		    switch (tensile_strength > 5600) {
			case 1:
			    grade = 8;
			    break;
		    }
		    break;
	    }
	    break;
	case 1:
	    grade = 6;
	    break;
    }

    return grade;
}

int main() {
    float hardness, carbon_content, tensile_strength;
    int grade,x;
    printf("Enter hardness: ");
    while (scanf("%f", &hardness) != 1) {
	printf("Invalid input. Enter hardness: ");
	while (getchar() != '\n');
    }

    printf("Enter carbon content: ");
    while (scanf("%f", &carbon_content) != 1) {
	printf("Invalid input. Enter carbon content: ");
	while (getchar() != '\n');
    }

    printf("Enter tensile strength: ");
    while (scanf("%f", &tensile_strength) != 1) {
	printf("Invalid input. Enter tensile strength: ");
	while (getchar() != '\n');
    }

    grade = grade_steel(hardness, carbon_content, tensile_strength);

    printf("Grade of the steel is: %d\n", grade);
    scanf("%d",&x);
    return 0;
}