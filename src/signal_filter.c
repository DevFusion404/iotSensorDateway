#include <stdio.h>

int calc_dat(int raw_signal) {
    return raw_signal * 2;
}

int main() {
    int filtered = calc_dat(15);
    printf("Filtered signal: %d\n", filtered);
    return 0;
}
