# iot_sensor_gateway

A production-style Embedded C / IoT Sensor Gateway daemon engineered for the **RefactorIQ** Safe Code Transformation & Validation Agent (**SCTVA**) evaluation and demonstration.

---

## 1. Subsystem Architecture

The repository simulates an edge device ingestion gateway receiving frames from field telemetry sensors, buffering raw payload arrays, calculating antenna coverage geometries, filtering high-frequency noise spikes, and reporting metrics via structured logs.

```
iot_sensor_gateway/
├── include/
│   └── sensor_gateway.h         # Master gateway definitions & prototypes
├── src/
│   ├── main.c                   # Edge gateway orchestrator daemon
│   ├── antenna_geometry.c       # RF spatial coverage & antenna math
│   ├── packet_receiver.c        # Inbound packet reception & payload extraction
│   ├── telemetry_logger.c       # System audit logger & telemetry formatter
│   ├── ring_buffer.c            # Circular frame buffer memory configuration
│   ├── signal_filter.c          # Digital signal DSP filtering logic
│   ├── threshold_detector.c     # Sensor thermal spike normalization
│   ├── packet_counter.c         # Network frame telemetry counter
│   ├── watchdog_timer.c         # Hardware watchdog timeout resolver
│   ├── payload_validator.c      # Inbound frame boundary bounds checking
│   └── sensor_reader.c          # ADC analog sensor reading & SNR calculation
├── Makefile                     # Standard GCC multi-target build rules
├── refactoring_plan.json        # Companion Refactoring Decision Plan (RDP)
├── demo_runner.py               # Automated SCTVA pipeline runner (10/10 PASS)
└── README.md                    # Subsystem documentation
```

---

