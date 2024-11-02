#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
};

void matrix_scan_user(void) {
  achordion_task();
}

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_2,
  DANCE_12,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    TO(4),          KC_F,           KC_P,           KC_D,           KC_L,           KC_X,                                           KC_SCLN,        KC_U,           KC_O,           KC_Y,           KC_B,           KC_TRANSPARENT, 
    KC_Z,           KC_S,           MT(MOD_LALT, KC_N),MT(MOD_LGUI, KC_T),KC_H,           KC_K,                                           KC_COMMA,       KC_A,           MT(MOD_RGUI, KC_E),MT(MOD_RALT, KC_I),KC_C,           KC_Q,           
    KC_TRANSPARENT, MT(MOD_LCTL, KC_V),MT(MOD_LALT | MOD_LCTL | MOD_LGUI, KC_W),ALL_T(KC_G),    KC_M,           KC_J,                                           KC_MINUS,       KC_DOT,         ALL_T(KC_QUOTE),MT(MOD_RALT | MOD_RCTL | MOD_RGUI, KC_EQUAL),MT(MOD_RCTL, KC_SLASH),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_0),    LT(2,KC_R),                                     LT(4,KC_SPACE), OSL(3),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    MT(MOD_LSFT, KC_TAB),TD(DANCE_1),                                    TD(DANCE_2),    MT(MOD_RSFT, KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    TO(0),          KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_NO,          
    KC_TAB,         KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                           KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_BSPC,        
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,          
    KC_NO,          KC_NO,          KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_ALT,    KC_SPACE,                                       KC_RIGHT_SHIFT, KC_RIGHT_ALT,   KC_NO,          KC_RIGHT_CTRL,  KC_NO,          KC_NO,          
                                                    LT(2,KC_TAB),   KC_ESCAPE,                                      KC_NO,          KC_ENTER
  ),
  [2] = LAYOUT_voyager(
    LGUI(LCTL(KC_SPACE)),TD(DANCE_3),    KC_AMPR,        KC_HASH,        KC_DLR,         KC_PERC,                                        KC_EQUAL,       KC_7,           KC_8,           KC_9,           KC_COMMA,       QK_LLCK,        
    CW_TOGG,        TD(DANCE_4),    TD(DANCE_5),    TD(DANCE_6),    TD(DANCE_7),    KC_GRAVE,                                       KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_ASTR,        KC_DOT,         
    KC_TRANSPARENT, KC_BSLS,        RALT(KC_BSLS),  RALT(RSFT(KC_BSLS)),LALT(LSFT(KC_2)),KC_TILD,                                        KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_8),    KC_TRANSPARENT,                                 KC_0,           KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TD(DANCE_9),    TD(DANCE_10)
  ),
  [3] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          ST_MACRO_2,     ST_MACRO_3,     KC_NO,                                          KC_NO,          ST_MACRO_8,     ST_MACRO_9,     KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     KC_NO,                                          KC_NO,          ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    LALT(KC_C),     KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          ST_MACRO_13,    ST_MACRO_14,    ST_MACRO_15,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
  [4] = LAYOUT_voyager(
    TO(0),          LGUI(KC_Q),     LALT(LGUI(KC_W)),LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_NO,                                          LGUI(LCTL(KC_0)),RGUI(KC_1),     RGUI(KC_2),     RGUI(KC_3),     RGUI(KC_4),     KC_NO,          
    KC_NO,          KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       LGUI(KC_GRAVE),                                 LGUI(LCTL(KC_9)),KC_RIGHT_SHIFT, KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_RIGHT_CTRL,  KC_NO,          
    KC_NO,          LSFT(KC_LEFT),  LSFT(KC_UP),    LSFT(KC_DOWN),  RSFT(KC_RIGHT), KC_NO,                                          QK_LLCK,        LALT(LGUI(KC_1)),LALT(LGUI(KC_2)),LALT(LGUI(KC_3)),KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          LGUI(KC_BSPC),  LALT(KC_BSPC),                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    LGUI(KC_LBRC),  LGUI(KC_RBRC),                                  KC_NO,          KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    TO(1),          KC_NO,          RGB_VAD,        RGB_SLD,        RGB_VAI,        RGB_MODE_FORWARD,                                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    QK_DYNAMIC_TAPPING_TERM_UP,LALT(LSFT(KC_F12)),KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,MT(MOD_LSFT, KC_MEDIA_NEXT_TRACK),RGB_HUI,                                        KC_NO,          LCTL(KC_F1),    LCTL(KC_F2),    KC_F5,          KC_NO,          KC_NO,          
    QK_DYNAMIC_TAPPING_TERM_DOWN,LALT(LSFT(KC_F11)),KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,RGB_HUD,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    QK_DYNAMIC_TAPPING_TERM_PRINT,KC_NO,          KC_NO,          KC_NO,          KC_NO,          LALT(KC_AUDIO_VOL_UP),                                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO
  ),
  [6] = LAYOUT_voyager(
    KC_NO,          KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,                                          KC_NO,          KC_NO,          KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,                                          QK_LLCK,        KC_NO,          KC_HYPR,        RALT(RCTL(KC_RIGHT_GUI)),KC_RIGHT_CTRL,  KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_BSPC,                                        KC_MS_BTN1,     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_LEFT_SHIFT,  TO(0),                                          KC_MS_BTN3,     KC_MS_BTN2
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(LSFT(KC_A))),LALT(LCTL(LSFT(KC_D))),LALT(LCTL(LSFT(KC_L))),KC_TRANSPARENT,                                 KC_TRANSPARENT, LALT(LCTL(LSFT(KC_U))),LALT(LCTL(LSFT(KC_O))),KC_TRANSPARENT, LALT(LCTL(LSFT(KC_P))),KC_TRANSPARENT, 
    KC_TRANSPARENT, LALT(LCTL(LSFT(KC_S))),KC_TRANSPARENT, LALT(LCTL(LSFT(KC_T))),KC_TRANSPARENT, LALT(LCTL(LSFT(KC_K))),                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(LSFT(KC_I))),LALT(LGUI(LCTL(LSFT(KC_C)))),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(LSFT(KC_M))),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_F6),    LALT(LGUI(LCTL(LSFT(KC_K)))),LALT(KC_LBRC),                                  LALT(LGUI(LCTL(LSFT(KC_9)))),KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       TD(DANCE_11),                                   LALT(LGUI(LCTL(LSFT(KC_8)))),MT(MOD_RSFT, KC_4),MT(MOD_RGUI, KC_5),MT(MOD_RALT, KC_6),KC_RIGHT_CTRL,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_UP),    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,LALT(KC_RBRC),                                  LALT(LGUI(LCTL(LSFT(KC_7)))),KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_12),                                   TD(DANCE_14),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    TD(DANCE_13),   KC_TRANSPARENT,                                 TD(DANCE_15),   TD(DANCE_16)
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LSFT(KC_4)),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LALT(LGUI(KC_Z)),LALT(LGUI(KC_C)),LALT(LCTL(KC_SPACE)),KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_L, KC_P, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_COMMA, KC_A, COMBO_END};
const uint16_t PROGMEM combo2[] = { LT(2,KC_R), LT(4,KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_MINUS, LT(4,KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo4[] = { LT(2,KC_R), MT(MOD_LSFT, KC_TAB), COMBO_END};
const uint16_t PROGMEM combo5[] = { TD(DANCE_0), LT(2,KC_R), COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_S, KC_H, COMBO_END};
const uint16_t PROGMEM combo7[] = { MT(MOD_LCTL, KC_V), MT(MOD_LALT | MOD_LCTL | MOD_LGUI, KC_W), COMBO_END};
const uint16_t PROGMEM combo8[] = { MT(MOD_LALT | MOD_LCTL | MOD_LGUI, KC_W), ALL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combo9[] = { ALL_T(KC_G), KC_M, COMBO_END};
const uint16_t PROGMEM combo10[] = { MT(MOD_LGUI, KC_T), MT(MOD_RGUI, KC_E), COMBO_END};
const uint16_t PROGMEM combo11[] = { MT(MOD_LSFT, KC_TAB), MT(MOD_RSFT, KC_ENTER), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, ST_MACRO_0),
    COMBO(combo1, ST_MACRO_1),
    COMBO(combo2, LGUI(LSFT(KC_SPACE))),
    COMBO(combo3, LGUI(LSFT(KC_J))),
    COMBO(combo4, KC_ENTER),
    COMBO(combo5, KC_SPACE),
    COMBO(combo6, OSL(10)),
    COMBO(combo7, LGUI(KC_Z)),
    COMBO(combo8, LGUI(KC_C)),
    COMBO(combo9, LGUI(KC_V)),
    COMBO(combo10, OSM(MOD_RSFT)),
    COMBO(combo11, OSL(7)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F:
            return g_tapping_term + 10;
        case MT(MOD_LALT, KC_N):
            return g_tapping_term + 5;
        case MT(MOD_LGUI, KC_T):
            return g_tapping_term + 5;
        case KC_H:
            return g_tapping_term + 10;
        case MT(MOD_LCTL, KC_V):
            return g_tapping_term + 5;
        case MT(MOD_LALT | MOD_LCTL | MOD_LGUI, KC_W):
            return g_tapping_term + 5;
        case ALL_T(KC_G):
            return g_tapping_term + 5;
        case LT(2,KC_R):
            return g_tapping_term -5;
        case MT(MOD_LSFT, KC_TAB):
            return g_tapping_term -5;
        case TD(DANCE_1):
            return g_tapping_term + 150;
        case KC_A:
            return g_tapping_term + 10;
        case MT(MOD_RGUI, KC_E):
            return g_tapping_term + 5;
        case MT(MOD_RALT, KC_I):
            return g_tapping_term + 5;
        case ALL_T(KC_QUOTE):
            return g_tapping_term + 5;
        case MT(MOD_RALT | MOD_RCTL | MOD_RGUI, KC_EQUAL):
            return g_tapping_term + 5;
        case MT(MOD_RCTL, KC_SLASH):
            return g_tapping_term + 5;
        case LT(4,KC_SPACE):
            return g_tapping_term + 10;
        case MT(MOD_RSFT, KC_ENTER):
            return g_tapping_term -5;
        case LT(2,KC_TAB):
            return g_tapping_term -5;
        case TD(DANCE_3):
            return g_tapping_term + 20;
        case TD(DANCE_4):
            return g_tapping_term + 20;
        case TD(DANCE_5):
            return g_tapping_term + 20;
        case TD(DANCE_7):
            return g_tapping_term + 20;
        case KC_BSLS:
            return g_tapping_term + 20;
        case RALT(KC_BSLS):
            return g_tapping_term + 20;
        case RALT(RSFT(KC_BSLS)):
            return g_tapping_term + 20;
        case KC_EQUAL:
            return g_tapping_term + 20;
        case KC_COMMA:
            return g_tapping_term + 5;
        case KC_PLUS:
            return g_tapping_term + 20;
        case KC_4:
            return g_tapping_term + 20;
        case KC_5:
            return g_tapping_term + 20;
        case KC_6:
            return g_tapping_term + 20;
        case KC_ASTR:
            return g_tapping_term + 20;
        case KC_DOT:
            return g_tapping_term + 20;
        case KC_MINUS:
            return g_tapping_term + 20;
        case KC_3:
            return g_tapping_term + 20;
        case KC_SLASH:
            return g_tapping_term + 20;
        case KC_0:
            return g_tapping_term -20;
        case TD(DANCE_9):
            return g_tapping_term + 20;
        case TD(DANCE_10):
            return g_tapping_term + 20;
        case LALT(KC_C):
            return g_tapping_term + 5;
        case LCTL(LSFT(KC_TAB)):
            return g_tapping_term + 20;
        case LALT(KC_BSPC):
            return g_tapping_term + 20;
        case LGUI(KC_LBRC):
            return g_tapping_term + 20;
        case LGUI(KC_RBRC):
            return g_tapping_term + 20;
        case KC_RIGHT_SHIFT:
            return g_tapping_term + 20;
        case KC_RIGHT_GUI:
            return g_tapping_term + 20;
        case KC_RIGHT_ALT:
            return g_tapping_term + 20;
        case KC_RIGHT_CTRL:
            return g_tapping_term + 20;
        case KC_MEDIA_PREV_TRACK:
            return g_tapping_term + 20;
        case KC_AUDIO_VOL_DOWN:
            return g_tapping_term + 20;
        case TD(DANCE_12):
            return g_tapping_term -20;
        case TD(DANCE_13):
            return g_tapping_term + 20;
        case MT(MOD_RSFT, KC_4):
            return g_tapping_term + 20;
        case MT(MOD_RGUI, KC_5):
            return g_tapping_term + 20;
        case MT(MOD_RALT, KC_6):
            return g_tapping_term + 20;
        case TD(DANCE_14):
            return g_tapping_term -20;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154}, {0,0,154} },

    [1] = { {2,238,228}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255} },

    [2] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {2,238,228}, {0,0,255}, {0,0,0}, {0,0,0}, {41,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {41,255,255}, {2,238,228}, {41,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {41,255,255}, {0,0,0}, {74,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,255}, {2,238,228}, {2,238,228}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {201,205,181}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {201,205,181}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {2,238,228}, {201,205,181}, {201,205,181}, {201,205,181}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {74,255,255}, {0,0,0}, {44,255,255}, {44,255,255}, {44,255,255}, {44,255,255}, {0,0,255}, {2,238,228}, {2,238,228}, {2,238,228}, {2,238,228}, {44,255,255}, {0,0,255}, {2,238,228}, {2,238,228}, {2,238,228}, {2,238,228}, {44,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {2,238,228}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {44,255,255}, {0,0,0} },

    [6] = { {0,0,0}, {239,142,223}, {239,142,223}, {124,218,204}, {239,142,223}, {0,0,0}, {0,0,0}, {239,142,223}, {124,218,204}, {124,218,204}, {124,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {187,177,246}, {187,177,246}, {187,177,246}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {2,238,228}, {0,0,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {2,238,228}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,0}, {148,162,247}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {148,162,247}, {148,162,247} },

    [7] = { {0,0,0}, {0,0,0}, {152,175,233}, {147,151,249}, {29,169,227}, {0,0,0}, {0,0,0}, {0,0,147}, {0,0,0}, {181,30,76}, {0,0,0}, {172,3,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {2,238,228}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {28,189,236}, {186,127,244}, {0,0,0}, {156,199,244}, {0,0,0}, {0,0,0}, {0,0,0}, {82,135,218}, {149,149,249}, {255,162,236}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {129,3,163}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {129,3,163}, {0,0,0}, {0,0,0}, {152,255,255}, {255,184,230}, {255,184,230}, {129,3,163}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {255,184,230}, {0,0,0}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255} },

    [10] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {216,180,252}, {0,0,0}, {0,0,0}, {216,180,252}, {216,180,252}, {216,180,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 10:
      set_layer_color(10);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q) SS_DELAY(100) SS_TAP(X_U));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_U));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_U));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_N)) SS_DELAY(100) SS_TAP(X_N));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_I));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_A));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_U));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_A));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_A));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_I));
    }
    break;

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_3):
    case TD(DANCE_4):
    case TD(DANCE_5):
    case TD(DANCE_6):
    case TD(DANCE_7):
    case TD(DANCE_8):
    case TD(DANCE_9):
    case TD(DANCE_10):
    case TD(DANCE_11):
    case TD(DANCE_13):
    case TD(DANCE_14):
    case TD(DANCE_15):
    case TD(DANCE_16):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: layer_move(6); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_HOLD:
          if(!is_layer_locked(5)) {
            layer_off(5);
          }
        break;
    }
    dance_state[0].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, LALT(KC_BSPC)),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_ESCAPE, LCTL(LGUI(KC_Q))),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_EXLM, LALT(KC_1)),
        [DANCE_4] = ACTION_TAP_DANCE_TAP_HOLD(KC_AT, LALT(KC_9)),
        [DANCE_5] = ACTION_TAP_DANCE_TAP_HOLD(KC_LPRN, KC_LBRC),
        [DANCE_6] = ACTION_TAP_DANCE_TAP_HOLD(KC_RPRN, KC_RBRC),
        [DANCE_7] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUES, LALT(LSFT(KC_SLASH))),
        [DANCE_8] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, LALT(KC_BSPC)),
        [DANCE_9] = ACTION_TAP_DANCE_TAP_HOLD(LALT(KC_GRAVE), LALT(KC_U)),
        [DANCE_10] = ACTION_TAP_DANCE_TAP_HOLD(RALT(KC_E), LALT(KC_I)),
        [DANCE_11] = ACTION_TAP_DANCE_TAP_HOLD(LALT(LCTL(KC_UP)), LALT(LCTL(LGUI(KC_UP)))),
        [DANCE_13] = ACTION_TAP_DANCE_TAP_HOLD(KC_SPACE, RSFT(KC_SPACE)),
        [DANCE_14] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_SPACE),
        [DANCE_15] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINUS, RGUI(RSFT(KC_COMMA))),
        [DANCE_16] = ACTION_TAP_DANCE_TAP_HOLD(KC_PLUS, RGUI(RSFT(KC_DOT))),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_2_finished, dance_2_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
};
