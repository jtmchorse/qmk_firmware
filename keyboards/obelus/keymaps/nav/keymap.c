#include "obelus.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ,-----------------------.
   * | ins | home| pgup|prtsc|
   * |-----+-----+-----+-----|
   * | del | end | pgdn|scrlk|
   * |-----+-----+-----+-----|
   * |     |  up |     |pause|
   * |-----+-----+-----+-----|
   * | left|  dn |right|  L1 |
   * `---------------------- '
   */
[0] = KEYMAP( /* Base */
  KC_INSERT, KC_HOME, KC_PGUP,  KC_PSCR, \
  KC_DELETE, KC_END,  KC_PGDN,  KC_SLCK, \
  KC_NO,      KC_UP,  KC_NO,    KC_PAUSE, \
  KC_LEFT,   KC_DOWN, KC_RIGHT, TO(1) \
),

  /* L1 - mouse controls
   * ,-----------------------.
   * |wh_l |wh_up|wh_r |fast |
   * |-----+-----+-----+-----|
   * |btn3 |wh_dn|btn4 |slow |
   * |-----+-----+-----+-----|
   * |l_clk| m_up|r_clk|vslow|
   * |-----+-----+-----+-----|
   * | m_l |m_ dn| m_r |  L0 |
   * `---------------------- '
   */
[1] = KEYMAP( /* L1 */
  KC_MS_WH_LEFT, KC_MS_WH_UP,   KC_MS_WH_RIGHT, KC_MS_ACCEL2, \
  KC_MS_BTN3,    KC_MS_WH_DOWN, KC_MS_BTN4,     KC_MS_ACCEL1, \
  KC_MS_BTN1,    KC_MS_UP,      KC_MS_BTN2,     KC_MS_ACCEL0, \
  KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,    TO(0) \
),
};

#ifdef AUDIO_ENABLE
  float tone_startup[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
#endif

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case BACKLIT:
        if (record->event.pressed) {
          register_code(KC_RSFT);
          #ifdef BACKLIGHT_ENABLE
            backlight_step();
          #endif
        } else {
          unregister_code(KC_RSFT);
        }
        return false;
        break;
    }
  return true;
}

void led_set_user(uint8_t usb_led) {

}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

#endif
