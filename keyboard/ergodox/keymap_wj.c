#include <util/delay.h>
#include "action_layer.h"
#include "action_util.h"
#include "bootloader.h"
#include "keymap_common.h"

/****************************************************************************************************
*
* Keymap: Default Layer in Dvorak
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |   =+   |  1!  |  2@  |  3#  |  4$  |  5%  |      |           |      |  6^  |  7&  |  8*  |  9(  |  0)  |   -_   |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |   Tab  |  '"  |  ,<  |  .>  |   P  |   Y  |      |           |      |   J  |   F  |   U  |   P  |   $  |   /?   |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |   Esc  |   A  |   O  |   E  |   U  |   I  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   \|   |
* |--------+------+------+------+------+------|  Fn  |           |  Fn  |------+------+------+------+------+--------|
* |  Shift |  ;:  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |  Shift |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |  Fn  | Shift| Ctrl | Alt  | Gui  |                                       | Gui  | Alt  | Ctrl | Shift|  Fn  |
*   |      |  -_  |  =+  | Left | Right|                                       | Up   | Left |  [{  |  ]}  |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        | /?   | \|   |       | §±   | `~   |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 | BkSp | Del  |------|       |------|Return| Space|
*                                 |      |      | Esc  |       | Tab  |      |      |
*                                 `--------------------'       `--------------------'
*
* Keymap: Fn/Keypad Layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |  F11 |  F12 |  F13 |  F14 | Vol+ |      |           |      | Next |   7  |   8  |   9  |   -  |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |  Caps  | PgUp | Home | Up   | End  | Mute |------|           |------| Play |   4  |   5  |   6  |   +  |        |
* |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
* |  Shift | PgDn | Left | Down | Right| Vol- |      |           |      | Prev |   1  |   2  |   3  |   =  | Shift  |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   | TRNS | Shift| Ctrl | Home | End  |                                       | PgUp | PgDn |   .  |   /  | TRNS   |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |Teensy|       |      |   =  |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 |      | Ins  |------|       |------| KEnt |  K0  |
*                                 |      |      | Caps |       | NL/Cl|      |      |
*                                 `--------------------'       `--------------------'
*
*/

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default */
    KEYMAP(
           EQL  ,1   ,2   ,3   ,4   ,5   ,NO  ,
           TAB  ,QUOT,COMM,DOT ,P   ,Y   ,NO  ,
           ESC  ,A   ,O   ,E   ,U   ,I   ,     
           LSFT ,SCLN,Q   ,J   ,K   ,X   ,FN5 ,
           FN5  ,FN1 ,FN2 ,FN3 ,FN4 ,          
                                    SLSH,BSLS,
                                         NO  ,
                               BSPC,DEL ,ESC,
           NO  ,6   ,7   ,8   ,9   ,0   ,MINS,
           NO  ,F   ,G   ,C   ,R   ,L   ,SLSH,
                D   ,H   ,T   ,N   ,S   ,BSLS,
           FN6 ,B   ,M   ,W   ,V   ,Z   ,RSFT,
                     FN7 ,FN8 ,FN9 ,FN10,FN6 ,
           NUBS,GRV ,
           NO  ,
           TAB ,ENT ,SPC 
    ),
    /* Layer 1: Keypad */
    KEYMAP(
           NO  ,F1  ,F2  ,F3  ,F4  ,F5  ,NO  ,
           NO  ,F11 ,F12 ,F13 ,F14 ,VOLU,NO  ,
           NO  ,PGUP,HOME,UP  ,END ,MUTE,     
           LSFT,PGDN,LEFT,DOWN,RGHT,VOLD,TRNS,
           TRNS,LSFT,LCTL,HOME,END ,          
                                    NO  ,FN0 ,
                                         NO  ,
                               NO  ,INS ,CAPS,
           NO  ,F6  ,F7  ,F8  ,F9  ,F10 ,NO  ,
           NO  ,MNXT,P7  ,P8  ,P9  ,PMNS,NO  ,
                MPLY,P4  ,P5  ,P6  ,PPLS,NO  ,
           TRNS,MPRV,P1  ,P2  ,P3  ,PAST,RSFT,
                     PGUP,PGDN,PDOT,PSLS,TRNS,
           NO  ,PEQL,
           NO  ,
           NLCK,PENT,P0
    ),};
enum function_id {
    TEENSY_KEY,
};
const action_t PROGMEM fn_actions[] = {
	[0] = ACTION_FUNCTION(TEENSY_KEY),
	[1] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_MINS),
	[2] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_EQL),
	[3] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_LEFT),
	[4] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_RGHT),
	[5] = ACTION_LAYER_TAP_TOGGLE(1),
	[6] = ACTION_LAYER_TAP_TOGGLE(1),
	[7] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_UP),
	[8] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_DOWN),
	[9] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_LBRC),
	[10] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_RBRC)
};
void action_function(keyrecord_t *event, uint8_t id, uint8_t opt) {
    if (id == TEENSY_KEY) {
        clear_keyboard();
        _delay_ms(250);
        bootloader_jump();
    }
}
