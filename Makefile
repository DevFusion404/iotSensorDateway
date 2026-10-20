# RefactorIQ iot_sensor_gateway Makefile
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
SRC_DIR = src
BIN_DIR = bin

MODULES = antenna_geometry packet_receiver telemetry_logger ring_buffer \
          signal_filter threshold_detector packet_counter watchdog_timer \
          payload_validator sensor_reader

all: $(MODULES)

$(MODULES): %: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean $(MODULES)
