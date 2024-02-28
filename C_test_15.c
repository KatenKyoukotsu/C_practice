// Install gnuplot library 
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set parametric\n");
        fprintf(gnuplotPipe, "set xrange [-10:10]\n");
        fprintf(gnuplotPipe, "set yrange [-10:10]\n");
        fprintf(gnuplotPipe, "plot (1 + 3) * cos(3 * t) - 3 * cos(t + 3 * t), (1 + 3) * sin(3 * t) - 3 * sin(t + 3 * t)\n");
        fflush(gnuplotPipe);
        getchar(); // Wait for user to press enter
        fprintf(gnuplotPipe, "exit\n");
        pclose(gnuplotPipe);
    } else {
        printf("Error opening gnuplot");
    }
    return 0;
}