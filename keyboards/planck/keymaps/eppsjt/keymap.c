#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MEDIA,
  _FUNC,
  _NUMPAD,
};

// Custom keycodes for more complicated operations
enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    NUMPAD
};

// Aliases for momentary layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MEDIA MO(_MEDIA)

// Other aliases
#define ZOOM_IN  LGUI(KC_EQL)
#define ZOOM_OUT LGUI(KC_MINS)
#define ZOOM_NML LGUI(KC_0)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define LNG_TGL LALT(KC_GRV)

// Tap dance key configurations
#ifdef TAP_DANCE_ENABLE
  enum {
    TD_SFT_CAP = 0
  };

  qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SFT_CAP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
  };

  #define SFT_CAP TD(TD_SFT_CAP)
#endif
#ifndef TAP_DANCE_ENABLE
  #define SFT_CAP KC_LSFT
#endif

// Layout definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |*Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter*|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | Alt  | Media| Super| Lower|    Space    | Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    SFT_CAP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    KC_LCTL, KC_LALT, MEDIA,KC_LGUI,   LOWER,   KC_SPC,  KC_SPC,  RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LOWER
 * ,-----------------------------------------------------------------------------------.
 * |   ~  | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Enter|   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | NULL | NULL | NULL | NULL | NULL | NULL |   (  |   )  |   _  |   +  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDwn| PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL ,
    KC_ENT,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* RAISE
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | NULL | NULL | NULL | NULL |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDwn| PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* MEDIA AND MISC SHORTCUTS
 * ,-----------------------------------------------------------------------------------.
 * |LngTgl| NULL | NULL | NULL | NULL | NULL | NULL | NULL |Insert| NULL |PrntSc| NULL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BKSP | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift| NULL | NULL | NULL | NULL | NULL | NULL | NULL |ZoomOu|ZoomIn|Zoom 0| NULL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | NULL | NULL |      | NULL | Vol- |     Mute    | Vol+ | Prev | Stop | Play | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_planck_grid(
	LNG_TGL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,   XXXXXXX, KC_PSCR,  XXXXXXX,
	KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
	KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ZOOM_OUT, ZOOM_IN, ZOOM_NML, XXXXXXX,
	XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_VOLD, KC_MUTE, KC_MUTE, KC_VOLU, KC_MPRV,  KC_MSTP, KC_MPLY,  KC_MNXT
),

/* FUNCTIONS
 * ,-----------------------------------------------------------------------------------.
 * |      | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | NULL | NULL |AudOff|MusOff|QWERTY|NUMPAD|Mus On|Aud On| NULL | Null |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Reset|      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_planck_grid(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
	_______, XXXXXXX, XXXXXXX, AU_OFF,  MU_OFF,  QWERTY,  NUMPAD,  MU_ON,   AU_ON,   XXXXXXX, XXXXXXX, _______,
	_______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |QWERTY| NULL | NULL | NULL | NULL | NULL | NULL |   /  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Left | Down | Up   | Right|   *  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | NULL | BKSP |   1  |   2  |   3  |  Ent |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |   ,  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS,  KC_P7,  KC_P8,   KC_P9,   KC_PMNS,
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAST,  KC_P4,  KC_P5,   KC_P6,   KC_PPLS,
    _______, _______, _______, _______, _______, _______, XXXXXXX, KC_BSPC,  KC_P1,  KC_P2,   KC_P3,   KC_PENT,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_P0,  KC_PDOT, KC_PCMM, KC_PEQL
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2] = SONG(NUM_LOCK_OFF_SOUND);
float tone_numpad[][2] = SONG(NUM_LOCK_ON_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _FUNC);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    printf("%u\n", (unsigned int) keycode);
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_NUMPAD)) {
          #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_qwerty);
          #endif
          layer_off(_NUMPAD);
        }
      }
      return false;
    case NUMPAD:
      if (record->event.pressed) {
        if (!IS_LAYER_ON(_NUMPAD)) {
          #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_numpad);
          #endif
          layer_on(_NUMPAD);
        }
      }
      return false;
    }
    return true;
}
