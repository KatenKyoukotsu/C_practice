#include <stdio.h>

int main() {
    int N, x1, y1, x2, y2;
    int totalArea = 0;

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file\n");
        return 1;
    }

    fscanf(inputFile, "%d", &N);
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d %d %d %d", &x1, &y1, &x2, &y2);
        totalArea += (x2 - x1) * (y2 - y1);
    }
    fclose(inputFile);

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file\n");
        return 1;
    }

    fprintf(outputFile, "%d\n", totalArea);
    fclose(outputFile);

    return 0;
}