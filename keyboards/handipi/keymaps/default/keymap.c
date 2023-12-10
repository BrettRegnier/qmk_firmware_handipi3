// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include <string.h>

#define LAYER_TOGGLE_CHORD KC_ENT
#define CONTROL_CHORD KC_SPC
#define ALT_CHORD KC_ESC
#define AM_TOGGLE KC_TAB

// void CheckForBootloader(void);
// void LayerUp(int* next_layer, const int num_layers);
// void LayerDown(int* next_layer, const int num_layers);


// Global variables
bool mouse=false;
bool autoshift_on=true;


enum
{
    TD_MOUSE_CLICK = 0,
    TD_ALT_F1,
    TD_ALT_F2,
    TD_ALT_F3,
    TD_ALT_F4,
    TD_ALT_F5,
    TD_ALT_F6,
    TD_ALT_F7,
    TD_ALT_F8,
    TD_ALT_F9
};

enum 
{
    LAYER_SHIFT = SAFE_RANGE, 
    NOM_F1,
    NOM_F2,
    NOM_F3,
    NOM_F4,
    NOM_F5,
    NOM_F6,
    NOM_F7,
    NOM_F8,
    NOM_F9,
    ALT_F1,
    ALT_F2,
    ALT_F3,
    ALT_F4,
    ALT_F5,
    ALT_F6,
    ALT_F7,
    ALT_F8,
    ALT_F9,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions [] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_MOUSE_CLICK] = ACTION_TAP_DANCE_DOUBLE(KC_BTN1, KC_BTN2),
    //[TD_ALT_F1] = ACTION_TAP_DANCE_DOUBLE(KC_F1, SS_LALT(KC_F1)),
    //[TD_ALT_F2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, SS_LALT(KC_F2)),
    [TD_ALT_F1] = ACTION_TAP_DANCE_DOUBLE(NOM_F1, ALT_F1),
    [TD_ALT_F2] = ACTION_TAP_DANCE_DOUBLE(NOM_F2, ALT_F2),
    [TD_ALT_F3] = ACTION_TAP_DANCE_DOUBLE(NOM_F3, ALT_F3),
    [TD_ALT_F4] = ACTION_TAP_DANCE_DOUBLE(NOM_F4, ALT_F4),
    [TD_ALT_F5] = ACTION_TAP_DANCE_DOUBLE(NOM_F5, ALT_F5),
    [TD_ALT_F6] = ACTION_TAP_DANCE_DOUBLE(NOM_F6, ALT_F6),
    [TD_ALT_F7] = ACTION_TAP_DANCE_DOUBLE(NOM_F7, ALT_F7),
    [TD_ALT_F8] = ACTION_TAP_DANCE_DOUBLE(NOM_F8, ALT_F8),
    [TD_ALT_F9] = ACTION_TAP_DANCE_DOUBLE(NOM_F9, ALT_F9),
};

