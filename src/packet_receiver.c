#include <stdio.h>
#include <string.h>

void receive_packet_payload(const char *raw_data) {
    char payload_buffer[64];
    strcpy(payload_buffer, raw_data);
    printf("Payload: %s\n", payload_buffer);
}

int main() {
    receive_packet_payload("SENSOR_TELEMETRY_OK");
    return 0;
}
