#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

// Function to multiply two numbers represented as strings
void multiply(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int lenResult = len1 + len2;

    int temp[MAX_DIGITS] = {0};

    // Perform multiplication using grade-school algorithm
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            temp[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    // Perform carry-over
    for (int i = lenResult - 1; i > 0; i--) {
        if (temp[i] >= 10) {
            temp[i - 1] += temp[i] / 10;
            temp[i] %= 10;
        }
    }

    // Find the starting index of the result
    int index = 0;
    while (temp[index] == 0) {
        index++;
    }

    // Convert the result to a string
    for (int i = index; i < lenResult; i++) {
        result[i - index] = temp[i] + '0';
    }
    result[lenResult - index] = '\0';
}

int main() {
    char num1[MAX_DIGITS], num2[MAX_DIGITS], result[2 * MAX_DIGITS];

    // Read input from the file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file\n");
        return 1;
    }
    fscanf(inputFile, "%s\n%s", num1, num2);
    fclose(inputFile);

    // Perform multiplication
    multiply(num1, num2, result);

    // Write the result to the output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file\n");
        return 1;
    }
    fprintf(outputFile, "%s\n", result);
    fclose(outputFile);

    return 0;
}