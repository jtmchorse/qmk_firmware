#include "lfk78.h"
#include "issi.h"
#include "lighting.h"

//Define a shorter 'transparent' key code to make the keymaps more compact
#define KC_TR KC_TRNS

// Colors of the layer indicator LED
// This list needs to define layer 0xFFFFFFFF, it is the end of the list, and the unknown layer
const Layer_Info layer_info[] = {
  // Layer     Mask           Red     Green   Blue
  {0x00000000, 0xFFFFFFF8, {0x0000, 0x0FFF, 0x0000}}, // base layers (VANILLA, DEFAULT_WKL, DEFAULT_OSX) - green
  {0x00000008, 0xFFFFFFF8, {0x0000, 0x0000, 0x0FFF}}, // function layer - blue
  {0x00000010, 0xFFFFFFF0, {0x0FFF, 0x0000, 0x0FFF}}, // settings layer - magenta
  {0xFFFFFFFF, 0xFFFFFFFF, {0x0FFF, 0x0FFF, 0x0FFF}}, // unknown layer - REQUIRED - white
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP(
  /* Keymap VANILLA: (Base Layer) Default Layer
   * ,---------.  ,------------------------------------------------------------.  ,---------.
   * | F1 | F2 |  |Esc~| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backspa|  |PgUp|Home|
   * |---------|  |------------------------------------------------------------|  |---------|
   * | F3 | F4 |  |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     \|  |PgDn| End|
   * |---------|  |------------------------------------------------------------|  `---------'
   * | F5 | F6 |  |Func    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |---------|  |------------------------------------------------------------|  ,----.
   * | F7 | F8 |  |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift      |  | Up |
   * |---------|  |-------------------------------------------------------------------------.
   * | F9 | F10|  |Ctrl|Win |Alt |      Space                | Alt| Ctrl |    |Lft| Dn |Rig |
   * `---------'  `------------------------------------------------------'    `-------------'
   */
  KC_NO, KC_NO,    KC_GESC,KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,   KC_BSPC,  KC_HOME, KC_PGUP,
  KC_NO, KC_NO,    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,  KC_END,  KC_PGDN,
  KC_NO, KC_NO,    MO(1),     KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,      KC_ENT,
  KC_NO, KC_NO,    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT,   KC_UP,
  KC_NO, KC_NO,    KC_LCTL, KC_LGUI, KC_LALT,              KC_SPC,           KC_NO, KC_RALT, KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap FUNCTION: Function Layer
   * ,---------.  ,-------------------------------------------------------------.  ,---------.
   * |    |    |  | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete   |  |    |    |
   * |---------|  |-------------------------------------------------------------|  |---------|
   * |    |    |  |     |   |   |   |   |   |   |   |   |   |   |   |   |       |  |    |    |
   * |---------|  |-------------------------------------------------------------|  `---------'
   * |    |    |  |        |   |   |   |   |   |   |   |   |   |   |   |        |
   * |---------|  |-------------------------------------------------------------|  ,----.
   * |    |    |  |        |   |   |   |   |   |   |   |   |   |   |            |  |pgup|
   * |---------|  |--------------------------------------------------------------------------.
   * |    |    |  |    |    |    |                            |     |Fun2|   |home|pgdn|end |
   * `---------'  `------------------------------------------------------'     `-------------'
   */
[1] = KEYMAP(
  KC_TR,   KC_TR,  KC_GRV,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,  KC_TR, KC_TR,
  KC_TR,   KC_TR,  KC_TR,    KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR,  KC_TR,    KC_TR, KC_TR,
  KC_TR,   KC_TR,  KC_TR,     KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR,       KC_TR,
  KC_TR,   KC_TR,  KC_TR,      KC_TR,  KC_TR,  KC_TR,  KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR,       KC_TR,       KC_PGUP,
  KC_TR,   KC_TR,  KC_TR,  KC_TR, KC_TR,                 KC_TR,                         KC_TR, KC_TR, TO(2),      KC_HOME, KC_PGDN, KC_END),

  /* Keymap FUNCTION: Flash Layer
   * ,---------.  ,-------------------------------------------------------------.  ,---------.
   * |    |    |  |   |   |   |   |   |   |   |   |   |   |   |   |   |         |  |    |    |
   * |---------|  |-------------------------------------------------------------|  |---------|
   * |    |    |  |     |   |   |   |   |   |   |   |   |   |   |   |   |       |  |RSET|    |
   * |---------|  |-------------------------------------------------------------|  `---------'
   * |    |    |  |        |   |   |   |   |   |   |   |   |   |   |   |        |
   * |---------|  |-------------------------------------------------------------|  ,----.
   * |    |    |  |        |   |   |   |   |   |   |   |   |   |   |            |  |    |
   * |---------|  |--------------------------------------------------------------------------.
   * |    |    |  |    |    |    |                            |     |     |   |    |    |    |
   * `---------'  `------------------------------------------------------'     `-------------'
   */
[2] = KEYMAP(
  KC_TR,   KC_TR,    TO(0),  KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR,     KC_TR, KC_TR,
  KC_TR,   KC_TR,    KC_TR,    KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR,  KC_TR,  RESET, KC_TR,
  KC_TR,   KC_TR,    KC_TR,     KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR,       KC_TR,
  KC_TR,   KC_TR,    KC_TR,      KC_TR,  KC_TR,  KC_TR,  KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR, KC_TR,       KC_TR,      KC_TR,
  KC_TR,   KC_TR,    KC_TR,  KC_TR, KC_TR,                  KC_TR,                           KC_TR, KC_TR, KC_TR,    KC_TR, KC_TR, KC_TR),
};
