#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMBOL 1
#define _MEDRGB 3

/* enum custom_keycodes { */
/*     QWERTY = SAFE_RANGE, */
/*     SYMB, */
/*     NAV, */
/*     ADJUST, */
/* }; */

// Shortcuts for layer selection mods
#define MED_RGB MO(_MEDRGB)         // switch to media & rgb layer whilst held
#define SYM_SPC LT(_SYMBOL, KC_SPC) // switch to symbol layer whilst held, K_SPC when tapped

// Shortcuts for keypress mods
// #define CTL_ESC CTL_T(KC_ESC) // ESC on tap, CTL on hold
#define GUI_ENT GUI_T(KC_ENTER)  // ENTER on tap, GUI on hold
#define BSLS_SFT RSFT_T(KC_BSLS) // Backslask on tap, RShift on hold

// Unicode & Emoji key names
enum unicode_names { JOY, SWEAT, SMILE, THUMB, OKAY, HUND, TADA };
const uint32_t PROGMEM unicode_map[] = {
    [JOY]   = 0x1F602, // 😂
    [SWEAT] = 0x1F605, // 😅
    [SMILE] = 0x1F642, // 🙂
    [THUMB] = 0x1F44D, // 👍
    [OKAY]  = 0x1F44C, // 👌
    [HUND]  = 0x1F4AF, // 💯
    [TADA]  = 0x1F389, // 🎉
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_DEL  ,                          KC_BSPC ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_EQL  ,                          KC_MINS ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOTE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,BSLS_SFT,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_LALT ,    SYM_SPC ,GUI_ENT ,        GUI_ENT ,SYM_SPC ,    MED_RGB ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,X(TADA) ,X(HUND) ,X(OKAY) ,X(THUMB),_______ ,                          _______ ,KC_EXLM ,KC_LPRN ,KC_RPRN ,KC_F11  ,KC_F12  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,X(SWEAT),X(SMILE),X(JOY)  ,XXXXXXX ,_______ ,                          _______ ,KC_HASH ,KC_LCBR ,KC_RCBR ,KC_DLR  ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,KC_LBRC ,KC_RBRC ,KC_LABK ,KC_RABK ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_MEDRGB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,DM_PLY1 ,DM_PLY2 ,DM_REC1 ,DM_REC2 ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_RBT  ,XXXXXXX ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,KC_PSCR ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,RGB_HUD ,RGB_HUI ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_MNXT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_BOOT ,XXXXXXX ,RGB_SAD ,RGB_SAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MPLY ,KC_MUTE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     RGB_TOG ,    RGB_M_P ,RGB_MOD ,        XXXXXXX ,XXXXXXX ,    _______ ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};
// clang-format on
