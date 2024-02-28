#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1/(x+3);
}

double r(double x, int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += pow(-1, i) * pow(x, i) / pow(3, i+1);
    }
    return sum;
}

double Q(double x, int n) {
    return pow(-1, n-1) * pow(x, n-1) / pow(3, n);
}

int main() {
    double x;
    int n;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The value of the function f(x): %lf\n", f(x));
    printf("The value of the nth term Q: %lf\n", Q(x, n));
    printf("The sum of the first n terms: %lf\n", r(x, n));

    return 0;
}