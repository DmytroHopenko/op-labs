#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Task 1

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }

    for( int i = 2; i <= num /2; i++) {
        if( num % i == 0) {
            return false;
        }
    }
    return true;
}
//

//Task 2

int sum_recursive(int num) {
    if (num > 100) {
        return 0;
    }
    return num + sum_recursive(num + 1);
}

//

//Task 3

double equation(double N, double A, double x) {
    return N * x + A;
}

double bisection(double N, double A, double left, double right, double tolerance) {
    double middle;
    while ((right - left) >= tolerance) {
        middle = (left + right) / 2;
        if (equation(N, A, middle) == 0.0) {
            return middle;
        }

        if (equation(N, A, left) * equation(N, A, middle) < 0) {
            right = middle;
        } else {
            left = middle;
        }
    }
    return middle;
}

//

int main(void){
    // Task 1
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(is_prime(num)) {
        printf("%d is a prime number\n", num);
    }else {
        printf("%d is not a prime number\n", num);
    }

    // Task 2

    int numInList;

    printf("Enter a list of numbers: ");
    scanf("%d", &numInList);

    int result = sum_recursive(numInList);

    printf("The sum from your number in list to 100 is: %d\n", result);

    // Task 3

    int N, A;

    printf("Enter information to solve equation by bisection method: \n");

    printf("Enter a list of numbers: ");
    scanf("%d", &N);
    printf("Enter your age:");
    scanf("%d", &A);

    double left = -100, right = 100;
    double tolerance = 0.00001;

    double root = bisection(N, A, left, right, tolerance);

    printf("The root of your equation is: %.5f\n", root);

    return 0;
}
