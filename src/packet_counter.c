#include <stdio.h>

int global_counter = 0;

void count_received_frame() {
    global_counter = global_counter + 1;
}

int main() {
    count_received_frame();
    printf("Total frames: %d\n", global_counter);
    return 0;
}
