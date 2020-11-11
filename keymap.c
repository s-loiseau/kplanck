#include QMK_KEYBOARD_H

#define CRALT RALT_T(KC_LBRC)
#define CLALT LALT_T(KC_EQL)
#define CTAB LGUI_T(KC_TAB)
#define CBSLS LGUI_T(KC_BSLS)
#define CESC LCTL_T(KC_ESC)
#define CQUO RCTL_T(KC_QUOT)
#define CNON LSFT_T(KC_GRV)
#define CENT RSFT_T(KC_ENTER)

#define CLOW LT(_LW, KC_INS)
#define CRAI LT(_RS, KC_LBRC)


#define _QW  0
#define _RS  1
#define _LW  2

/* Qwerty
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | WIN   |       | pgdn  | up    | pgup  |       |       |  del  |     ^ |     ç |prscrn | win   |
 * | TAB   |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |  \  à |
 * |       |   !   |   @   |   #   |   $   |   $   |   ^ ? |   &   |   *   |   (   |   )   |       |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * | CTL   | home  | left  | down  | right | end   |  f1   |  f2   |  f3   |  f4   |  f5   |  f6   |
 * | ESC   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |  "  é |
 * |       |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |       |
 * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
 * |       |   *   |   *   |   *   |   *   |       |  f7   |  f8   |  f9   |  f10  |  f11  | f12   |
 * |Sftns `|   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   / é |SftEtr |
 * |       |       |       |       |       |       |       |   ;   |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | vold  |volu   |       | mute  | Alt   | Lower |       | Ralt  | Raise |       |       | rst   |
 * | left  |right  | up    | down  |  -    |  ins  |Space  |   =   |   [   |   ]   |  DEL  | BSPC  |
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = LAYOUT_planck_grid(
CTAB,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CBSLS, \
CESC,    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CQUO, \
CNON,    KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, CENT, \
KC_LEFT, KC_RIGHT,KC_UP,   KC_DOWN, CLALT,    CLOW,    KC_SPACE,CRALT,   CRAI,    KC_RBRC, KC_DEL,  KC_BSPC \
),

[_LW] = LAYOUT_planck_grid(
_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
_______, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
_______, _______, _______, _______, _______,  _______, _______, KC_SCLN, _______, _______, _______, _______, \
_______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______ \
),

[_RS] = LAYOUT_planck_grid(
_______, XXXXXXX, KC_PGDN, KC_UP,   KC_PGUP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_PSCR, XXXXXXX, \
_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,  \
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12, \
KC_VOLD, KC_VOLU, XXXXXXX, KC_MUTE, _______,  _______, _______, XXXXXXX, KC_POWER, XXXXXXX, XXXXXXX, XXXXXXX \
)
};
