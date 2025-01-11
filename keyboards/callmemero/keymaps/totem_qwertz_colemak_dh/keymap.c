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
// │ d e f i n e   q w e r t z   m a p p i n g       │
// └─────────────────────────────────────────────────┘

#define QWERTZ_SINGLE_QUOTE S(KC_BSLS)  //
#define QWERTZ_DOUBLE_QUOTE KC_AT  //
#define QWERTZ_Z KC_Y  //
#define QWERTZ_Y KC_Z  //
#define QWERTZ_QUES KC_UNDS  //
#define QWERTZ_EXLM KC_EXLM  //
#define QWERTZ_AT RALT(KC_Q)  //
#define QWERTZ_HASH KC_BSLS  //
#define QWERTZ_TICK KC_EQL  // ´
#define QWERTZ_BSLS RALT(KC_MINS)  // \/
#define QWERTZ_EQL KC_RPRN  //
#define QWERTZ_TILD RALT(KC_RBRC)  //
#define QWERTZ_CIRC KC_GRV  //
#define QWERTZ_PPLS KC_RBRC  //
#define QWERTZ_ASTR S(KC_RBRC)  //
#define QWERTZ_AMPR KC_CIRC  //
#define QWERTZ_UNDS S(KC_SLSH)  //
#define QWERTZ_MINS KC_SLSH  //
#define QWERTZ_SLSH KC_AMPR  //
#define QWERTZ_PIPE RALT(KC_NUBS)  //
#define QWERTZ_LSQR RALT(KC_8)  //
#define QWERTZ_RSQR RALT(KC_9)  //
#define QWERTZ_LBRC KC_ASTR  //
#define QWERTZ_RBRC KC_LPRN  //
#define QWERTZ_LCBR RALT(KC_7)  //
#define QWERTZ_RCBR RALT(KC_0)  //
#define QWERTZ_AE KC_QUOT  //
#define QWERTZ_OE KC_SCLN  //
#define QWERTZ_UE KC_LBRC  //
#define QWERTZ_LT KC_NUBS  //
#define QWERTZ_GT S(KC_NUBS)  //
#define QWERTZ_SZ KC_MINS  //

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
#define ALT_R MT(MOD_LALT, KC_R)
#define GUI_S MT(MOD_LGUI, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)
#define HYP_D MT(MOD_HYPR, KC_D)
#define MEH_C MT(MOD_MEH, KC_C)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SHT_N MT(MOD_RSFT, KC_N)
#define GUI_E MT(MOD_LGUI, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define CTL_O MT(MOD_LCTL, KC_O)
#define HYP_H MT(MOD_HYPR, KC_H)
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
const uint16_t PROGMEM at_combo[] = {KC_W, ALT_R, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_F, GUI_S, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_P, SHT_T, COMBO_END};
const uint16_t PROGMEM perc_combo[] = {KC_B, KC_G, COMBO_END};

