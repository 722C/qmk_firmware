#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
// #define _GAME 3
#define _ADJUST 16


// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_5x15(
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------.
     KC_GESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,KC_NLCK,KC_MINS, KC_EQL,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_BSPC,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_TAB ,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_P7,  KC_P8,  KC_P9,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSLS,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     MO(_RAISE),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,  KC_P4,  KC_P5,  KC_P6,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_P1,  KC_P2,  KC_P3,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_LCTL,KC_LGUI,KC_LALT,MO(_LOWER),KC_LALT, KC_ENT, KC_SPC,  KC_P0, KC_SPC, KC_SPC,MO(_RAISE),KC_LEFT,  KC_UP,KC_DOWN,KC_RGHT
  //`-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------'
  ),

  [_LOWER] = LAYOUT_ortho_5x15(
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------.
      KC_GRV,KC_EXLM, KC_AT ,KC_HASH,KC_CLR ,KC_PERC,RGB_TOG,RGB_RMOD,RGB_MOD,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN, KC_DEL,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LBRC,RGB_HUI,RGB_SAI,RGB_VAI,KC_RBRC,  KC_P7,  KC_P8,  KC_P9,KC_PLUS,KC_NLCK,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
 MO(_ADJUST),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LPRN,RGB_HUD,RGB_SAD,RGB_VAD,KC_RPRN,  KC_P4,  KC_P5,  KC_P6,KC_MINS,KC_BSLS,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_P1,  KC_P2,  KC_P3, KC_EQL,KC_TRNS,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_P0,  KC_P0, KC_EQL,KC_TRNS
  //`-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------'
  ),

  [_RAISE] = LAYOUT_ortho_5x15(
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------.
      KC_F12,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,KC_TRNS,KC_TRNS,KC_TRNS,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_DEL,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
      KC_F11,KC_MINS,  KC_UP, KC_EQL,KC_HOME,KC_LBRC,KC_TRNS,KC_TRNS,KC_TRNS,KC_RBRC,KC_MINS,  KC_UP, KC_EQL,KC_TRNS,KC_PGUP,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT, KC_END,KC_LPRN,KC_TRNS,KC_TRNS,KC_TRNS,KC_RPRN,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_PGDN,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_TRNS,KC_MPRV,KC_MPLY,KC_MNXT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     KC_TRNS,KC_TRNS,KC_TRNS,MO(_ADJUST),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
  //`-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------'
  ),

  [_ADJUST] = LAYOUT_ortho_5x15(
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------.
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  ///-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------/
     RESET  ,XXXXXXX,XXXXXXX,_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
  //`-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------'
  ),

  // [_GAME] = LAYOUT_ortho_5x15(
  // //,----+----+----+----+----+----+----+----+----+----+----+----+----+----+----.
  //     ESC,   1,   2,   3,   4,   5,    ,    ,    ,  NO,  NO,  NO,  NO,  NO,  NO,
  // ///----+----+----+----+----+----+----+----+----+----+----+----+----+----+----/
  //    TAB ,   Q,   W,   E,   R,   T,    ,    ,    ,  NO,  NO,  NO,  NO,  NO,  NO,
  // ///----+----+----+----+----+----+----+----+----+----+----+----+----+----+----/
  //    CAPS,   A,   S,   D,   F,   G,    ,    ,    ,  NO,  NO,  NO,  NO,  NO,  NO,
  // ///----+----+----+----+----+----+----+----+----+----+----+----+----+----+----/
  //    LSFT,   Z,   X,   C,   V,   B,    ,    ,    ,  NO,  NO,  NO,  NO,  NO,  NO,
  // ///----+----+----+----+----+----+----+----+----+----+----+----+----+----+----/
  //    LCTL,LGUI,LALT,GAME,SPC , ENT,    ,    ,    ,  NO,  NO,  NO,  NO,  NO,GAME
  // //`----+----+----+----+----+----+----+----+----+----+----+----+----+----+----'
  // ),

};
