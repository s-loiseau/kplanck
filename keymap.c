#include QMK_KEYBOARD_H

/* ALT */
#define CRALT RALT_T(KC_EQL)
#define CLALT LALT_T(KC_MINS)

/* GUI */
#define CTAB LGUI_T(KC_TAB)
#define CBSLS LGUI_T(KC_BSLS)
#define CBSPC LGUI_T(KC_BSPC)

/* CTL */
#define CESC LCTL_T(KC_ESC)
#define CQUO RCTL_T(KC_QUOT)

/* SHIFT */
#define CGRV LSFT_T(KC_GRV)
#define CENT RSFT_T(KC_ENTER)

/* Shift hold, space tap : used on layer _LW allow to use number row for symbols */
#define CSPC LSFT_T(KC_SPACE)

/* LT layer */
#define CLOW LT(_LW, KC_BSLS)
#define CRAI LT(_RS, KC_SPACE)

/* Layers */
#define _QW  0
#define _RS  1
#define _LW  2

/* Qwerty
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | WIN   |  F1   |       |       |       |       |       |  PGDN |  UP ^ | PGUP  |prscrn | win   |
 * | TAB   |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  DEL  |
 * |       |   !   |   @   |   #   |   $   |   $   |   ^ ? |   &   |   *   |   (   |   )   |       |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * | CTL   |       |       |       |       |       | HOME  |  LEFT |  DOWN |  RIGH |  END  |       |
 * | ESC   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |  "  é |
 * |       |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |       |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |  F12  |       |       |       |       |       |       |       |
 * |Sftns `|   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   / é |SftEtr |
 * |       |   <   |       |   =   |   -   |   [   |   ]   |   ;   |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | vold  |volu   |       | mute  | Alt   | Lower |Raise  | Ralt  |       |       |       | rst   |
 * | left  |right  | up    | down  |  -    |   \   |Space  |   =   |   [   |   ]   |  DEL  | INS   |
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = LAYOUT_planck_grid(
CTAB,     KC_Q,     KC_W,    KC_E,    KC_R,    KC_T, \
KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    CBSPC, \
CESC,     KC_A,     KC_S,    KC_D,    KC_F,    KC_G, \
KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, CQUO, \
CGRV,     KC_Z,     KC_X,    KC_C,    KC_V,    KC_B, \
KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, CENT, \
KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT,   CLALT,   CLOW, \
CRAI, CRALT,    KC_LBRC,    KC_RBRC, KC_DEL,  KC_INS \
),

[_LW] = LAYOUT_planck_grid(
_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, \
KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  _______, \
_______, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    \
KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______, \
_______, KC_NUBS, _______, KC_EQL,  KC_MINS,  KC_LBRC, \
KC_RBRC, KC_SCLN, _______, _______, _______,  _______, \
_______, _______, _______, _______, _______,  _______, \
CSPC,    _______, _______, _______, _______,  _______ \
),

[_RS] = LAYOUT_planck_grid(
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, \
XXXXXXX, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, _______, \
_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, \
KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______, \
_______, KC_F9,   KC_F10,  KC_F11,   KC_F12, _______, \
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
KC_VOLD, KC_VOLU, XXXXXXX, KC_MUTE, _______, _______, \
_______, _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET \
)
};

/* retro_tapping_per_key */
/* avoid shift/enter to return enter each time */
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CLOW:
            return true;
        case CRAI:
            return true;
        case CSPC:
            return true;
        default:
            return false;
    }
}
