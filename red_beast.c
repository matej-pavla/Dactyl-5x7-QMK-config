#include "red_beast.h"

#define DIMM_BRIGHTNESS 180
#define HSV_DIMM_CYAN 128, 255, DIMM_BRIGHTNESS
#define HSV_DIMM_RED 0, 255, DIMM_BRIGHTNESS
#define HSV_DIMM_YELLOW 43, 255, DIMM_BRIGHTNESS

const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_RED}
);

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_DIMM_YELLOW}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    gaming_layer,
    capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    //rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
    rgblight_sethsv(HSV_DIMM_CYAN);
    rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 0);
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_TOG:
      if (record->event.pressed) {
        // Do something when pressed
        uint8_t val = rgblight_get_val() ? 0 : DIMM_BRIGHTNESS;
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), val);
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

/*layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 0);
        break;
    case 3:
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), DIMM_BRIGHTNESS);
        break;
    default: //  for any other layers, or the default layer
        break;
    }

    return state;
}*/

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 3));
    return state;
}
