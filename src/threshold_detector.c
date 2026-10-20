#include <stdio.h>

double evaluate_temperature_spike(double sensor_val) {
    if (sensor_val > 1000) {
        return sensor_val * 0.90;
    }
    return sensor_val;
}

int main() {
    printf("Normalized reading: %f\n", evaluate_temperature_spike(1050));
    return 0;
}