const uint16_t PROGMEM keymaps [][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ' │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ ? │
     * └───┴───├───┼───┼───┤   ├───├───┼───┼───┴───┘
     *         │ ; │spc│tab│   │ent│bsp│del│
     *         └───┴───┴───┘   └───┴───┴───┘
     *                     ┌───┐
     *                     │UPA│
     *                 ┌───┼───┼───┐
     *                 │LFA│TOG│RTA│
     *                 └───├───┼───┘
     *                     │DNA│
     *                     └───┘
     */

    [0] = {
        {KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,     KC_O,   KC_P},
        {KC_A,   KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,     KC_K,     KC_L,   KC_QUOTE},
        {KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT, KC_SLASH},
        {KC_NO,  KC_NO,  KC_SCLN, KC_SPC,  KC_TAB,  KC_ENT,  KC_BSPC,  KC_DEL,   KC_NO,  KC_NO},
        {KC_NO,  KC_NO,  KC_DOWN, KC_LEFT, KC_UP,   LAYER_SHIFT, KC_RIGHT, KC_NO,    KC_NO,  KC_NO},
    },

    /*
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ [ │ ] │NOP│NOP│NOP│   │ = │ - │NOP│NOP│ ` │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │TF1│TF2│TF3│TF4│TF5│   │TF6│TF7│TF8│TF9│ \ │
     * └───┴───├───┼───┼───┤   ├───├───┼───┼───┴───┘
     *         │esc│spc│tab│   │ent│ctl│alt│
     *         └───┴───┴───┘   └───┴───┴───┘
     *                     ┌───┐
     *                     │UPA│
     *                 ┌───┼───┼───┐
     *                 │LFA│TOG│RTA│
     *                 └───├───┼───┘
     *                     │DNA│
     *                     └───┘
     */

    [1] = {
        {KC_1,   KC_2,   KC_3,    KC_4,    KC_5,   KC_6,    KC_7,     KC_8,    KC_9,   KC_0},
        {KC_LEFT_BRACKET,   KC_RIGHT_BRACKET,   KC_NO,    KC_NO,    KC_NO,   KC_EQUAL,    KC_MINUS,     KC_NO,    KC_NO,   KC_GRAVE},
        {KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,   KC_F6,    KC_F7,     KC_F8, KC_F9, KC_BACKSLASH},
        {KC_NO,  KC_NO,  KC_ESC,  KC_SPC,  KC_TAB, KC_ENT,  KC_BSPC,  KC_LALT,  KC_NO,  KC_NO},
        {KC_NO,  KC_NO,  KC_DOWN, KC_LEFT, KC_UP,  LAYER_SHIFT, KC_RIGHT, KC_NO,   KC_NO,  KC_NO},
    },

    /*
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ ' │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │   │ N │ M │ , │ . │ ? │
     * └───┴───├───┼───┼───┤   ├───├───┼───┼───┴───┘
     *         │ ; │spc│tab│   │ent│bsp│del│
     *         └───┴───┴───┘   └───┴───┴───┘
     *                     ┌───┐
     *                     │UPA│
     *                 ┌───┼───┼───┐
     *                 │LFA│TOG│RTA│
     *                 └───├───┼───┘
     *                     │DNA│
     *                     └───┘
     */

    [2] = {
        {KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,     KC_O,   KC_P},
        {KC_A,   KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,     KC_K,     KC_L,   KC_QUOTE},
        {KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT, KC_SLASH},
        {KC_NO,  KC_NO,  KC_SCLN, KC_SPC,  KC_TAB,  KC_ENT,  KC_BSPC,  KC_DEL,   KC_NO,  KC_NO},
        {KC_NO,  KC_NO,  KC_DOWN, KC_LEFT, KC_UP,   LAYER_SHIFT, KC_RIGHT, KC_NO,    KC_NO,  KC_NO},
    },

    /*
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ [ │ ] │NOP│NOP│ G │   │ = │ - │NOP│NOP│ ` │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │   │ N │ M │ < │ > │ \ │
     * └───┴───├───┼───┼───┤   ├───├───┼───┼───┴───┘
     *         │ ; │spc│tab│   │ent│ctl│alt│
     *         └───┴───┴───┘   └───┴───┴───┘
     *                     ┌───┐
     *                     │UPA│
     *                 ┌───┼───┼───┐
     *                 │LFA│NOP│RTA│
     *                 └───├───┼───┘
     *                     │DNA│
     *                     └───┘
     */

    [3] = {
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_NO,  KC_NO,       KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_NO,  KC_NO,       KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_NO,  KC_NO,       KC_NO, KC_NO, QK_BOOT},
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_ENT, KC_NO,       KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   KC_DOWN, KC_LEFT, KC_UP, KC_NO,  KC_RIGHT, KC_NO, KC_NO, KC_NO},
    }

};

layer_state_t layer_state_set_user(layer_state_t state)
{
    switch (get_highest_layer(state)) 
    {
        case 2:
            autoshift_disable();
            break;
        default:
            autoshift_enable();
            break;
    }    
    return state;
}

// // Tap Dance function
// void mouse_click_tap_dance(qk_tap_dance_state_t* state, void* user_data)
// {
//     switch (state->count)
//     {
//         case 1:
//             // Single tap, send left mouse click
//             register_code(KC_BTN1);
//             unregister_code(KC_BTN1);
//             break;
//         case 2:
//             // Double tap, send right mouse click
//             register_code(KC_BTN2);
//             unregister_code(KC_BTN2);
//             break;
//     }
// }

// void CheckForBootloader()
// {
//     if (toggle_chord_active && alt_chord_active && control_chord_active)
//     {
//         // Put into bootloader mode
//         // uint16_t boot = QK_BOOT;
//         tap_code16(QK_BOOT);
//     }
// }

// void LayerUp(int* next_layer, const int num_layers)
// {

//     if (*next_layer + 1 == num_layers)
//     {
//         return;
//     }

//     changed_layers = true;
//     layer_off(*next_layer++);
//     layer_on(*next_layer);
// }

// void LayerDown(int* next_layer, const int num_layers)
// {
//     if (*next_layer == 0)
//     {
//         return;
//     }

