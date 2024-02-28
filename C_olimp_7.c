#include <stdio.h>

#define MAX_SIZE 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int M;
    int matrix[MAX_SIZE][MAX_SIZE];

    // Read input from the file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file\n");
        return 1;
    }
    fscanf(inputFile, "%d", &M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(inputFile, "%d", &matrix[i][j]);
        }
    }
    fclose(inputFile);

    // Calculate the maximum sum path
    for (int i = M - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (i == M - 1 && j == M - 1) {
                continue;
            } else if (i == M - 1) {
                matrix[i][j] += matrix[i][j + 1];
            } else if (j == M - 1) {
                matrix[i][j] += matrix[i + 1][j];
            } else {
                matrix[i][j] += max(matrix[i][j + 1], matrix[i + 1][j]);
            }
        }
    }

    // Write the result to the output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file\n");
        return 1;
    }
    fprintf(outputFile, "%d\n", matrix[0][0]);
    fclose(outputFile);

    return 0;
}