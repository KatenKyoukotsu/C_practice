#include <stdio.h>

void inputN(int *n) {
    do {
        printf("Input number of matrics (2 < n < 24): ");
        scanf("%d", n);
    } while ((*n <= 1 || *n >= 24) || (*n % 2 == 0));
}

void printMatrix(int A[][7], int n) {
    // Вывод матрицы с выравниванием по младшему разряду
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", A[i][j] % 10);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Ввод нечетного целого числа n
    inputN(&n);

    // Исходная матрица
    int A[7][7] = {
        {7, 6, 5, 4, 3, 2, 1},
        {0, 8, 15, 14, 13, 12, 0},
        {0, 0, 9, 16, 11, 0, 0},
        {0, 0, 0, 10, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    // Вывод матрицы с выравниванием по младшему разряду
    printMatrix(A, n);

    return 0;
}
