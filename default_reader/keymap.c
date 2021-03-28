#include QMK_KEYBOARD_H

//----------------------------------------------------------------------------------------------------------------------------------------------------------
//aqui inicializamos la capaz del teclado
enum sofle_layers { 
    _QWERTY, 
    _DVORAK,
    _LOWER,
    _RAISE, 
    _ADJUST,
}; 

//----------------------------------------------------------------------------------------------------------------------------------------------------------
//aquie inicializamos las teclas especiales del teclado
enum custom_keycodes { 
    KC_QWERTY = SAFE_RANGE,
    KC_DVORAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE, 
    KC_GRAPH, 
    KC_TERM,

};

//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Aca estan inicializadas las funciones de tabdance
enum  {
    TD_CAPLOCK, 
    TD_QUOT,
};  

//----------------------------------------------------------------------------------------------------------------------------------------------------------
//AQUI EMPIEZAN LAS CAPAS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   \  |  /   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RALT |  [   |    ] |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
            KC_ESC,  KC_1,   KC_2,     KC_3,    KC_4,     KC_5,                               KC_6,     KC_7,     KC_8,     KC_9,    KC_0, KC_MINS, \
            KC_GRV,  KC_Q,   KC_W,     KC_E,    KC_R,     KC_T,                               KC_Y,     KC_U,     KC_I,     KC_O,    KC_P, KC_BSPC, \
            KC_TAB,  KC_A,   KC_S,     KC_D,    KC_F,     KC_G,                               KC_H,     KC_J,     KC_K,     KC_L, KC_SCLN, TD(TD_QUOT), \
    TD(TD_CAPLOCK),  KC_Z,   KC_X,     KC_C,    KC_V,     KC_B,  KC_MUTE,        XXXXXXX,     KC_N,     KC_M,  KC_COMM,   KC_DOT, KC_BSLS, KC_SLSH, \
                          KC_LGUI,  KC_LALT, KC_LCTL, KC_LOWER,   KC_ENT,         KC_SPC, KC_RAISE,  KC_RALT,  KC_LBRC,  KC_RBRC  \
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | `    |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |CAPS  |   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RALT |  [   |    ] |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_DVORAK] = LAYOUT( \
                KC_ESC,        KC_1,    KC_2,    KC_3,     KC_4,     KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_SLSH, \
                KC_GRV, TD(TD_QUOT), KC_COMM,  KC_DOT,     KC_P,     KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_BSPC, \
                KC_TAB,        KC_A,    KC_O,    KC_E,     KC_U,     KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  KC_MINS, \
        TD(TD_CAPLOCK),     KC_SCLN,    KC_Q,    KC_J,     KC_K,     KC_X,  KC_MUTE,  XXXXXXX,     KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_BSLS, \
                                     KC_LGUI, KC_LALT,  KC_LCTL, KC_LOWER,   KC_ENT,   KC_SPC, KC_RAISE, KC_RALT, KC_LBRC, KC_RBRC  \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
   KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, \
   KC_GRV,    KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,                      KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,  KC_F12, \
   KC_CAPS, KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
   KC_LSFT,  KC_EQL,  KC_MINS,  KC_PLUS,  KC_LCBR,  KC_RCBR, _______,  _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_SLSH, \
                      KC_LGUI,  KC_LALT,  KC_LCTL,  XXXXXXX,  KC_ENT,   KC_SPC, XXXXXXX, KC_RALT, KC_LABK, KC_RABK\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  XXXXXXX, KC_GRAPH, XXXXXXX, XXXXXXX, KC_TERM,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                          KC_PGUP, KC_PRVWD,    KC_UP, KC_NXTWD, KC_DLINE, KC_BSPC,  \
  KC_CAPS,  KC_INS, KC_PSCR,  KC_END,  KC_HOME,  KC_APP,                          KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_FIND, XXXXXXX,  \
  KC_LSFT, KC_UNDO,  KC_CUT, KC_COPY, KC_PASTE,  KC_DEL, XXXXXXX,         XXXXXXX,XXXXXXX,  KC_CALC,  KC_MAIL,  KC_MYCM,  XXXXXXX, XXXXXXX,  \
                      _______, _______, _______, _______, KC_ENT,         KC_SPC, XXXXXXX,  KC_RALT, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |LONOFF| LMODE| LMODE| LHUE | LSAD | LVAL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|DVORAK|MACWIN|      |                    |      |      | LMODE| LHUE | LSAD | LVAL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |SLIGHT|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |SLIGHT|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX,   UC_M_LN,    UC_M_WC, UC_M_MA,   UC_MOD,                       RGB_TOG, RGB_M_B, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,  \
  RESET,   XXXXXXX, KC_QWERTY,  KC_DVORAK, CG_TOGG,  UC_RMOD,                       XXXXXXX, XXXXXXX, RGB_M_R, RGB_HUD, RGB_SAD, RGB_VAD, \
  XXXXXXX, XXXXXXX,   CG_TOGG,    XXXXXXX, XXXXXXX,  XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, KC_BRIU, \
  XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_BRID, \
                          _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//ESTAS SON LAS FUNCIONES CAPSLOCK
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),

};  





//----------------------------------------------------------------------------------------------------------------------------------------------------------
//estas son las funciones de las teclas especiales  
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case KC_DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;

        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;

        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
            
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;

        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;

        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;

        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;

        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;

        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;

        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;

        case KC_TERM:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_F4);
            } else {
                unregister_mods(mod_config(MOD_LALT));
                unregister_code(KC_F4);
            }
            return false;

        case KC_GRAPH:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_F1);
            } else {
                unregister_mods(mod_config(MOD_LALT));
                unregister_code(KC_F1);
            }
            return false;

    }
    return true;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//En esta seccion viene la parte de los ecoders 
#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

#endif  
 
//----------------------------------------------------------------------------------------------------------------------------------------------------------
//en esta seccion controla los oled  

//primero leemos el estado de las capas
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}