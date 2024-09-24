#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}


void studentTable() {
    int count;

    printf("Insert count of students: ");
    scanf("%d", &count);
    printf("\n");

    // Check for wrong input
    if (count <= 0) {
        printf("Invalid number of students.\n");
        return;
    }

    // Initialize memory for students
    char **surnames = malloc(count * sizeof(char *));
    char **initials = malloc(count * sizeof(char *));
    char **mails = malloc(count * sizeof(char *));
    char **colors = malloc(count * sizeof(char *));

    if (surnames == NULL || initials == NULL || mails == NULL || colors == NULL) {
        printf("Memory allocation failed\n");
        // Free already allocated memory before exiting
        free(surnames);
        free(initials);
        free(mails);
        free(colors);
        return;
    }

    // Initialize memory for each student
    for (int i = 0; i < count; i++) {
        surnames[i] = malloc(MAX_LENGTH * sizeof(char));
        initials[i] = malloc(MAX_LENGTH * sizeof(char));
        mails[i] = malloc(MAX_LENGTH * sizeof(char));
        colors[i] = malloc(MAX_LENGTH * sizeof(char));
        if (surnames[i] == NULL || initials[i] == NULL || mails[i] == NULL || colors[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free already allocated memory before exiting
            for (int j = 0; j < i; j++) {
                free(surnames[j]);
                free(initials[j]);
                free(mails[j]);
                free(colors[j]);
            }
            free(surnames);
            free(initials);
            free(mails);
            free(colors);
            return;
        }
    }

    // Read information about students
    for (int i = 0; i < count; i++) {
        printf("Enter surname of student %d: ", i + 1);
        scanf("%s", surnames[i]);
        printf("Enter initials of student %d: ", i + 1);
        scanf("%s", initials[i]);
        printf("Enter email of student %d: ", i + 1);
        scanf("%s", mails[i]);
        printf("Enter favorite color of student %d: ", i + 1);
        scanf("%s", colors[i]);
    }

    // Output surnames, initials, mails and colors of students
    printf("%-5s | %-20s | %-10s | %-30s | %-15s\n", "№", "Student surnames", "Initials", "Mail", "Color");
    for (int i = 0; i < count; i++) {
        printf("%-5d | %-20s | %-10s | %-30s | %-15s\n", i + 1, surnames[i], initials[i], mails[i], colors[i]);
    }

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(surnames[i]);
        free(initials[i]);
        free(mails[i]);
        free(colors[i]);
    }
    free(surnames);
    free(initials);
    free(mails);
    free(colors);
}

int main(void) {
    int num = 42;
    float float_num= 3.14159;
    char a = 'A';
    char str[] = "Hello World!";
    void *pointer = &num;

    //Decimal number in different formats

    printf("Decimal: %d\n", num);
    printf("Binary: ");
    printBinary(num);
    printf("\n");
    printf("Octal: %o\n", num);
    printf("Hexadecimal: %X\n", num);

    //Floating number in different formats

    printf("Floating point number: %f\n", float_num);
    printf("Exponential number: %e\n", float_num);
    printf("Flexible: %g\n", float_num);

    //Output char and string

    printf("Character: %c\n", a);
    printf("String: %s\n", str);

    //Output pointer
    printf("Pointer: %p\n", pointer);

    // Second task

    studentTable();

    return 0;
}

