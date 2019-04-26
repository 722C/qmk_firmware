#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  GAME
};

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO


#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_GAME GAME

bool game_active = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.            ,----+----+----+----+----+----.
     GESC,   1,   2,   3,   4,   5,                6,   7,   8,   9,   0,BSPC,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     TAB ,   Q,   W,   E,   R,   T,                Y,   U,   I,   O,   P,BSLS,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     RASE,   A,   S,   D,   F,   G,                H,   J,   K,   L,SCLN,QUOT,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     LSFT,   Z,   X,   C,   V,   B,                N,   M,COMM, DOT,SLSH,RSFT,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     LCTL,LGUI,LALT,LOWR,LALT, ENT,              SPC,RASE,LEFT,  UP,DOWN,RGHT
  //`----+----+----+----+----+----'            `----+----+----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.            ,----+----+----+----+----+----.
     GRV ,EXLM, AT ,HASH,CLR ,PERC,             CIRC,AMPR,ASTR,LPRN,RPRN, DEL,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
         ,    ,    ,    ,    ,LBRC,             RBRC,  P7,  P8,  P9,PLUS,NLCK,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
         ,    ,    ,    ,    ,LPRN,             RPRN,  P4,  P5,  P6,MINS,BSLS,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
         ,    ,    ,    ,    ,    ,                 ,  P1,  P2,  P3, EQL,    ,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
         ,    ,    ,    ,    ,    ,                 ,    ,  P0,  P0, EQL,
  //`----+----+----+----+----+----'            `----+----+----+----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.            ,----+----+----+----+----+----.
      F12,  F1,  F2,  F3,  F4,  F5,               F6,  F7,  F8,  F9, F10, DEL,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
      F11,MINS,  UP, EQL,HOME,LBRC,             RBRC,MINS,  UP, EQL,    ,PGUP,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
         ,LEFT,DOWN,RGHT, END,LPRN,             RPRN,LEFT,DOWN,RGHT,    ,PGDN,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
         ,MPRV,MPLY,MNXT,    ,GAME,                 ,    ,    ,    ,    ,    ,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
         ,    ,    ,    ,    ,    ,                 ,    ,    ,    ,    ,TRNS
  //`----+----+----+----+----+----'            `----+----+----+----+----+----'
  ),

  [_ADJUST] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.            ,-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,             _______,_______,_______,_______,_______,_______,
  ///-------+-------+-------+-------+-------+-------/            /-------+-------+-------+-------+-------+-------/
     _______,_______,_______,_______,_______,_______,             _______,_______,_______,_______,_______,_______,
  ///-------+-------+-------+-------+-------+-------/            /-------+-------+-------+-------+-------+-------/
     _______,_______,_______,_______,_______,_______,             _______,_______,_______,_______,_______,_______,
  ///-------+-------+-------+-------+-------+-------/            /-------+-------+-------+-------+-------+-------/
     _______,_______,_______,_______,_______,_______,             _______,_______,_______,_______,_______,_______,
  ///-------+-------+-------+-------+-------+-------/            /-------+-------+-------+-------+-------+-------/
     RESET  ,DEBUG  ,_______,_______,_______,_______,              _______,_______,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+-------'            `-------+-------+-------+-------+-------+-------'
  ),

  [_GAME] = LAYOUT_kc(
  //,----+----+----+----+----+----.            ,----+----+----+----+----+----.
      ESC,   1,   2,   3,   4,   5,               NO,  NO,  NO,  NO,  NO,  NO,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     TAB ,   Q,   W,   E,   R,   T,               NO,  NO,  NO,  NO,  NO,  NO,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     CAPS,   A,   S,   D,   F,   G,               NO,  NO,  NO,  NO,  NO,  NO,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     LSFT,   Z,   X,   C,   V,   B,               NO,  NO,  NO,  NO,  NO,  NO,
  ///----+----+----+----+----+----/            /----+----+----+----+----+----/
     LCTL,LGUI,LALT,GAME,SPC , ENT,               NO,  NO,  NO,  NO,  NO,GAME
  //`----+----+----+----+----+----'            `----+----+----+----+----+----'
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        if (!game_active) {
          game_active = 1;
          layer_on(_GAME);
        } else {
          game_active = 0;
          layer_off(_GAME);
        }
      }
      return false;
      break;
  }
  return true;
}

