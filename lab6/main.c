#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Task 1

int is_vowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y');
}

int is_consonant(char ch) {
    ch = tolower(ch);
    return (ch >= 'a' && ch <= 'z' && !is_vowel(ch));
}

//

int main(void){
    char sentence[120];
    int vowels = 0, consonants = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for(int i = 0; sentence[i] != '\0'; i++) {
        if(isalpha(sentence[i])) {
            if(is_vowel(sentence[i])) {
                vowels++;
            }else if(is_consonant(sentence[i])){
                consonants++;
            }
        }
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);


    // Task 2

    int numOfList;
    int i = 1;
    int sum = 0;

    printf("Enter your place in list: ");
    scanf("%d", &numOfList);

    while(i <= 100) {
        if(i == numOfList || i == 33) {
            i++;
            continue;
        }
        sum+=i;
        i++;
    }

    printf("The sum of the first 100 numbers excluding %d and 33: %d\n", numOfList, sum);

    // Task 3

    int N;
    double num, sum2 = 0, min, max, average;

    do {
        printf("Enter an integer N in range [7, 12]: ");
        scanf("%d", &N);
    }while(N < 7 || N > 12);

    printf("Enter %d real numbers:\n", N);

    for (int i = 0; i < N; i++) {
        scanf("%lf", &num);
        sum2 += num;

        if (i == 0) {
            min = max = num;
        } else {
            if (num < min) min = num;
            if (num > max) max = num;
        }
    }

    average = sum2 / N;

    printf("Sum: %.2lf\n", sum2);
    printf("Average: %.2lf\n", average);
    printf("Minimum: %.2lf\n", min);
    printf("Maximum: %.2lf\n", max);

    return 0;
}
