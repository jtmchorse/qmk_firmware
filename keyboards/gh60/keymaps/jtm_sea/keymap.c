#include "gh60.h"
#include "action_layer.h"

// #define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
  KEYMAP_HHKB_ISO(
        KC_GESC,    KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, \
        MT(F(2), KC_TAB),  KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
        KC_LCTL, KC_A,    KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,     KC_L,    KC_SCLN, KC_QUOT, F(2), KC_ENT, \
        KC_LSPO, KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSPC, F(1), \
        KC_LCTL, KC_LALT, KC_LGUI,      KC_SPC,            KC_RGUI, KC_RGUI, KC_RALT, KC_RCTL),
    /* 1: fn */
    KEYMAP_HHKB_ISO(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_TRNS, KC_DEL, \
        KC_CAPS, BL_OFF,  BL_ON, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,    KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT, KC_B, KC_ENT, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_TRNS,  KC_TRNS, \
        RESET,   RESET,   KC_TRNS,      KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* 2: fn */
    KEYMAP_HHKB_ISO(
        KC_Z, KC_WH_U, KC_WH_D, KC_X,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, \
        KC_TRNS, BL_OFF,  BL_ON, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,    KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_MPRV, KC_C, KC_MNXT, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_TRNS,  KC_TRNS, \
        RESET,   RESET,   KC_TRNS,      KC_MPLY,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

enum function_id {
    SHIFT_ESC, 
};  

const uint16_t PROGMEM fn_actions[] = {      
    [0] = ACTION_FUNCTION(SHIFT_ESC),
    [1] = ACTION_LAYER_MOMENTARY(1),  
    // to Fn overlay
};

