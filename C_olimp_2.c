#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int coefficients[9];
    int i, firstNonZeroIndex = -1;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read input from file
    for (i = 0; i < 9; i++) {
        fscanf(inputFile, "%d", &coefficients[i]);
        if (coefficients[i] != 0 && firstNonZeroIndex == -1) {
            firstNonZeroIndex = i;
        }
    }
    fclose(inputFile);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write result to file
    for (i = 8; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (i != firstNonZeroIndex) {
                fprintf(outputFile, " ");
            }
            if (i == 0) {
                fprintf(outputFile, "%d", coefficients[i]);
            } else if (i == 1) {
                if (coefficients[i] == 1) {
                    fprintf(outputFile, "x");
                } else if (coefficients[i] == -1) {
                    fprintf(outputFile, "-x");
                } else {
                    fprintf(outputFile, "%dx", coefficients[i]);
                }
            } else {
                if (coefficients[i] == 1) {
                    fprintf(outputFile, "x^%d", i);
                } else if (coefficients[i] == -1) {
                    fprintf(outputFile, "-x^%d", i);
                } else {
                    fprintf(outputFile, "%dx^%d", coefficients[i], i);
                }
            }
        }
    }
    fclose(outputFile);

    return 0;
}