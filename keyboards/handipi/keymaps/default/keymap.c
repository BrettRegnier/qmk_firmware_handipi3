// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include <string.h>

#define LAYER_TOGGLE_CHORD KC_ENT
#define CONTROL_CHORD KC_SPC
#define ALT_CHORD KC_SCLN

// void CheckForBootloader(void);
// void LayerUp(int* next_layer, const int num_layers);
// void LayerDown(int* next_layer, const int num_layers);


// Global variables

enum
{
    TD_MOUSE_CLICK = 0,
    TD_L_S_BRACKET,
    TD_R_S_BRACKET,
    TD_L_C_BRACKET,
    TD_R_C_BRACKET,
    TD_PLUS,
    TD_MINUS,
    TD_UNDER,
    TD_EQUAL,
    TD_TILDE
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions [] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_MOUSE_CLICK] = ACTION_TAP_DANCE_DOUBLE(KC_BTN1, KC_BTN2),
    [TD_L_S_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_LEFT_BRACKET),
    [TD_R_S_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_RIGHT_BRACKET),
    [TD_L_C_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_LEFT_CURLY_BRACE),
    [TD_R_C_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_RIGHT_CURLY_BRACE),
    [TD_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_PLUS),
    [TD_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_MINUS),
    [TD_UNDER] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_UNDERSCORE),
    [TD_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_EQUAL),
    [TD_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_GRAVE),
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
     *                 │LFA│CLK│RTA│
     *                 └───├───┼───┘
     *                     │DNA│
     *                     └───┘
     */

    [0] = {
        {KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,     KC_O,   KC_P},
        {KC_A,   KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,     KC_K,     KC_L,   KC_QUOTE},
        {KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT, KC_SLASH},
        {KC_NO,  KC_NO,  KC_SCLN, KC_SPC,  KC_TAB,  KC_ENT,  KC_BSPC,  KC_DEL,   KC_NO,  KC_NO},
        {KC_NO,  KC_NO,  KC_DOWN, KC_LEFT, KC_UP,   TD(TD_MOUSE_CLICK), KC_RIGHT, KC_NO,    KC_NO,  KC_NO},
    },

    /*
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ [ │ ] │ { │ } │ G │   │ + │ - │ _ │ = │ ` │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │   │ N │ M │ < │ > │ \ │
     * └───┴───├───┼───┼───┤   ├───├───┼───┼───┴───┘
     *         │ ; │spc│tab│   │ent│ctl│alt│
     *         └───┴───┴───┘   └───┴───┴───┘
     *                     ┌───┐
     *                     │MSU│
     *                 ┌───┼───┼───┐
     *                 │MSL│CLK│MSR│
     *                 └───├───┼───┘
     *                     │MSD│
     *                     └───┘
     */

    [1] = {
        {KC_1,   KC_2,   KC_3,    KC_4,    KC_5,   KC_6,    KC_7,     KC_8,    KC_9,   KC_0},
        {KC_LEFT_BRACKET,   KC_RIGHT_BRACKET,   KC_LEFT_CURLY_BRACE,    KC_RIGHT_CURLY_BRACE,    KC_NO,   KC_PLUS,    KC_MINUS,     KC_UNDERSCORE,    KC_EQUAL,   KC_GRAVE},
        {KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,   KC_N,    KC_M,     KC_LABK, KC_RABK, KC_BACKSLASH},
        {KC_NO,  KC_NO,  KC_ESC,  KC_SPC,  KC_TAB, KC_ENT,  KC_BSPC,  KC_LALT,  KC_NO,  KC_NO},
        {KC_NO,  KC_NO,  KC_MS_DOWN, KC_MS_LEFT, KC_MS_UP,  TD(TD_MOUSE_CLICK), KC_MS_RIGHT, KC_NO,   KC_NO,  KC_NO},
    },

    /*
     * ┌───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │   │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ [ │ ] │ { │ } │ G │   │ + │ - │ _ │ = │ ` │
     * ├───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │   │ N │ M │ < │ > │ \ │
     * └───┴───├───┼───┼───┤   ├───├───┼───┼───┴───┘
     *         │ ; │spc│tab│   │ent│ctl│alt│
     *         └───┴───┴───┘   └───┴───┴───┘
     *                     ┌───┐
     *                     │MSU│
     *                 ┌───┼───┼───┐
     *                 │MSL│CLK│MSR│
     *                 └───├───┼───┘
     *                     │MSD│
     *                     └───┘
     */

    [2] = {
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_NO,  KC_NO,       KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_NO,  KC_NO,       KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_NO,  KC_NO,       KC_NO, KC_NO, QK_BOOT},
        {KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,    KC_ENT, KC_NO,       KC_NO, KC_NO, KC_NO},
        {KC_NO,   KC_NO,   KC_MS_DOWN, KC_MS_LEFT, KC_MS_UP, KC_NO,  KC_MS_RIGHT, KC_NO, KC_NO, KC_NO},
    }

};

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
    }

    if (record->event.pressed)
    {
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
                    if (next_layer + 1 != num_layers)
                    {
                        changed_layers = true;
                        layer_off(next_layer++);
                        layer_on(next_layer);
                        return false;
                    }
                }
                case KC_MS_UP:
                {
                    if (next_layer + 1 != num_layers)
                    {
                        changed_layers = true;
                        layer_off(next_layer++);
                        layer_on(next_layer);
                        return false;
                    }
                }
                case KC_DOWN:
                {
                    if (next_layer > 0)
                    {
                        changed_layers = true;
                        layer_off(next_layer--);
                        layer_on(next_layer);
                        return false;
                    }
                }
                case KC_MS_DOWN:
                {
                    if (next_layer > 0)
                    {
                        changed_layers = true;
                        layer_off(next_layer--);
                        layer_on(next_layer);
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

