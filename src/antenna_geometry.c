#include <stdio.h>

double calculate_antenna_coverage(double radius) {
    return 3.14159 * radius * radius;
}

int main() {
    printf("Coverage: %f\n", calculate_antenna_coverage(5.0));
    return 0;
}
