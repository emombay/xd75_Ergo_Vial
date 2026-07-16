#include QMK_KEYBOARD_H

enum layers {
    _WORK,   // Workman (default)
    _QWERTY, // QWERTY
    _SYMB,   // symbols
    _UTIL,   // utility / shortcuts
    _NUM,    // numpad + mouse keys
    _ADJ,    // adjust keys
    _GAME,   // game keys
};

// Named keycodes exposed in Vial's keycode picker ("User" tab). Order must
// match the customKeycodes array in vial.json. The keymap grid below uses the
// equivalent built-ins (MO/PDF/TT/EE_CLR); these exist so keys reassigned from
// the Vial app get friendly names.
enum custom_keycodes {
    WRKMN = QK_KB_0, // persistent default layer: Workman
    QWERTY,          // persistent default layer: QWERTY
    SYMB,            // momentary Symbols layer
    UTIL,            // momentary Util layer
    NUM,             // momentary Numpad layer
    ADJUST,          // momentary Adjust layer
    GAME,            // toggle Game layer
    EPRM,            // reset EEPROM to defaults
    ALTTAB,          // hold-to-repeat Alt+Tab
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Workman layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |   `    | 1      | 2      | 3      | 4      | 5      | UNDO   |PrintSc |  Redo  | 6      | 7      | 8      | 9      | 0      | NUM    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | D      | R      | W      | B      | DELETE | CAPS   |CRTL+Win| J      | F      | U      | P      | ;      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CODE   | A      | S      | H      | T      | G      | _      | Esc    | Meh    | Y      | N      | E      | O      | I      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | M      | C      | V      | App    | COPY   | BackSp | K      | L      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | AltTab |  LGui  |  Alt   | RCTRL  |  UTIL  | BackSp | PASTE  | Enter  | SPACE  |  Left  |  Down  |   Up   | Right  | TT(NUM)|
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_WORK] = LAYOUT_ortho_5x15(
    KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,   KC_5,      C(KC_Z), KC_PSCR, C(KC_Y),     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    TO(_NUM),
    KC_TAB,  KC_Q,     KC_D,    KC_R,    KC_W,   KC_B,      KC_DEL,  KC_CAPS, C(G(KC_NO)), KC_J,   KC_F,   KC_U,    KC_P,    KC_SCLN, KC_BSLS,
    MO(_SYMB),KC_A,    KC_S,    KC_H,    KC_T,   KC_G,      KC_UNDS, KC_ESC,  KC_MEH,      KC_Y,   KC_N,   KC_E,    KC_O,    KC_I,    KC_QUOT,
    KC_LSFT, KC_Z,     KC_X,    KC_M,    KC_C,   KC_V,      KC_APP,  C(KC_C), KC_BSPC,     KC_K,   KC_L,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, ALTTAB,   KC_LGUI, KC_LALT, KC_RCTL,MO(_UTIL), KC_BSPC, C(KC_V), KC_ENT,      KC_SPC, KC_LEFT,KC_DOWN, KC_UP,   KC_RGHT, TT(_NUM)
 ),
/* Keymap 1: Basic layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | Q      | W      | E      | R      | T      |        |        |        | Y      | U      | I      | O      | P      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | A      | S      | D      | F      | G      |        |        |        | H      | J      | K      | L      | ;      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | Z      | X      | C      | V      | B      |        |        |        | N      | M      | ,      | .      | /      |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = LAYOUT_ortho_5x15(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______  ,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______  ,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______  ,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______  ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* Keymap 2: Symbol Layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |  +     |  =     |  {     |  }     | |      |        |        |        |        | TD_2EQ |        |        |        | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | &      |  -     |  (     |  )     | `      |        |        |        |        | TD_3EQ | TD_FUN |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | <      |  >     |  [     |  ]     |  ~     |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        | F8     | F9     | F10    | F11    |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
// SYMBOLS
// NOTE: the 3 positions below were TD_2EQ/TD_3EQ/TD_FUN in the original custom
// tap-dance implementation (tap "==" / "===" / "=>", double-tap "!=" / "!==" / "() => {}").
// Vial's own tap-dance system owns `tap_dance_actions[]`, so those custom SEND_STRING
// dances were removed here; recreate them from the Vial app's Tap Dance + Macro tabs,
// then reassign these KC_NO placeholders to the resulting TD(n) keycodes.
 [_SYMB] = LAYOUT_ortho_5x15( /* QWERTY */
    _______, KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    _______, KC_PLUS, KC_EQL,  KC_LCBR,KC_RCBR,KC_PIPE, _______, _______, _______, _______, KC_NO,   _______, _______, _______, KC_F12  ,
    _______, KC_AMPR, KC_MINS, KC_LPRN,KC_RPRN,KC_GRV,  _______, _______, _______, _______, KC_NO,   KC_NO,   _______, _______, _______  ,
    _______, KC_LT,   KC_GT,   KC_LBRC,KC_RBRC,KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______  ,
    _______, KC_F8,   KC_F9,   KC_F10, KC_F11, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* Keymap 3: UTIL Layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |Ctrl+Tab|        | Ctrl+D | Ctrl+R | Ctrl+W |        |        |        |        |        | Ctrl+F |        | Ctrl+P |        | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | All    | Save   |        |Ctrl+T  |        |        |        |        |        | Home   | PgDown | PgUp   | End    | Insert |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        | Cut    |        | Copy   | Paste  |        |        |        | Prev   | Next   | Vol-   | Vol+   | Play   |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        | Undo   | Redo   |        |        |        |        |        | Ctrl+< | Ctrl+^ | Ctrl+v | Ctrl+> |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_UTIL] = LAYOUT_ortho_5x15( /* QWERTY */
    _______,      KC_F1,   KC_F2,     KC_F3,     KC_F4,      KC_F5,   _______, _______, _______, KC_F6,   KC_F7,     KC_F8,     KC_F9,      KC_F10,     KC_F11  ,
    C(KC_TAB),    _______, C(KC_D),   C(KC_R),   C(KC_W),    _______, _______, _______, _______, _______, C(KC_F),   _______,   C(KC_P),    _______,    KC_F12  ,
    _______,      C(KC_A), C(KC_S),   _______,   C(KC_T),    _______, _______, _______, _______, _______, KC_HOME,   KC_PGDN,   KC_PGUP,    KC_END,     KC_INS  ,
    _______,      _______, C(KC_X),   _______,   C(KC_C),    C(KC_V), _______, _______, _______, KC_MPRV, KC_MNXT,   KC_VOLD,   KC_VOLU,    KC_MPLY,    _______  ,
    _______,      _______, _______,   C(KC_Z),   C(KC_Y),    _______, _______, _______, _______, _______, C(KC_LEFT),C(KC_DOWN),C(KC_UP),   C(KC_RGHT), _______
 ),
/* Keymap 4: Numpad Layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        | NumLk  | /      | *      | -      | ADJUST |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        | Lclk   | MsUp   | Rclk   |        |        |        |        |        | 7      | 8      | 9      | +      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        | MsLeft | MsDown | MsRght |        |        |        |        |        | 4      | 5      | 6      | +      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        | App    |        |        |        |        |        | 1      | 2      | 3      | Enter  |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | 0      | 0      | .      | =      |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NUM] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, TO(_ADJ)  ,
    _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______  ,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______  ,
    _______, _______, _______, _______, KC_APP,  _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______  ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_EQL,  _______
 ),
/* Keymap 5: Adjust
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        | Bright-| WRKM   | Hue-   |        | EE_CLR |        | AGnorm | AGswap | Game   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        | Bright+| QWRTY  | Hue+   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        | Animat |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[_ADJ] = LAYOUT_ortho_5x15(
     _______, _______, _______, _______, _______, _______, RM_VALD, PDF(_WORK),   RM_HUED, _______, EE_CLR,  _______, AG_NORM, AG_SWAP, TO(_GAME),
     _______, _______, _______, _______, _______, _______, RM_VALU, PDF(_QWERTY), RM_HUEU, _______, _______, _______, _______, _______, _______  ,
     _______, _______, _______, _______, _______, _______, _______, RM_NEXT,      _______, _______, _______, _______, _______, _______, _______  ,
     _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______  ,
     _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
  ),

/* Keymap 6: Game
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | Wrkmn  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |    ;   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | Space  |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_5x15(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_WORK),
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  ,
     KC_SCLN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  ,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  ,
     _______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

// --- Hold-to-repeat Alt+Tab -------------------------------------------------
// Each ALTTAB tap sends Tab with Alt held; Alt is released by a deferred
// callback once no tap has happened for ALT_TAB_TIMEOUT_MS.

#define ALT_TAB_TIMEOUT_MS 1000

static deferred_token alt_tab_token = INVALID_DEFERRED_TOKEN;

static uint32_t alt_tab_release(uint32_t trigger_time, void *cb_arg) {
    unregister_code(KC_LALT);
    alt_tab_token = INVALID_DEFERRED_TOKEN;
    return 0; // one-shot: do not repeat
}

// Momentary layer helper for the custom layer keycodes above.
static void momentary_layer(uint8_t layer, keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(layer);
    } else {
        layer_off(layer);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WRKMN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORK);
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case SYMB:
            momentary_layer(_SYMB, record);
            return false;
        case UTIL:
            momentary_layer(_UTIL, record);
            return false;
        case NUM:
            momentary_layer(_NUM, record);
            return false;
        case ADJUST:
            momentary_layer(_ADJ, record);
            return false;
        case GAME:
            if (record->event.pressed) {
                layer_invert(_GAME);
            }
            return false;
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
        case ALTTAB:
            if (record->event.pressed) {
                if (alt_tab_token == INVALID_DEFERRED_TOKEN) {
                    register_code(KC_LALT);
                    alt_tab_token = defer_exec(ALT_TAB_TIMEOUT_MS, alt_tab_release, NULL);
                } else {
                    extend_deferred_exec(alt_tab_token, ALT_TAB_TIMEOUT_MS);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
    }
    return true;
}

// --- Per-layer RGB tint ------------------------------------------------------
// Uses the _noeeprom variants so layer changes never wear the EEPROM.

#ifdef RGB_MATRIX_ENABLE
static const hsv_t layer_colors[] = {
    [_WORK]   = {RGB_MATRIX_COLOR_LAYER_0},
    [_QWERTY] = {RGB_MATRIX_COLOR_LAYER_1},
    [_SYMB]   = {RGB_MATRIX_COLOR_LAYER_2},
    [_UTIL]   = {RGB_MATRIX_COLOR_LAYER_3},
    [_NUM]    = {RGB_MATRIX_COLOR_LAYER_4},
    [_ADJ]    = {RGB_MATRIX_COLOR_LAYER_5},
    [_GAME]   = {RGB_MATRIX_COLOR_LAYER_6},
};

static void set_layer_color(uint8_t layer) {
    if (layer >= ARRAY_SIZE(layer_colors)) {
        return;
    }
    hsv_t hsv = layer_colors[layer];
    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
}

void keyboard_post_init_user(void) {
    set_layer_color(get_highest_layer(layer_state | default_layer_state));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_layer_color(get_highest_layer(state | default_layer_state));
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    set_layer_color(get_highest_layer(layer_state | state));
    return state;
}
#endif
