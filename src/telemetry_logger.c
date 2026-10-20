#include <stdio.h>

void log_telemetry_event(int event_id, const char *status) {
    char event_log[128];
    sprintf(event_log, "EVENT_%d: %s", event_id, status);
    printf("Log: %s\n", event_log);
}

int main() {
    log_telemetry_event(101, "LINK_ESTABLISHED");
    return 0;
}
