/**
 * main.c - IoT Sensor Gateway Hub Main Entry Point
 * RefactorIQ Project: iot_sensor_gateway
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/sensor_gateway.h"

int main() {
    printf("============================================================\n");
    printf("      RefactorIQ: IoT Sensor Edge Gateway Daemon (v%s)\n", GATEWAY_VERSION);
    printf("============================================================\n");

    printf("\n[1] Hardware Ingestion Subsystem:\n");
    printf("    Antenna coverage (radius=7.5m): %.2f sq.m\n", calculate_antenna_coverage(7.5));
    printf("    ADC Sensor #1 SNR: %.2f dB\n", read_snr(1));

    printf("\n[2] Network & Telemetry Subsystem:\n");
    count_received_frame();
    printf("    Inbound frame counted. Total frames: %d\n", global_counter);
    receive_packet_payload("CMD_POLL_ACTIVE_SENSORS");
    log_telemetry_event(200, "GATEWAY_ONLINE");

    printf("\n[3] Memory & Safety Guard Subsystem:\n");
    configure_ring_buffer(512);
    printf("    Watchdog timeout: %d sec\n", resolve_watchdog_timeout(0));
    printf("    Payload check (128 bytes): %d (OK)\n", validate_payload_boundary(128));

    printf("\n============================================================\n");
    printf("   Gateway Subsystems Initialized Successfully.\n");
    printf("============================================================\n");

    return 0;
}