// Between home and bottom row
const uint16_t PROGMEM tick_combo[] = {ALT_R, KC_X, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {GUI_S, MEH_C, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {SHT_T, HYP_D, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {KC_G, KC_V, COMBO_END};

// horizontal combos
const uint16_t PROGMEM copy_combo[] = {KC_X, MEH_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {MEH_C, HYP_D, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, HYP_D, COMBO_END};

// Right hand vertical combos
// Between top and home row
const uint16_t PROGMEM caret_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_L, SHT_N, COMBO_END};
const uint16_t PROGMEM star_combo[] = {KC_U, GUI_E, COMBO_END};
const uint16_t PROGMEM amp_combo[] = {QWERTZ_Y, ALT_I, COMBO_END};

// Between home and bottow row
const uint16_t PROGMEM unds_combo[] = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM mins_combo[] = {SHT_N, HYP_H, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {GUI_E, MEH_COM, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {ALT_I, KC_DOT, COMBO_END};

// Horizontal combos: brackets
const uint16_t PROGMEM lsqr_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM rsqr_combo[] = {KC_U, QWERTZ_Y, COMBO_END};
const uint16_t PROGMEM lpar_combo[] = {SHT_N, GUI_E, COMBO_END};
const uint16_t PROGMEM rpar_combo[] = {GUI_E, ALT_I, COMBO_END};
const uint16_t PROGMEM lcbr_combo[] = {HYP_H, MEH_COM, COMBO_END};
const uint16_t PROGMEM rcbr_combo[] = {MEH_COM, KC_DOT, COMBO_END};

// Vertical combos: Umlaute
const uint16_t PROGMEM ae_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {SHT_T, KC_G, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {HYP_D, KC_V, COMBO_END};
const uint16_t PROGMEM sz_combo[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM lt_combo[] = {KC_M, SHT_N, COMBO_END};
const uint16_t PROGMEM gt_combo[] = {ALT_I, CTL_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(at_combo, QWERTZ_AT),
  COMBO(hash_combo, QWERTZ_HASH),
  COMBO(dollar_combo, KC_DLR),
  COMBO(perc_combo, KC_PERC),
  COMBO(tick_combo, QWERTZ_TICK),
  COMBO(bsls_combo, QWERTZ_BSLS),
  COMBO(eql_combo, QWERTZ_EQL),
  COMBO(tilde_combo, QWERTZ_TILD),
  COMBO(copy_combo, LCTL(KC_C)),
  COMBO(paste_combo, LCTL(KC_V)),
  COMBO(cut_combo, LCTL(KC_X)),
  COMBO(caret_combo, QWERTZ_CIRC),
  COMBO(plus_combo, QWERTZ_PPLS),
  COMBO(star_combo, QWERTZ_ASTR),
  COMBO(amp_combo, QWERTZ_AMPR),
  COMBO(unds_combo, QWERTZ_UNDS),
  COMBO(mins_combo, QWERTZ_MINS),
  COMBO(slsh_combo, QWERTZ_SLSH),
  COMBO(pipe_combo, QWERTZ_PIPE),
  COMBO(lsqr_combo, QWERTZ_LSQR),
  COMBO(rsqr_combo, QWERTZ_RSQR),
  COMBO(lpar_combo, QWERTZ_LBRC),
  COMBO(rpar_combo, QWERTZ_RBRC),
  COMBO(lcbr_combo, QWERTZ_LCBR),
  COMBO(rcbr_combo, QWERTZ_RCBR),
  COMBO(ae_combo, QWERTZ_AE),
  COMBO(oe_combo, QWERTZ_OE),
  COMBO(ue_combo, QWERTZ_UE),
  COMBO(lt_combo, QWERTZ_LT),
  COMBO(gt_combo, QWERTZ_GT),
  COMBO(sz_combo, QWERTZ_SZ)
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y   o v e r r i d e s         │
// └─────────────────────────────────────────────────┘

// shift + ? = !
const key_override_t quexclam_override =
  ko_make_with_layers_negmods_and_options(
      MOD_MASK_SHIFT,       // Trigger modifiers: shift
      QWERTZ_QUES,             // Trigger key:
      QWERTZ_EXLM,             // Replacement key:
      ~0,                  // Activate on all layers
      MOD_MASK_CA,         // Do not activate when ctrl, alt or gui is pressed
      ko_option_no_reregister_trigger);

// Override quote key: no mod = ' | shift = "
const key_override_t quote_override =
  ko_make_with_layers_negmods_and_options(
      MOD_MASK_SHIFT,       // Trigger modifiers: shift
      QWERTZ_SINGLE_QUOTE,  // Trigger key:
      QWERTZ_DOUBLE_QUOTE,  // Replacement key:
      ~0,                  // Activate on all layers
      MOD_MASK_CA,         // Do not activate when ctrl, alt or gui is pressed
      ko_option_no_reregister_trigger);

// This globally defines all key overrides to be used ├───────────┐
const key_override_t *key_overrides[] = {
  &quexclam_override,
  &quote_override
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
             │    Q    │    W    │    F    │    P    │    B    ││    J    │    L    │    U    │    Y    │    '    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    A    │    R    │    S    │    T    │    G    ││    M    │    N    │    E    │    I    │    O    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │   ESC   │    Z    │    X    │    C    │    D    │    V    ││    K    │    H    │    ,;   │    .:   │   ?!    │  ALT_GR │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  UTIL   │  NAV    │  SHIFT  ││   ENT   │    NUM  │   FUN   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

   [_BASE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,      KC_J,     KC_L,     KC_U,     QWERTZ_Y, QWERTZ_SINGLE_QUOTE,
              CTL_A,    ALT_R,    GUI_S,    SHT_T,    KC_G,      KC_M,     SHT_N,    GUI_E,    ALT_I,    CTL_O,
    KC_TAB,   QWERTZ_Z, KC_X,     MEH_C,    HYP_D,    KC_V,      KC_K,     HYP_H,    MEH_COM,  KC_DOT,   QWERTZ_QUES,  KC_RALT,
                                  UTIL,     NAV,      OS_SHT,    KC_ENT,   NUM,      FUN
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
   │         │         │         │  MEH    │  HYPR   │         ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││   ENT   │  BSPC   │   DEL   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_NAV] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______, _______,    _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,
              KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT, _______,    _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,
    _______,  _______,  _______,  KC_MEH,   KC_HYPR, _______,    _______,  _______,  _______,  _______,  _______,   _______,
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
   │         │    -    │    1    │    2    │    3    │    /    ││         │   HYPR  │   MEH   │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │    .    │    ,    ││         │         │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_NUM] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_PPLS,    KC_7,    KC_8,     KC_9,    KC_PAST,   _______,  _______,  _______,  _______, _______,
              KC_0,       KC_4,    KC_5,     KC_6,    QWERTZ_EQL,_______,  KC_LSFT,  KC_LGUI,  KC_LALT, KC_LCTL,
    _______,  KC_PMNS,    KC_1,    KC_2,     KC_3,    KC_PSLS,   _______,  KC_HYPR,  KC_MEH,   _______, _______,  _______,
                                   _______,  KC_DOT,  KC_PDOT,   _______,  _______,  _______
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
              QK_BOOT,  _______,  _______,  _______,   _______,  RALT(KC_E),  KC_MPRV,  KC_VOLU,  KC_MNXT,   _______,
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



