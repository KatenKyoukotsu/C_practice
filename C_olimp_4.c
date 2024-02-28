#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int A, N, B = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read input from file
    fscanf(inputFile, "%d %d", &A, &N);
    fclose(inputFile);

    // Calculate the mirror reflection
    for (int i = 0; i < N; i++) {
        B = B << 1; // Left shift B by 1 to make room for the next bit
        if (A & (1 << i)) {
            B = B | 1; // Set the least significant bit of B if the corresponding bit of A is 1
        }
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write result to file
    fprintf(outputFile, "%d", B);
    fclose(outputFile);

    return 0;
}