#include <stdio.h>

int main() {
    int k, l, m;
    FILE *inputFile, *outputFile;

    // Open the input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file\n");
        return 1;
    }

    // Read the dimensions from the input file
    fscanf(inputFile, "%d %d %d", &k, &l, &m);

    // Read the front and right projections from the input file
    int front[l][k], right[m][l];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < k; j++) {
            fscanf(inputFile, "%d", &front[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            fscanf(inputFile, "%d", &right[i][j]);
        }
    }

    // Close the input file
    fclose(inputFile);

    // Calculate the minimum and maximum number of cubes
    int min_cubes = 0, max_cubes = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            if (front[j][i] == 1 && right[i][j] == 1) {
                min_cubes++;
                max_cubes++;
            } else if (front[j][i] == 1 || right[i][j] == 1) {
                max_cubes++;
            }
        }
    }

    // Open the output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file\n");
        return 1;
    }

    // Write the minimum and maximum number of cubes to the output file
    fprintf(outputFile, "%d %d\n", min_cubes, max_cubes);

    // Close the output file
    fclose(outputFile);

    return 0;
}