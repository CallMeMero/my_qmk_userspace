/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀   ┌─┐┌─╴╷┌──┬─
                                                           ▀  ▀  ▀          │ ┐├─╴│└─┐│
                                                                            └─┘└─╴╵╶─┘╵
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "callmemero.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum totem_layers {
    _BASE,
    _NAV,
    _NUM,
    _FUN,
    _UTIL
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
    NAV = SAFE_RANGE,
    NUM,
    FUN,
    UTIL
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define CTL_A MT(MOD_LCTL, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define GUI_D MT(MOD_LGUI, KC_D)
#define SHT_F MT(MOD_LSFT, KC_F)
#define HYP_V MT(MOD_HYPR, KC_V)
#define MEH_C MT(MOD_MEH, KC_C)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SHT_J MT(MOD_RSFT, KC_J)
#define GUI_K MT(MOD_LGUI, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define CTL_QUOT MT(MOD_LCTL, KC_QUOT)
#define HYP_M MT(MOD_HYPR, KC_M)
#define MEH_COM MT(MOD_MEH, KC_COMM)

// LAYER TAP KEYS          ├───────────────────────────────────┐

#define NAV LT(_NAV, KC_SPACE)
#define NUM LT(_NUM, KC_BSPC)
#define FUN LT(_FUN, KC_DEL)
#define UTIL LT(_UTIL, KC_ESC)

// OTHER KEY DEFINITIONS   ├───────────────────────────────────┐

#define OS_SHT OSM(MOD_LSFT)


// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                       │
// └─────────────────────────────────────────────────┘

// Left hand vertical combos
// Between top and home row
const uint16_t PROGMEM at_combo[] = {KC_W, ALT_S, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_E, GUI_D, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_R, SHT_F, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {KC_T, KC_G, COMBO_END};

// Between home and bottom row
const uint16_t PROGMEM grave_combo[] = {ALT_S, KC_X, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {GUI_D, MEH_C, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {SHT_F, HYP_V, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {KC_G, KC_B, COMBO_END};

// horizontal combos
const uint16_t PROGMEM esc_combo[] = {ALT_S, SHT_F, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, MEH_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {MEH_C, HYP_V, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, HYP_V, COMBO_END};

// Right hand vertical combos
// Between top and home row
const uint16_t PROGMEM caret_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_U, SHT_J, COMBO_END};
const uint16_t PROGMEM star_combo[] = {KC_I, GUI_K, COMBO_END};
const uint16_t PROGMEM amp_combo[] = {KC_O, ALT_L, COMBO_END};

// Between home and bottow row
const uint16_t PROGMEM unds_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM mins_combo[] = {SHT_J, HYP_M, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {GUI_K, MEH_COM, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {ALT_L, KC_DOT, COMBO_END};

// Horizontal combos: brackets
const uint16_t PROGMEM lsqr_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM rsqr_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lpar_combo[] = {SHT_J, GUI_K, COMBO_END};
const uint16_t PROGMEM rpar_combo[] = {GUI_K, ALT_L, COMBO_END};
const uint16_t PROGMEM lcbr_combo[] = {HYP_M, MEH_COM, COMBO_END};
const uint16_t PROGMEM rcbr_combo[] = {MEH_COM, KC_DOT, COMBO_END};

// Vertical combos: Umlaute
const uint16_t PROGMEM ae_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {SHT_F, KC_G, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {HYP_V, KC_B, COMBO_END};
const uint16_t PROGMEM sz_combo[] = {KC_Y, KC_U, COMBO_END};

const uint16_t PROGMEM lt_combo[] = {KC_H, SHT_J, COMBO_END};
const uint16_t PROGMEM gt_combo[] = {ALT_L, CTL_QUOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(at_combo, KC_AT),
  COMBO(hash_combo, KC_HASH),
  COMBO(dollar_combo, KC_DLR),
  COMBO(perc_combo, KC_PERC),
  COMBO(grave_combo, KC_GRV),
  COMBO(bsls_combo, KC_BSLS),
  COMBO(eql_combo, KC_EQL),
  COMBO(tilde_combo, KC_TILD),
  COMBO(esc_combo, KC_ESC),
  COMBO(copy_combo, LCTL(KC_C)),
  COMBO(paste_combo, LCTL(KC_V)),
  COMBO(cut_combo, LCTL(KC_X)),
  COMBO(caret_combo, KC_CIRC),
  COMBO(plus_combo, KC_PLUS),
  COMBO(star_combo, KC_ASTR),
  COMBO(amp_combo, KC_AMPR),
  COMBO(unds_combo, KC_UNDS),
  COMBO(mins_combo, KC_MINS),
  COMBO(slsh_combo, KC_SLSH),
  COMBO(pipe_combo, KC_PIPE),
  COMBO(lsqr_combo, KC_LBRC),
  COMBO(rsqr_combo, KC_RBRC),
  COMBO(lpar_combo, KC_LPRN),
  COMBO(rpar_combo, KC_RPRN),
  COMBO(lcbr_combo, KC_LCBR),
  COMBO(rcbr_combo, KC_RCBR),
  COMBO(ae_combo, RALT(KC_Q)),
  COMBO(oe_combo, RALT(KC_P)),
  COMBO(ue_combo, RALT(KC_Y)),
  COMBO(lt_combo, KC_LT),
  COMBO(gt_combo, KC_GT),
  COMBO(sz_combo, RALT(KC_S))
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y   o v e r r i d e s         │
// └─────────────────────────────────────────────────┘

// shift + ? = !
const key_override_t quexclam_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);

// Override comma key: no mod = , | shift = ; | ctrl+shift = <
const key_override_t semicolon_override =
  ko_make_with_layers_negmods_and_options(
      MOD_MASK_SHIFT,       // Trigger modifiers: shift
      MEH_COM,             // Trigger key: meh_comma hold tap key
      KC_SCLN,             // Replacement key: ;
      ~0,                  // Activate on all layers
      MOD_MASK_CA,         // Do not activate when ctrl, alt or gui is pressed
      ko_option_no_reregister_trigger);
const key_override_t lt_override =
  ko_make_with_layers_negmods_and_options(
    MOD_MASK_CS,      // Trigger modifiers: ctrl+shift
    MEH_COM,         // Trigger key: meh_comma hold tap key
    KC_LT,         // Replacemeng key: <
    ~0,              // All layers
    MOD_MASK_AG,     // Do not activate when alt or gui is pressed
    ko_option_no_reregister_trigger);

// Override . key: no mod = . | shift = : | ctrl+shift = >
const key_override_t colon_override =
  ko_make_with_layers_negmods_and_options(
      MOD_MASK_SHIFT,      // Trigger modifiers: shift
      KC_DOT,              // Trigger key: dot key
      KC_COLN,             // Replacement key: :
      ~0,                  // Activate on all layers
      MOD_MASK_CA,        // Do not activate when ctrl or alt is pressed
      ko_option_no_reregister_trigger);
const key_override_t gt_override =
  ko_make_with_layers_negmods_and_options(
    MOD_MASK_CS,           // Trigger modifiers: ctrl+shift
    KC_DOT,                // Trigger key: dot key
    KC_GT,                 // Replacemeng key: >
    ~0,                    // All layers
    MOD_MASK_AG,           // Do not activate when alt or gui is pressed
    ko_option_no_reregister_trigger);

// This globally defines all key overrides to be used ├───────────┐
const key_override_t *key_overrides[] = {
  &quexclam_override,
  &semicolon_override,
  &lt_override,
  &colon_override,
  &gt_override
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
   ┌─────────────────────────────────────────────────┐
   │ b a s e                                         │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    A    │    S    │    D    │    F    │    G    ││    H    │    J    │    K    │    L    │    '    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   TAB   │    Y    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,;   │    .:   │   ?!    │  ALT_GR │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  UTIL   │  NAV    │  SHIFT  ││   ENT   │    NUM  │   FUN   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

   [_BASE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
              CTL_A,    ALT_S,    GUI_D,    SHT_F,    KC_G,      KC_H,     SHT_J,    GUI_K,    ALT_L,    CTL_QUOT,
    OS_SHT,   KC_Z,     KC_X,     MEH_C,    HYP_V,    KC_B,      KC_N,     HYP_M,    MEH_COM,  KC_DOT,   KC_QUES,  KC_RALT,
                                  UTIL,     NAV,      KC_TAB,    KC_ENT,      NUM,      FUN
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ n a v                                           │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │         │         ││         │  HOME   │   UP    │   END   │  PGUP   │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │  CTRL   │  ALT    │  CMD    │   SHFT  │         ││         │  LEFT   │  DOWN   │  RIGHT  │  PGDN   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │  MEH    │  HYPR   │         ││         │   ~     │         │    /    │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││   ENT   │  BSPC   │   DEL   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_NAV] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______, _______,    _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,
              KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT, _______,    _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,
    _______,  _______,  _______,  KC_MEH,   KC_HYPR, _______,    _______,  KC_TILD,  _______,  KC_SLSH,  _______,   _______,
                                  _______,  _______, _______,    KC_ENT,   KC_BSPC,   KC_DEL
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ n u m                                           │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
             │    +    │    7    │    8    │    9    │    *    ││         │         │         │         │         │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    0    │    4    │    5    │    6    │    =    ││         │   SHFT  │   CMD   │   ALT   │   CTRL  │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    (    │    -    │    1    │    2    │    3    │    /    ││         │   HYPR  │   MEH   │         │         │    )    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │    .    │    :    ││         │         │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_NUM] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_PLUS,    KC_7,    KC_8,     KC_9,    KC_ASTR,   _______,  _______,  _______,  _______, _______,
              KC_0,       KC_4,    KC_5,     KC_6,    KC_EQL,    _______,  KC_LSFT,  KC_LGUI,  KC_LALT, KC_LCTL,
    KC_LPRN,  KC_MINS,    KC_1,    KC_2,     KC_3,    KC_SLSH,   _______,  KC_HYPR,  KC_MEH,   _______, _______,  KC_RPRN,
                                   _______,  KC_DOT,  KC_SCLN,   _______,  _______,  _______
 ),
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ f u n c t i o n                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
             │   F12   │   F7    │   F8    │   F9    │         ││         │         │         │         │         │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │   F11   │   F4    │   F5    │   F6    │         ││         │  SHFT   │   CMD   │   ALT   │  CTRL   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │   F10   │   F1    │   F2    │   F3    │         ││         │  HYPR   │   MEH   │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││         │         │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_FUN] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_F12,   KC_F7,    KC_F8,    KC_F9,   _______,  _______,  _______,  _______,  _______,   _______,
               KC_F11,   KC_F4,    KC_F5,    KC_F6,   _______,  _______,  KC_LSFT,  KC_LGUI,  KC_LALT, KC_LCTL,
    _______,   KC_F10,   KC_F1,    KC_F2,    KC_F3,   _______,  _______,  KC_HYPR,  KC_MEH,   _______, _______,  _______,
                                _______,  _______,   _______,   _______,  _______,  _______
 ),
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ u t i l i t y                                   │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
             │   BOOT  │         │         │         │         ││    €    │  <<<<<  │  VOL+   │  >>>>>  │         │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │         │         │         │         │         ││         │         │  VOL-   │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ││         │         │  PL/PA  │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││         │         │  MUTE   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_UTIL] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              QK_BOOT,  _______,  _______,  _______,   _______,  RALT(KC_5),  KC_MPRV,  KC_VOLU,  KC_MNXT,   _______,
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_VOLD,  _______,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_MPLY,  _______,   _______, _______,
                                  _______,  _______,   _______,  _______,  _______,  KC_MUTE
 )
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// Make sure combos are always tapped and not held
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    return true;

}


/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/



