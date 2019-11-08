/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
* 
* ,--------------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |	F7	|  F8  |  F9  |  F10 |  F12 |  PSCR|FUNC1 | PAUS |FUNC2 |  PGM   |
* |--------+------+------+------+------+------+---------------------------------+------+------+------+------+------+---------|
* |  -_    |  1!  |  2@  |  3#  |  4$  |  5%  |                           		 |  6^  |  7&  |  8*  |  9(  |  0)  | =+     |
* |--------+------+------+------+------+------|                           		 +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           		 |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           		 |------+------+------+------+------+--------|
* |  DEL   |   A  |   S  |   D  |   F  |   G  |                           		 |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           		 |------+------+------+------+------+--------|
* | SHIFT  |   Z  |   X  |   C  |   V  |   B  |                           		 |   N  |   M  |  ,.  |  .>  |  /?  | FN2    |
* `--------+------+------+------+------+-------                           		 `------+------+------+------+------+--------'
*          |GUI   | `~   |MOUSE1|MOUSE2|                                         		|  [{  |  ]}  | ESC  | ENT  |
*          `---------------------------'                                         		`---------------------------'
*                                        ,-------------.         ,-------------.
*                                        |FUNC2 | Alt  |         | Alt  |FUNC2 |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Shift|         |Shift |      |      |
*                                 |BSpace|      |------|         |------|      | Space|
*                                 |      |FUNC1 | Ctrl |         | Ctrl | FUNC1|      |
*                                 `--------------------'         `--------------------'
*
* Keymap: Fn1 Layer
*
* ,-------------------------------------------------------------------------------------------------------------------.
* |   Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | TRNS | PAUS | NO   | PGM    |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | TRNS   |  !   |  @   |  #   |  $   |  %   |                           |  ^   |  &   |  *   |  (   |  )   | TRNS   |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | TRNS   | TRNS | TRNS | MS_U | TRNS | TRNS |                           | TRNS | HOME |   Up | END  | TRNS |   |    |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | TRNS   | TRNS | MS_L | MS_D | MS_R | MwU  |                           | TRNS | Left | Down | Right| TRNS |   "    |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | TRNS   | TRNS | TRNS | TRNS | TRNS | MwD  |                           | TRNS | TRNS | <    | >    | ?    | TRNS   |
* `--------+------+------+------+------+------'                           `------+------+------+------+------+--------'
*          |  INS | ~    | TRNS | TRNS |                                         | {    |  }   | TRNS | TRNS |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | NO   | TRNS |         | TRNS | NO   |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | TRNS |         | TRNS |      |      |
*                                 | TRNS | TRNS |------|         |------| TRNS | TRNS |
*                                 |      |      | TRNS |         | TRNS |      |      |
*                                 `--------------------'         `--------------------'
*
*/

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default */
	[0] = 
    KEYMAP(
           ESC,F1  ,F2  ,F3  ,F4  ,F5  ,F6   ,F7   ,F8,
           MINS, 1   ,2   ,3   ,4   ,5   ,
           TAB, Q   ,W   ,E   ,R   ,T   ,
           DEL, A   ,S   ,D   ,F   ,G   ,
           LSFT, Z  ,X   ,C   ,V   ,B   ,
                GRV ,LGUI,BTN1,BTN2,
                               FN11,LALT,
                                   LSFT,
                          BSPC ,FN1 ,LCTL,

           F9  ,F10 ,F11 ,FN10 ,PSCR,FN5,PAUS,FN9 ,FN0,
           6   ,7   ,8   ,9   ,0   ,EQL,
           Y   ,U   ,I   ,O   ,P   ,BSLS,
           H   ,J   ,K   ,L   ,SCLN,QUOT,
           N   ,M   ,COMM,DOT ,SLSH,FN2,
                LBRC,RBRC,FN12,ESC,
           RALT,FN9,
           RSFT,
           RCTL,FN1 ,SPC
    ),
	[1] = 
    /* Layer 1: Function layer */
    KEYMAP(
           TRNS, TRNS,TRNS,TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,
           FN17,FN12  ,FN13  ,FN14   ,FN15  ,FN16  ,
           F1  ,F2   ,F3   ,F4  ,F5  ,F6,
           F7   ,F8   ,F9  ,F10 ,F11, F12,
           LSFT,TRNS,TRNS,TRNS ,TRNS ,TRNS,
                TRNS ,TRNS,TRNS ,TRNS,
                          FN29 ,TRNS,
                               TRNS,
                     TRNS,TRNS ,TRNS ,
                     
           TRNS  ,TRNS ,TRNS ,TRNS  ,TRNS,FN6,TRNS,NO ,TRNS ,
           FN7  ,FN8  ,FN9  ,FN10   ,FN11 ,FN26,
           TRNS,HOME,UP  ,END  ,TRNS,FN18,
           PGUP,LEFT,DOWN,RIGHT,FN20,FN19,
           PGDN,TRNS,FN23,FN22 ,FN21,TRNS ,
                FN24,FN25,TRNS ,TRNS,
           TRNS,TRNS,
           TRNS,
           TRNS ,TRNS,ENT  
    ),
	    /* Layer 2: num pad */
	[2] =
    KEYMAP(
           TRNS,TRNS ,TRNS ,TRNS ,TRNS,TRNS,TRNS,TRNS ,TRNS ,
           TRNS,TRNS ,TRNS ,TRNS ,TRNS,TRNS ,
           TRNS,TRNS ,TRNS ,TRNS ,TRNS,TRNS ,
           TRNS,TRNS ,TRNS ,TRNS ,TRNS,TRNS ,
           TRNS,TRNS,TRNS,TRNS ,TRNS,TRNS ,
                TRNS,TRNS,TRNS ,TRNS,
           TRNS,TRNS,
           TRNS,
           TRNS ,TRNS,TRNS,
		   
           TRNS,TRNS   ,TRNS   ,TRNS   ,TRNS   ,NO  ,TRNS,FN0,TRNS,
           TRNS,TRNS   ,TRNS   ,TRNS   ,TRNS   ,TRNS,
           TRNS,P7     ,P8     ,P9     ,TRNS   ,TRNS,
           TRNS,P4     ,P5     ,P6     ,TRNS   ,TRNS,
           NLCK,P1     ,P2     ,P3     ,TRNS   ,PENT,
                TRNS   ,TRNS   ,TRNS   ,TRNS   ,
                        TRNS   ,FN0   ,
                        TRNS   ,
                        TRNS   ,PDOT    ,P0
    ),
	    /* guest layer */
	[3] =
    KEYMAP(
          TRNS  ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS,TRNS,TRNS ,TRNS ,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS  ,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS  ,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS  ,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS  ,
                TRNS,TRNS,LEFT ,RGHT,
                          LCTL ,LALT,
                                HOME,
                    BSPC ,DEL  ,END ,
		   
           TRNS ,TRNS ,TRNS ,FN0  ,TRNS,NO    ,TRNS,FN0,TRNS,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS  ,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS  ,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,TRNS  ,
           TRNS ,TRNS ,TRNS ,TRNS  ,TRNS,RSFT  ,
                TRNS  ,TRNS    ,TRNS    ,TRNS   ,
                                RALT,RCTL,
                                PGUP,
                                PGDN,ENT ,SPC
    ) 
	};
