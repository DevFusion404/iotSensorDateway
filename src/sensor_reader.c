#include <stdio.h>

float read_snr(int sensor_id) {
    return sensor_id * 1.25f;
}

int main() {
    float snr = read_snr(4);
    printf("Sensor SNR: %f\n", snr);
    return 0;
}
