#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task 1 & 3

void generate_numbers(int *arr, int size) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

//

// Task 2

int* get_element1(int *arr, int index) {

    if(index >= 0 && index < 10) {
        return &arr[index];
    }

    return NULL;
}

int* get_element2(int arr[12][12], int row, int col) {
    if(row >= 0 && row < 12 && col >= 0 && col < 12) {
        return &arr[row][col];
    }

    return NULL;
}

//

int main(void)
{
    // Task 1

    int arr[10];

    generate_numbers(arr, 10);

    printf("Generated Array: \n");

    for(int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    //Task 2

    int arr1[10] = {12, 31, 25, 36, 45, 5, 64, 72, 18, 59};
    int arr2[12][12];

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            arr2[i][j] = i * 12 + j;
        }
    }

    int index1 = 4;
    int *element1 = get_element1(arr1, index1);

    if(element1 != NULL) {
        printf("Element of one-dimensional array is: %d\n", *element1);
    }else {
        printf("Element1 is NULL\n");
    }

    int row = 10, col = 5;
    int *element2 = get_element2(arr2, row, col);

    if(element2 != NULL){
        printf("An element of a two-dimensional array is: %d\n", *element2);
    }else {
        printf("Element2 is NULL\n");
    }

    //Task 3

    int arr3[20];
    int max = 0, min = 99, sum;

    generate_numbers(arr3, 20);

    for (int i = 0; i < 20; i++) {
        printf("%d\n", arr3[i]);
        if (arr3[i] > max) {
            max = arr3[i];
        }
        if (arr3[i] < min) {
            min = arr3[i];
        }
    }

    sum = max + min;

    printf("Max Value: %d\n", max);
    printf("Min Value: %d\n", min);
    printf("Sum Value: %d\n", sum);

    return 0;
}
