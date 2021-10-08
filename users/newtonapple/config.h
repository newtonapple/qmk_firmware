#pragma once

// #define MOUSEKEY_DELAY             25  // default 300
// #define MOUSEKEY_INTERVAL          35  // default 50
// #define MOUSEKEY_MAX_SPEED         20  // default 10
// #define MOUSEKEY_TIME_TO_MAX       20  // default 20
// #define MOUSEKEY_WHEEL_MAX_SPEED   18  // default 8
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40  // default 40

// #define MOUSEKEY_DELAY              0  // default 300
// #define MOUSEKEY_INTERVAL          16  // default 50
// #define MOUSEKEY_MAX_SPEED         20  // default 10
// #define MOUSEKEY_TIME_TO_MAX       85  // default 20

#define MOUSEKEY_DELAY 15        // default 300
#define MOUSEKEY_INTERVAL 10     // default 50
#define MOUSEKEY_MAX_SPEED 15    // default 10
#define MOUSEKEY_TIME_TO_MAX 50  // default 20

// #define MOUSEKEY_WHEEL_DELAY        0
#define MOUSEKEY_WHEEL_MAX_SPEED 15    // default 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40  // default 40

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifdef FAST_MCU
#    define TAPPING_TERM 125
#    define CUSTOM_TAP_DELTA 135
#else
#    define TAPPING_TERM 200
#    define CUSTOM_TAP_DELTA 75
#endif
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

// #define IGNORE_MOD_TAP_INTERRUPT

#define ENABLE_MACVIM
#define ENABLE_SPACE_CADET

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }

#    define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#    define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and
 * allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
#    define AUDIO_CLICKY
#endif

/* RGB */
// #ifdef RGBLED_NUM
// #undef RGBLED_NUM
// #define RGBLED_NUM 21 // number of LEDs (sliver kprepublic case)
// #define RGBLED_NUM 36 // number of LEDs (kbdfans 5-degree acrylic case)
// #endif
