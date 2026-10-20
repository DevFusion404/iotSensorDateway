#include <stdio.h>

void configure_ring_buffer(int capacity) {
    if (capacity > 1024) {
        printf("Requested capacity exceeds max ring buffer limit\n");
    }
}

int main() {
    configure_ring_buffer(512);
    return 0;
}