enum function_id {
    BOOTLOAD_KEY,

};

enum macro_id {
	CTRL_TAB,
	SFT_1,
	SFT_2,
	SFT_3,
	SFT_4,
	SFT_5,
	SFT_6,
	SFT_7,
	SFT_8,
	SFT_9,
	SFT_0,
	SFT_MINS,
	SFT_BSLS,
	SFT_QUOT,
	SFT_SCLN,
	SFT_SLSH,
	SFT_DOT,
	SFT_COMM,
	SFT_LBRC,
	SFT_RBRC,
	SFT_EQL,
	SFT_GRV,
	ALT_TAB,
	CTRL_ALT_DEL,
    WIN_L
};

static const uint16_t PROGMEM fn_actions[] = {
		[0] = ACTION_FUNCTION(BOOTLOAD_KEY),
		[1] = ACTION_LAYER_MOMENTARY(1),
		[2] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
		[5] = ACTION_LAYER_TOGGLE(1),
		[6] = ACTION_MACRO(CTRL_ALT_DEL),
		[7] = ACTION_MACRO(SFT_EQL),		
		[8] = ACTION_MACRO(SFT_8),   		
		[9] = ACTION_LAYER_TOGGLE(2),
        [10] = ACTION_LAYER_TOGGLE(3),
        [11] = ACTION_MACRO(ALT_TAB),
        [12] = ACTION_MACRO(WIN_L),
};