//     changed_layers = true;
//     layer_off(*next_layer--);
//     layer_on(*next_layer);
// }

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    static int next_layer = 0;
    static int num_layers = sizeof(keymaps) / sizeof(keymaps[0]);

    static bool changed_layers = false;
    static bool toggle_chord_active = false;
    static bool control_chord_active = false;
    static bool alt_chord_active = false;
    static bool did_combo = false;
    static bool layer_shift = false;

    // CheckForBootloader();

    switch (keycode)
    {

        case LAYER_TOGGLE_CHORD:
        {

            if (record->event.pressed)
            {
                toggle_chord_active = true;
            }
            else
            {
                if (toggle_chord_active && !changed_layers)
                {
                    toggle_chord_active = false;
                    tap_code(LAYER_TOGGLE_CHORD);
                }
                else if (toggle_chord_active && changed_layers)
                {
                    toggle_chord_active = false;
                    changed_layers = false;
                }
            }

            return false;
        }
        case CONTROL_CHORD:
        {
            if (record->event.pressed)
            {
                control_chord_active = true;
            }
            else
            {
                if (control_chord_active && !did_combo)
                {
                    control_chord_active = false;
                    tap_code(CONTROL_CHORD);
                }
                else if (control_chord_active && did_combo)
                {
                    control_chord_active = false;
                    did_combo = false;
                }
            }

            return false;
        }
        case ALT_CHORD:
        {
            if (record->event.pressed)
            {
                alt_chord_active = true;
            }
            else
            {
                if (alt_chord_active && !did_combo)
                {
                    alt_chord_active = false;
                    tap_code(ALT_CHORD);
                }
                else if (alt_chord_active && did_combo)
                {
                    alt_chord_active = false;
                    did_combo = false;
                }
            }

            return false;
        }
        case LAYER_SHIFT:
            if (record->event.pressed && !layer_shift)
            {
                layer_shift = true;
                // Change layer up
                if (next_layer + 1 != num_layers)
                {
                    layer_off(next_layer++);
                    layer_on(next_layer);
                }
            }
            else if (layer_shift)
            {
                layer_shift = false;
                // Change layer down
                if (next_layer > 0)
                {
                    layer_off(next_layer--);
                    layer_on(next_layer);
                }
            }
            return false;
            
    }

    if (record->event.pressed)
    {
        switch(keycode)
        {
        case ALT_F1:
            register_code(KC_LALT);
            register_code(KC_F1);
            return false;
        case ALT_F2:
            tap_code16(QK_LALT | KC_F2);
            return false;
        case ALT_F3:
            unregister_code16(ALT_F3);
            register_code16(QK_LALT | KC_F3);
            return false;
        case ALT_F4:
            register_code(KC_LALT);
            register_code(KC_F4);
            return false;
        case ALT_F5:
            register_code(KC_LALT);
            register_code(KC_F5);
            return false;
        case ALT_F6:
            register_code(KC_LALT);
            register_code(KC_F6);
            return false;
        case ALT_F7:
            register_code(KC_LALT);
            register_code(KC_F7);
            return false;
        case ALT_F8:
            register_code(KC_LALT);
            register_code(KC_F8);
            return false;
        case ALT_F9:
            register_code(KC_LALT);
            register_code(KC_F9);
            return false;
        }
        if (control_chord_active)
        {
            // Send a control chord before the current key?
            // Unregister the current key and then re-register it
            unregister_code(keycode);
            tap_code16(QK_LCTL | keycode);
            did_combo = true;

            return false;
        }
        else if (alt_chord_active)
        {
            // Send a control chord before the current key?
            // Unregister the current key and then re-register it
            unregister_code(keycode);
            tap_code16(QK_LALT | keycode);
            did_combo = true;


            return false;
        }

        if (toggle_chord_active)
        {
            switch (keycode)
            {
                case KC_UP:
                {
                    changed_layers = true;
                    if (next_layer + 1 != num_layers)
                    {
                        layer_off(next_layer++);
                        layer_on(next_layer);
                    }
                    return false;
                }
                case KC_MS_UP:
                {
                    changed_layers = true;
                    if (next_layer + 1 != num_layers)
                    {
                        layer_off(next_layer++);
                        layer_on(next_layer);
                    }
                    return false;
                }
                case KC_DOWN:
                {
                    changed_layers = true;
                    if (next_layer > 0)
                    {
                        layer_off(next_layer--);
                        layer_on(next_layer);
                    }
                    return false;
                }
                case KC_MS_DOWN:
                {
                    changed_layers = true;
                    if (next_layer > 0)
                    {
                        layer_off(next_layer--);
                        layer_on(next_layer);
                    }
                    return false;
                }
                case KC_TAB:
                {
                    changed_layers=true;
                    mouse = !mouse;   
                }
                case KC_SPC:
                {
                    changed_layers=true;
                    if (autoshift_on)
                    {
                        autoshift_disable();
                        autoshift_on = false;
                    }
                    else 
                    {
                        autoshift_enable();
                        autoshift_on = true;
                    }
                }
            }
        }
        if (mouse)
        {
            switch (keycode)
            {
                case KC_UP:
                    unregister_code(KC_UP);
                    tap_code(KC_MS_UP);
                    return false;
                case KC_DOWN: 
                    unregister_code(KC_DOWN);
                    tap_code(KC_MS_DOWN);
                    return false;
                case KC_LEFT: 
                    unregister_code(KC_LEFT);
                    tap_code(KC_MS_LEFT);
                    return false;
                case KC_RIGHT: 
                    unregister_code(KC_RIGHT);
                    tap_code(KC_MS_RIGHT);
                    return false;
                case LAYER_SHIFT:
                    unregister_code16(LAYER_SHIFT);
                    register_code16(TD(TD_MOUSE_CLICK));
                    return false;
            }
        }
    }

    return true;
}

