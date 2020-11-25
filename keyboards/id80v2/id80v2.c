#include "id80v2.h"

void matrix_init_kb(void) {
    led_init_ports();
    matrix_init_user();
}

void led_init_ports(void) {
    setPinOutput(CAPS_LOCK_LED_PIN);
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        writePin(CAPS_LOCK_LED_PIN, !led_state.caps_lock);
    }
    return res;
}
