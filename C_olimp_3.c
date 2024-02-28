#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    FILE *inputFile, *outputFile;
    int digits[9];
    int i, num1 = 0, num2 = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read input from file
    for (i = 0; i < 9; i++) {
        fscanf(inputFile, "%1d", &digits[i]);
    }
    fclose(inputFile);

    // Sort the digits in descending order
    qsort(digits, 9, sizeof(int), compare);

    // Form two numbers to maximize their product
    for (i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            num1 = num1 * 10 + digits[i];
        } else {
            num2 = num2 * 10 + digits[i];
        }
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write result to file
    fprintf(outputFile, "%d\n%d", num1, num2);
    fclose(outputFile);

    return 0;
}