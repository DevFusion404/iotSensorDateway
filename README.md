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

## 2. Refactoring Catalog & Safety Validations

Every module contains an authentic, real-world code smell or security anti-pattern. Each refactoring matches the capability catalog of the SCTVA engine and is verified with 0 rollbacks:

| # | File | Smell / Anti-Pattern | SCTVA Refactoring | Transformed Output | Validation |
|---|------|----------------------|-------------------|--------------------|------------|
| 1 | `src/antenna_geometry.c` | Magic Number (`3.14159`) | **Introduce Constant** | `#define PI_VALUE 3.14159` | AST Equivalence / 1.00 Conf |
| 2 | `src/packet_receiver.c` | Buffer Overflow (`strcpy`) | **Replace Unsafe Function** | `strncpy(dest, src, sizeof(dest)-1)` | Memory Safety / 1.00 Conf |
| 3 | `src/telemetry_logger.c` | Format String Risk (`sprintf`) | **Replace Unsafe Function** | `snprintf(dest, sizeof(dest), ...)` | Memory Safety / 1.00 Conf |
| 4 | `src/ring_buffer.c` | Magic Number (`1024`) | **Introduce Constant** | `#define BUFFER_SIZE 1024` | AST Equivalence / 1.00 Conf |
| 5 | `src/signal_filter.c` | Cryptic Function Name (`calc_dat`) | **Rename Symbol** | `calculate_formatted_data` | Call-graph Preservation / 1.00 Conf |
| 6 | `src/threshold_detector.c`| Magic Number (`1000`) | **Introduce Constant** | `#define MAX_DISCOUNT_THRESHOLD 1000` | AST Equivalence / 1.00 Conf |
| 7 | `src/packet_counter.c` | Naked Global Variable (`global_counter`) | **Encapsulate Variable** | Accessors `get_global_counter()` & `set_global_counter()` | Scope Isolation / 1.00 Conf |
| 8 | `src/watchdog_timer.c` | Magic Number (`30`) | **Introduce Constant** | `#define DEFAULT_TIMEOUT_SEC 30` | AST Equivalence / 1.00 Conf |
| 9 | `src/payload_validator.c` | Magic Number (`256`) | **Introduce Constant** | `#define MAX_ARRAY_SIZE 256` | AST Equivalence / 1.00 Conf |
| 10 | `src/sensor_reader.c` | Cryptic Symbol Name (`read_snr`) | **Rename Symbol** | `read_sensor_data` | Call-graph Preservation / 1.00 Conf |

---

## 3. Running the SCTVA Demonstration

Execute the self-contained demonstration runner from the repository root:

```powershell
python "iot_sensor_gateway\demo_runner.py"
```

### Expected Output
```
======================================================================================
      RefactorIQ: SAFE CODE TRANSFORMATION & VALIDATION (SCTVA) DEMO
           Target Project: iot_sensor_gateway (Embedded C / IoT)
======================================================================================

[01/10] Target: src/antenna_geometry.c
      Refactoring: Introduce Constant
      Status: [PASS] Transformed & Safety-Verified (Confidence: 1.000)
...
Total Transformations Attempted : 10
Total Successfully Verified     : 10
Safety Rollbacks                : 0
Verification Success Rate       : 100.0%
======================================================================================
```

---

## 4. Building with GCC

To compile all standalone tools:
```bash
make all
```
Binary output will be generated into the `bin/` directory.
