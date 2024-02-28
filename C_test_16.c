#include <stdio.h>
#include <math.h>

// Recursive function to calculate the expression for odd and even n
int calculateExpression(int n) {
    if (n == 1) {
        return 135; // Base case for odd n
    } else if (n == 2) {
        return 246; // Base case for even n
    } else {
        if (n % 2 == 0) {
            return 2 * calculateExpression(n - 2); // Recursive call for even n
        } else {
            return 3 * calculateExpression(n - 2); // Recursive call for odd n
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int n, result;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read input from file
    fscanf(inputFile, "%d", &n);
    fclose(inputFile);

    // Calculate the expression based on the value of n
    result = calculateExpression(n);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write result to file
    fprintf(outputFile, "%d", result);
    fclose(outputFile);

    return 0;
}