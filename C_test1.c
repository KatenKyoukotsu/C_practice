#include <stdio.h>
#include <math.h>

double calculateZ(double x, double y) {
    return (pow(x, 2) - pow(y, 2) + 2 * fabs(x * y)) / (1 + pow(x, 2) + pow(y, 2));
}

int main() {
    double x, y, z;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter y: ");
    scanf("%lf", &y);
    z = calculateZ(x, y);
    printf("z = %lf\n", z);
    return 0;
}