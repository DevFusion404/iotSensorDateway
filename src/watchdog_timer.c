#include <stdio.h>

int resolve_watchdog_timeout(int configured_sec) {
    if (configured_sec <= 0) {
        return 30;
    }
    return configured_sec;
}

int main() {
    printf("Watchdog: %d sec\n", resolve_watchdog_timeout(0));
    return 0;
}
