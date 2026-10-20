/**
 * sensor_gateway.h - IoT Edge Sensor Gateway Subsystem Definitions
 * RefactorIQ Demo Target Repository for Safe C Transformations
 */

#ifndef SENSOR_GATEWAY_H
#define SENSOR_GATEWAY_H

#ifdef __cplusplus
extern "C" {
#endif

/* Core Telemetry Definitions */
#define GATEWAY_VERSION "1.4.2"
#define MAX_PAYLOAD_LEN 256

/* Antenna & Spatial Coverage */
double calculate_antenna_coverage(double radius);

/* Network Frame Ingestion */
void receive_packet_payload(const char *raw_data);

/* Event & Audit Telemetry */
void log_telemetry_event(int event_id, const char *status);

/* Circular Buffer Allocation */
void configure_ring_buffer(int capacity);

/* Signal Processing & Filtering */
int calc_dat(int raw_signal);

/* Sensor Threshold Analysis */
double evaluate_temperature_spike(double sensor_val);

/* Packet Stream Accounting */
extern int global_counter;
void count_received_frame(void);

/* Watchdog Subsystem */
int resolve_watchdog_timeout(int configured_sec);

/* Inbound Frame Boundary Verification */
int validate_payload_boundary(int payload_bytes);

/* Hardware ADC & Sensor Sampling */
float read_snr(int sensor_id);

#ifdef __cplusplus
}
#endif

#endif /* SENSOR_GATEWAY_H */