static const uint16_t PROGMEM fn_actions_1[] = {
//2 slots here
		[6] = ACTION_LAYER_TOGGLE(1),
		[7] = ACTION_MACRO(SFT_6),                     
		[8] = ACTION_MACRO(SFT_7),                     
		[9] = ACTION_MACRO(SFT_8),                     
		[10] = ACTION_MACRO(SFT_9),                     
		[11] = ACTION_MACRO(SFT_0),                     
		[12] = ACTION_MACRO(SFT_1),                     
		[13] = ACTION_MACRO(SFT_2),                     
		[14] = ACTION_MACRO(SFT_3),                     
		[15] = ACTION_MACRO(SFT_4),                     
		[16] = ACTION_MACRO(SFT_5),  
		[17] = ACTION_MACRO(SFT_MINS),                     
		[18] = ACTION_MACRO(SFT_BSLS),                     
		[19] = ACTION_MACRO(SFT_QUOT),                     
		[20] = ACTION_MACRO(SFT_SCLN),                     
		[21] = ACTION_MACRO(SFT_SLSH),                     
		[22] = ACTION_MACRO(SFT_DOT),                     
		[23] = ACTION_MACRO(SFT_COMM),                     
		[24] = ACTION_MACRO(SFT_LBRC),                     
		[25] = ACTION_MACRO(SFT_RBRC),                     
		[26] = ACTION_MACRO(SFT_EQL),
		[27] = ACTION_MACRO(SFT_GRV),
		[29] = ACTION_MACRO(CTRL_TAB),
};

static const uint16_t PROGMEM fn_actions_2[] = {
	//2 slots here
	[0] = ACTION_LAYER_TOGGLE(2),
};

static const uint16_t PROGMEM fn_actions_3[] = {
	//2 slots here
	[0] = ACTION_LAYER_TOGGLE(3),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (id == BOOTLOAD_KEY) {
        clear_keyboard();
        _delay_ms(250);
        bootloader_jump();
    }	
}


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {			
       case SFT_1:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(1), END ) :
                    MACRO( U(RSFT), U(1), END ));	
        case SFT_2:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(2), END ) :
                    MACRO( U(RSFT), U(2), END ));	
        case SFT_3:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(3), END ) :
                    MACRO( U(RSFT), U(3), END ));
        case SFT_4:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(4), END ) :
                    MACRO( U(RSFT), U(4), END ));
        case SFT_5:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(5), END ) :
                    MACRO( U(RSFT), U(5), END ));					
        case SFT_6:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(6), END ) :
                    MACRO( U(RSFT), U(6), END ));	
        case SFT_7:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(7), END ) :
                    MACRO( U(RSFT), U(7), END ));	
        case SFT_8:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(8), END ) :
                    MACRO( U(RSFT), U(8), END ));
        case SFT_9:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(9), END ) :
                    MACRO( U(RSFT), U(9), END ));
        case SFT_0:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(0), END ) :
                    MACRO( U(RSFT), U(0), END ));
       case SFT_MINS:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(MINS), END ) :
                    MACRO( U(RSFT), U(MINS), END ));	
        case SFT_BSLS:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(BSLS), END ) :
                    MACRO( U(RSFT), U(BSLS), END ));	
        case SFT_QUOT:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(QUOT), END ) :
                    MACRO( U(RSFT), U(QUOT), END ));
        case SFT_SCLN:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(SCLN), END ) :
                    MACRO( U(RSFT), U(SCLN), END ));
        case SFT_SLSH:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(SLSH), END ) :
                    MACRO( U(RSFT), U(SLSH), END ));					
        case SFT_DOT:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(DOT), END ) :
                    MACRO( U(RSFT), U(DOT), END ));	
        case SFT_COMM:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(COMM), END ) :
                    MACRO( U(RSFT), U(COMM), END ));	
        case SFT_LBRC:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(LBRC), END ) :
                    MACRO( U(RSFT), U(LBRC), END ));
        case SFT_RBRC:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(RBRC), END ) :
                    MACRO( U(RSFT), U(RBRC), END ));
        case SFT_EQL:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(EQL), END ) :
                    MACRO( U(RSFT), U(EQL), END ));
        case SFT_GRV:
            return (record->event.pressed ?
                    MACRO( D(RSFT), D(GRV), END ) :
                    MACRO( U(RSFT), U(GRV), END ));														
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(LALT), U(TAB), END ));													
		case CTRL_ALT_DEL:
			return (record->event.pressed ?
				MACRO(D(LCTRL), D(LALT), D(DEL), END) :
				MACRO(U(LCTRL), U(LALT), U(DEL), END));
        case CTRL_TAB:
            return (record->event.pressed ?
                    MACRO( D(LCTRL), D(TAB), END ) :
                    MACRO( U(LCTRL), U(TAB), END ));	
        case WIN_L:
            return (record->event.pressed ?
                    MACRO( D(LGUI), D(L), END ) :
                    MACRO( U(LGUI), U(L), END ));                

    }
    return MACRO_NONE;
}