#include "bootloader.h"
#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Default Layer in Dvorak (Layer 0)
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   +    |   1  |   2  |   3  |   4  |   5  |  Esc |           |  ESC |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   '  |   ,  |   .  |   Y  |   Y  |(Null)|           |(Null)|   F  |   G  |   C  |   R  |   L  |   /    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | CapsLk |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   \    |
     * |--------+------+------+------+------+------| FN1  |           | FN2  |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LGUI |   `  |  INS | Left | Rght |                                       |  Up  |  Dn  |   [  |   ]  | RGUI |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LCtr | LAlt |       | Ralt | RCtr |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | BkSp | Del  |------|       |------| Enter| Space|
     *                                 |      |      | End  |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *****************************************************************************************************
     * This Dvorak keyboard layout stems from my early Kinesis years, using the Contour PS/2 with a Dvorak
     * software layout. Because of this, the RBRC and LBRC were on opposite sides of the board in the cor-
     * ner keys. I've decided to continue using this layout with my ErgoDox.
     */

    KEYMAP(  // layer 0 : default
        // left hand
        EQL,    1,    2,   3,   4,   5,   ESC,
        TAB, QUOT, COMM, DOT,   P,   Y,    NO,
        CAPS,   A,    O,   E,   U,   I,
        LSFT, SCLN,   Q,   J,   K,   X,   FN1,
        LGUI,  GRV, INS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 BSPC,DEL, END,
        // right hand
             ESC,  6,   7,   8,   9,   0,  MINS,
             NO,   F,   G,   C,   R,   L,  SLSH,
                   D,   H,   T,   N,   S,  BSLS,
             FN2,  B,   M,   W,   V,   Z,  RSFT,
                        UP,DOWN,RBRC,LBRC,  RGUI,
        RALT,RCTL,
        PGUP,
        PGDN,ENT, SPC
    ),


    /* 
     * Keymap: Function and Media Keys Layer (Layer 1)
     * 
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | TEENSY |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |  Mute  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      | FN4  |           |  FN6 |      | PrSc | ScLk | Paus |      | Vol Up |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------| Stop | Prev | Play | Next | Sel  | Vol Dn |
     * |--------+------+------+------+------+------| FN4  |           |  FN7 |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     * 
     * 
     */

    KEYMAP(  // layer 1 : function and media keys
        // left hand
        FN0, F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, MUTE,
             FN6, TRNS,PSCR,SLCK,PAUS,TRNS,VOLU,
                  MSTP,MPRV,MPLY,MNXT,MSEL,VOLD,
             FN7, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),


    /* 
     * Keymap: Numpad Layer (Layer 2)
     * 
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Power  |      |      |      |      |      |      |           |      |      | NmLk | KP / | KP * | KP - |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Sleep  |      |      |      |      |      | FN5  |           |  FN4 |      | KP 7 | KP 8 | KP 9 | KP + |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Wake   |      |      |      |      |      |------|           |------|      | KP 4 | KP 5 | KP 6 | KP + |        |
     * |--------+------+------+------+------+------| FN7  |           |  FN4 |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      | KP 1 | KP 2 | KP 3 |KP Ent|        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       | KP 0 |      | KP . |KP Ent|      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     * 
     */

    KEYMAP(  // layer 2: numpad
        // left hand
        PWR, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        SLEP,TRNS,TRNS,TRNS,TRNS,TRNS, FN5,
        WAKE,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN7,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,NLCK,PSLS,PAST,PMNS,TRNS,
              FN4,NO,  P7,  P8,  P9,  PPLS,TRNS,
                  NO,  P4,  P5,  P6,  PPLS,TRNS,
              FN4,NO,  P1,  P2,  P3,  PENT,TRNS,
                       P0,  TRNS,PDOT,PENT,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),


    /* 
     * Keymap: QWERTY Gaming Layer (Layer 3)
     * 
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           | ESC  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  | Fn4  |           | Fn4  |   Y  |   U  |   I  |   O  |   P  |   [    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| Fn1  |           | Fn2  |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LGUI |   `  |  INS | Left | Rght |                                       |  Up  |  Dn  |   [  |   ]  | RGUI |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LCtr | LAlt |       | Ralt | RCtr |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Home |       | PgUp |      |      |
     *                                 | BkSp | Del  |------|       |------| Enter| Space|
     *                                 |      |      | End  |       | PgDn |      |      |
     *                                 `--------------------'       `--------------------'
     * 
     */

    KEYMAP(  // layer 3 : QWERTY Gaming
        // left hand
        EQL, 1,   2,   3,   4,   5,   ESC,
        TAB, Q,   W,   E,   R,   T,   FN4,
        CAPS,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   FN1,
        LGUI,GRV, INS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 BSPC,DEL, END,
        // right hand
             ESC, 6,   7,   8,   9,   0,   MINS,
             FN4, Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN2, N,   M,   COMM,DOT, SLSH,RSFT,
                       UP,DOWN,LBRC,RBRC,RGUI,
        RALT,RCTL,
        PGUP,
        PGDN,ENT, SPC
    ),

};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0 - Teensy key
    ACTION_LAYER_MOMENTARY(1),                      // FN1 - switch to Layer1
    ACTION_LAYER_MOMENTARY(2),                      // FN2 - switch to Layer2
    ACTION_LAYER_MOMENTARY(3),                      // FN3 - switch to Layer3
    ACTION_LAYER_SET_CLEAR(0),                      // FN4 - set Layer0
    ACTION_LAYER_SET(1, ON_PRESS),                  // FN5 - set Layer1
    ACTION_LAYER_SET(2, ON_PRESS),                  // FN6 - set Layer2
    ACTION_LAYER_SET(3, ON_PRESS),                  // FN7 - set Layer3
};

/*
 * Defining the Teensy Key action_function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }

}
