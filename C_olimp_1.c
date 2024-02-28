#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int n, i, j, count;
    int *table, *permutation;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read input from file
    fscanf(inputFile, "%d", &n);
    table = (int*) malloc(n * sizeof(int));
    permutation = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &table[i]);
    }
    fclose(inputFile);

    // Calculate the permutation
    for (i = n - 1; i >= 0; i--) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (permutation[j] == 0 && count == table[i]) {
                permutation[j] = i + 1;
                break;
            } else if (permutation[j] == 0) {
                count++;
            }
        }
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Write result to file
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", permutation[i]);
    }
    fclose(outputFile);

    free(table);
    free(permutation);

    return 0;
}