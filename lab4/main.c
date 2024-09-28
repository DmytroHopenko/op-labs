#include <stdio.h>
#include <math.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        int bit = ( num >> i ) & 1;

        printf("%d", bit);
    }
    printf("\n");
}

void calculate(int a, int b, int c) {
    double action, root1, root2;
    if(a == 0){
        printf("It's linear equation");
        return;
    };
    if(b == 0) {
        action = ( c * (-1) ) / a;
        if(action >= 0) {
            root1=sqrt(action);
            root2=sqrt(action) * (-1);
            printf("The result x1 is %f\n", root1);
            printf("The result x2 is %f\n", root2);
        }
    }else {
        action = b * b - 4*a*c;
        printf("%f\n", action);
        if(action > 0) {
            root1 = (-b - sqrt(action)) / (2 * a);
            root2 = (-b + sqrt(action)) / (2 * a);
            printf("The result x1 is %f\n", root1);
            printf("The result x2 is %f\n", root2);
        }else if(action == 0) {
            root1 = (-b - sqrt(action))/ (2 * a);
            printf("The result x1=x2 = %f\n", root1);
        }else {
            printf("This equation hasn't roots");
        }
    }
}

int main(void){
    int decimal_1, decimal_2;

    int i = 0;

    //Part of 3 task
        int *pointer;
    //

    printf("Enter first decimal number:");
    scanf("%d", &decimal_1);
    printf("Enter second decimal number:");
    scanf("%d", &decimal_2);

    // 3 task
        pointer = &decimal_1;
    //

    //Arithmetic operators
    printf("Arithmetic operators: \n");
    printf("A + B = %d\n", decimal_1 + decimal_2);
    printf("A - B = %d\n", decimal_1 - decimal_2);
    printf("A * B = %d\n", decimal_1 * decimal_2);
    printf("A / B = %d\n", decimal_1 / decimal_2);
    printf("A %% B = %d\n", decimal_1 % decimal_2);

    //Logical operators
    printf("Logical operators: \n");
    if(decimal_1 > decimal_2) {
        printf("A > B\n");
        printf("%d\n", i);
    }else if(decimal_1 == decimal_2) {
        printf("A == B\n");
        printf("%d\n", i);
    }else {
        printf("A < B && A != B \n");
        i++;
        printf("%d\n", i);
    }

    //ByBit operators
    printf("A = ");
    printBinary(decimal_1);

    printf("B = ");
    printBinary(decimal_2);

    printf("A & B = ");
    printBinary(decimal_1 & decimal_2);

    printf("A || B = ");
    printBinary(decimal_1 | decimal_2);

    printf("A ^ B = ");
    printBinary(decimal_1 ^ decimal_2);

    printf("~A= ");
    printBinary(~decimal_1);

    printf("A << 1 = ");
    printBinary(decimal_1 << 1);

    printf("A >> 1 = ");
    printBinary(decimal_1 >> 1);

    // 3 task output
    printf("Value: %d\n", *pointer);
    printf("Address: %p\n", (void*)pointer);

    // Task 4

    int a, b, c;

    printf("Let's find the roots of a quadratic equation \n");
    printf("Enter first coefficient: ");
    scanf("%d", &a);
    printf("Enter second coefficient: ");
    scanf("%d", &b);
    printf("Enter free member: ");
    scanf("%d", &c);

    calculate(a, b, c);

    return 0;
}
