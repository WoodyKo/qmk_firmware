#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _FEATURE 5
#define _TEXT 6
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  FEATURE,
  TEXT,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty　デフォルト
 * ,----------------------------------------------------------------------------------------------------------.
 * |      Q    |      W    |    E   |    R    |     T    | Eisu |     -    |   Y  |   U  |   I  |   O  |   P  |
 * |-----------+-----------+--------+---------+----------+------+----------+------+------+------+------+------|
 * |      A    |      S    |    D   |    F    |     G    | Kana |     -    |   H  |   J  |   K  |   L  |   ;  |
 * |-----------+-----------+--------+---------+----------+------+----------+------+------+------+------+------|
 * |      Z    |      X    |    C   |    V    |     B    |  TAB |     -    |   N  |   M  |   ,  |   .  |   /  |
 * |-----------+-----------+--------+---------+----------+------+----------+------+------+------+------+------|
 * | RAISE,Eisu| LOWER,Kana| FEATURE| Ctrl,TAB| SFT,Space|  GUI | Alt,Enter| Bksp | Left | Down |  Up  |Right |
 * `----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_Q,                 KC_W,                 KC_E,    KC_R,          KC_T,          KC_LANG1, KC_MINS,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A,                 KC_S,                 KC_D,    KC_F,          KC_G,          KC_LANG2, KC_MINS,       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, \
  KC_Z,                 KC_X,                 KC_C,    KC_V,          KC_B,          KC_TAB,   KC_MINS,       KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
  LT(_RAISE, KC_LANG2), LT(_LOWER, KC_LANG1), FEATURE, CTL_T(KC_TAB), SFT_T(KC_SPC), KC_LGUI,  ALT_T(KC_ENT), KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT  \
),

/* Coding用
 * ,----------------------------------------------------------------------------------------------------------.
 * |      Q    |     W     |    E   |    R    |     T     |   {  |    }    |  Y   |  U   |  I   |  O   |  P   |
 * |-----------+-----------+--------+---------+-----------+------+---------+------+------+------+------+------|
 * |      A    |     S     |    D   |    F    |     G     |   (  |    )    |  H   |  J   |  K   |  L   |  ;   |
 * |-----------+-----------+--------+---------+-----------+------+---------+------+------+------+------+------|
 * |      Z    |     X     |    C   |    V    |     B     |   '  |    "    |  N   |  M   |  ,   |  .   |  /   |
 * |-----------+-----------+--------+---------+-----------+------+---------+------+------+------+------+------|
 * | RAISE,Eisu| LOWER,Kana| FEATURE| Ctrl,TAB| Alt,Space | GUI  |SFT,Enter| Bksp | Left | Down |  Up  |Right |
 * `----------------------------------------------------------------------------------------------------------'
 */
/*[_QWERTY] = LAYOUT_ortho_4x12(
 *   KC_Q,                KC_W,                KC_E,    KC_R,          KC_T,          KC_LCBR, KC_RCBR,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    \
 *   KC_A,                KC_S,                KC_D,    KC_F,          KC_G,          S(KC_9), S(KC_0),       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, \
 *   KC_Z,                KC_X,                KC_C,    KC_V,          KC_B,          KC_QUOT, S(KC_QUOT),    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
 *   LT(_RAISE, KC_LANG2), LT(_LOWER, KC_LANG1), FEATURE, CTL_T(KC_TAB), ALT_T(KC_SPC), KC_LGUI, SFT_T(KC_ENT), KC_BSPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT  \
 *),
 */

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT  \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* FEATURE 機能型
 * ,-----------------------------------------------------------------------------------.
 * |  LUP | LDOWN|      |      |      |      |      |      |      | Vol**| Vol- | Vol+ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | MPRV | MPlay| MNXT |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |QWERTY|      |      |      |      |      |      |      |      | Sleep|
 * `-----------------------------------------------------------------------------------'
 */
[_FEATURE] = LAYOUT_ortho_4x12( \
  RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP  \
),

/* Text　文章系
* ,-----------------------------------------------------------------------------------.
* |   Q  |   W  |   E  |   R  |   T  |   {  |   }  |   Y  |   U  |   I  |   O  |   P  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |   A  |   S  |   D  |   F  |   G  |   (  |  )   |   H  |   J  |   K  |   L  |   ;  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |   Z  |   X  |   C  |   V  |   B  |  '   |  "   |   N  |   M  |   ,  |   .  |   /  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Esc  | Alt  |RAISE | Ctrl | Shift| GUI  | Enter| Bksp | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
[_TEXT] = LAYOUT_ortho_4x12(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LCBR, KC_RCBR, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN, KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT, KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  KC_ESC,  KC_LALT, RAISE, KC_LCTL, KC_LSFT,   KC_LGUI, KC_ENT,  KC_BSPC, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT  \
),

/* Lower 記号系
* ,-----------------------------------------------------------------------------------.
* |   !  |   "  |   #  |   $  |   %  |   &  |   '  |   =  |   -  |   ~  |   ^  |   |  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |   `  |   @  |   [  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |   ?  |      |      |      |      |      |      |ISO ~ |ISO | |      |      |   ]  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |Enter | Space| Bksp |   ;  |   :  |   _  |
* `-----------------------------------------------------------------------------------'
*/
[_LOWER] = LAYOUT_ortho_4x12( \
 KC_EXLM, KC_QUOT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_QUOT,       KC_EQL,     KC_MINS,    KC_TILD, KC_CIRC,    KC_PIPE, \
 _______, _______, _______, _______, _______, _______, _______,       _______,    _______,    _______, KC_AT,      KC_LBRC, \
 _______, _______, _______, _______, _______, _______, _______,       S(KC_NUHS), S(KC_NUBS), KC_SCLN, KC_COLN,    KC_RBRC, \
 _______, _______, _______, _______, _______, _______, SFT_T(KC_ENT), KC_BSPC,    KC_COMM,    KC_DOT,  S(KC_SLSH), KC_UNDS  \
),

/* Raise　数字系
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |      |      |      |      |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |      |      |      |      |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F9  |  F10 |  F11 |  F12 |      |      |ISO # |ISO / |   1  |   2  |   3  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Enter| Space|   0  | Bksp |   =  |   /  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______,       _______, KC_7, KC_8,    KC_9,   KC_MINS, \
  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______,       _______, KC_4, KC_5,    KC_6,   KC_PLUS, \
  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_NUHS,       KC_NUBS, KC_1, KC_2,    KC_3,   KC_ASTR, \
  _______, _______, _______, _______, _______, _______, SFT_T(KC_ENT), KC_BSPC, KC_0, KC_BSPC, KC_EQL, KC_SLSH  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

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
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case FEATURE:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_FEATURE);
      }
      return false;
      break;
    case TEXT:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_TEXT);
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
  }
  return true;
}
