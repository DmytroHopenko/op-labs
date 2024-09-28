#include <stdio.h>
#include <math.h>

// Task 2

double calculate_angle(double a, double b, double c) {
    return acos((b*b + c*c - a*a) / (2 * b * c)) * (180.0 / M_PI);
}

//

// Task 3

void print_hundreds(int digit) {
    switch(digit) {
        case 1: printf("One hundred "); break;
        case 2: printf("Two hundred "); break;
        case 3: printf("Three hundred "); break;
        case 4: printf("Four hundred "); break;
        case 5: printf("Five hundred "); break;
        case 6: printf("Six hundred "); break;
        case 7: printf("Seven hundred "); break;
        case 8: printf("Eight hundred "); break;
        case 9: printf("Nine hundred "); break;
    }
}

void print_tens(int digit) {
    switch(digit) {
        case 2: printf("twenty "); break;
        case 3: printf("thirty "); break;
        case 4: printf("forty "); break;
        case 5: printf("fifty "); break;
        case 6: printf("sixty "); break;
        case 7: printf("seventy "); break;
        case 8: printf("eighty "); break;
        case 9: printf("ninety "); break;
    }
}

void print_ones(int digit) {
    switch(digit) {
        case 1: printf("one"); break;
        case 2: printf("two"); break;
        case 3: printf("three"); break;
        case 4: printf("four"); break;
        case 5: printf("five"); break;
        case 6: printf("six"); break;
        case 7: printf("seven"); break;
        case 8: printf("eight"); break;
        case 9: printf("nine"); break;
    }
}

void print_teens(int digit) {
    switch(digit) {
        case 10: printf("ten"); break;
        case 11: printf("eleven"); break;
        case 12: printf("twelve"); break;
        case 13: printf("thirteen"); break;
        case 14: printf("fourteen"); break;
        case 15: printf("fifteen"); break;
        case 16: printf("sixteen"); break;
        case 17: printf("seventeen"); break;
        case 18: printf("eighteen"); break;
        case 19: printf("nineteen"); break;
    }
}

void number_to_words(int number) {
    int hundreds = number / 100;
    int tens = (number % 100) / 10;
    int ones = number % 10;

    if (hundreds > 0) {
        print_hundreds(hundreds);
    }

    if (tens == 1) {
        print_teens(tens * 10 + ones);
    } else {
        if (tens > 1) {
            print_tens(tens);
        }
        if (ones > 0) {
            print_ones(ones);
        }
    }

    printf("\n");
}

//

int main(void) {
    //Task 1

    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    if (num1 == num2) {
        printf("%d = %d\n", num1, num2);
    } else {
        num1 > num2 ? printf("%d > %d\n", num1, num2) : printf("%d < %d\n", num1, num2);
    }

    // Task 2

    int a, b, c;
    double angle_A, angle_B, angle_C;

    printf("Enter first side: ");
    scanf("%d", &a);
    printf("Enter second side: ");
    scanf("%d", &b);
    printf("Enter third side: ");
    scanf("%d", &c);

    if((a > 0 && b > 0 && c > 0) && ( a + b > c && b + c > a && a + c > b)) {
        angle_A = calculate_angle(a, b, c);
        angle_B = calculate_angle(b, a, c);
        angle_C = calculate_angle(c, a, b);
        if( a == b && b == c) {
            printf("Triangle is equilateral and the angles are sharp");
        }else if(a == b && a != c ) {
            printf("Triangle is isosceles\n");
            if(a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b) {
                printf("But also has right angle\n");
            }else {
                if(angle_A > 90 || angle_B > 90 || angle_C > 90) {
                    printf("Angle is obtuse\n");
                }else {
                    printf("Angle is sharp");
                }
            }
        }else {
            printf("Triangle is versatile\n");
            if(a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b) {
                printf("But also has right angle\n");
            }else {
                if(angle_A > 90 || angle_B > 90 || angle_C > 90) {
                    printf("Angle is obtuse\n");
                }else {
                    printf("Angle is sharp");
                }
            }
        }
    }else {
        printf("The side must be greater than 0 or a triangle cannot exist\n");
    }

    // Task 3

    int number;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    if (number > 99 && number < 1000) {
        number_to_words(number);
    }else {
        printf("The number is invalid");
    }

    return 0;
}
