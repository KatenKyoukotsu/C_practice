#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_average(double* data, int n, int type) {
    double sum = 0;
    double product = 1;
    for(int i = 0; i < n; i++) {
        sum += data[i];
        product *= data[i];
    }
    if(type == 1) {
        return sum;
    } else if(type == 2) {
        return pow(product, 1.0/n);
    } else if(type == 3) {
        return n / sum;
    } else if(type == 4) {
        return sqrt(sum);
    }
    return 0;
}

int count_positive_elements(double* data, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(data[i] > 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, choice;
    double min_val, max_val, *data;

    while(1) {
        printf("Choose input method:\n");
        printf("1. Keyboard input\n");
        printf("2. Random number generation\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if(choice == 3) {
            break;
        }

        printf("Enter the number of elements: ");
        scanf("%d", &n);

        if(choice == 1) {
            data = (double*)malloc(n * sizeof(double));
            for(int i = 0; i < n; i++) {
                printf("Enter element %d: ", i+1);
                scanf("%lf", &data[i]);
            }
        } else if(choice == 2) {
            printf("Enter the minimum value: ");
            scanf("%lf", &min_val);
            printf("Enter the maximum value: ");
            scanf("%lf", &max_val);
            data = (double*)malloc(n * sizeof(double));
            for(int i = 0; i < n; i++) {
                data[i] = min_val + (max_val - min_val) * ((double)rand() / RAND_MAX);
            }
        } else {
            printf("Invalid choice\n");
            continue;
        }

        printf("Arithmetic mean: %lf\n", calculate_average(data, n, 1));
        printf("Geometric mean: %lf\n", calculate_average(data, n, 2));
        printf("Harmonic mean: %lf\n", calculate_average(data, n, 3));
        printf("Root mean square: %lf\n", calculate_average(data, n, 4));
        printf("Number of positive elements: %d\n", count_positive_elements(data, n));

        free(data);
    }

    return 0;
}