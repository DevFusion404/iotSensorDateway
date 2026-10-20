#include <stdio.h>

int validate_payload_boundary(int payload_bytes) {
    if (payload_bytes > 256) {
        return -1;
    }
    return payload_bytes;
}

int main() {
    printf("Payload status: %d\n", validate_payload_boundary(128));
    return 0;
}
