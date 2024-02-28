#include <stdio.h>
#include <math.h>

int main() {
    double x, y, z;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter y: ");
    scanf("%lf", &y);

    if (x <= 0) {
        z = cbrt(x * x * x * y * y);
    } else if (fabs(y) >= x) {
        z = acos(x / y);
    } else {
        z = (log(5 * x + 1) * (5 * x - 3 * fabs(y)));
    }

    printf("z = %lf\n", z);

    return 0;
}