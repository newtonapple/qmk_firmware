# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) and other LLM Agents when working with code in this repository.

## Build Commands

QMK uses a Make-based build system. The format is `make <keyboard>:<keymap>[:<target>]`.

```bash
# Compile firmware
make planck/rev6:default
qmk compile -kb planck/rev6 -km default

# Compile and flash
make planck/rev6:default:flash

# Build all keymaps for a keyboard
make dz60:all

# Clean build artifacts
make clean
make distclean  # Also removes .build/, *.hex, *.bin, *.uf2

# List available keyboards
make list-keyboards
```

## Testing

```bash
# Run all unit tests
make test:all

# Run specific test
make test:basic
make test:tap_hold_configurations

# Python tests (QMK CLI)
nose2
```

## Linting and Formatting

```bash
# Format C code (use for quantum/, platforms/, tmk_core/)
qmk format-c --core-only <files>
clang-format -i <file>

# Format Python
qmk format-python <files>
yapf -ri lib/python/

# Lint keyboard configuration
qmk lint --keyboard <keyboard>

# Normalize text files
qmk format-text <files>
```

## Architecture

### Core Layers (bottom to top)

- **tmk_core/** - Base firmware layer (protocol handling, platform-agnostic)
- **platforms/** - Platform-specific implementations
  - `avr/` - ATmega32u4, etc. using LUFA USB stack
  - `chibios/` - ARM STM32 using ChibiOS RTOS
  - `arm_atsam/` - ARM ATSAM controllers
  - `test/` - Platform-agnostic test harness
- **quantum/** - QMK feature layer (keymaps, layers, macros, RGB, etc.)
- **keyboards/** - Hardware definitions (800+ keyboards)

### Program Flow

1. Entry point: `quantum/main.c` → `main()`
2. Platform initialization (LUFA/ChibiOS/ARM)
3. Main loop: `keyboard_task()` in `quantum/keyboard.c`
   - Matrix scanning (key press detection)
   - Action processing (quantum layer features)
   - USB HID reporting

### Keyboard Definition Structure

```
keyboards/<keyboard>/
├── <keyboard>.h          # LAYOUT macro definitions
├── config.h              # Hardware configuration (pins, matrix size)
├── rules.mk              # Feature flags (MOUSEKEY_ENABLE, RGB_MATRIX_ENABLE)
├── info.json             # Data-driven configuration
├── <keyboard>.c          # Keyboard-specific code
├── keymaps/
│   ├── default/
│   │   ├── keymap.c      # Key assignments per layer
│   │   ├── config.h      # Keymap-specific overrides
│   │   └── rules.mk      # Additional features for this keymap
│   └── <other_keymaps>/
└── <revisions>/          # PCB revisions (rev1/, rev2/, etc.)
```

### Configuration Priority (highest to lowest)

1. Keymap `config.h` / `rules.mk`
2. Keyboard revision `config.h` / `rules.mk`
3. Keyboard base `config.h` / `rules.mk`
4. QMK defaults

## Key Development Patterns

### Feature Enablement

Features are opt-in via `rules.mk` to preserve memory on constrained AVR chips (~28KB):

```makefile
# In rules.mk
MOUSEKEY_ENABLE = yes
RGB_MATRIX_ENABLE = yes
OLED_ENABLE = yes
```

### Keymap Definition

```c
// keyboards/<kb>/keymaps/<keymap>/keymap.c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T, ...
    ),
    [1] = LAYOUT(  // Function layer
        KC_GRV,  KC_F1, KC_F2, KC_F3, ...
    )
};
```

### Custom Functions

Override in keymap.c:
- `process_record_user()` - Custom key handling
- `matrix_scan_user()` - Called every matrix scan
- `layer_state_set_user()` - Layer change hooks

### LAYOUT Macros

Defined in `<keyboard>.h`, maps physical layout to matrix positions:

```c
#define LAYOUT_60_ansi( \
    K00, K01, K02, ... \
) { \
    { K00, K01, K02, ... }, \
    { K10, K11, K12, ... }, \
    ...
}
```

## Code Style

### C Code
- 4-space indentation (soft tabs)
- One True Brace Style
- Use `#pragma once` for headers
- Prefer `#if defined(X)` over `#ifdef X`
- Use `// clang-format off` around LAYOUT macros (clang-format breaks them)

### Python Code
- Python 3.7+ compatible
- PEP8 with 200 char line length (see `setup.cfg`)
- YAPF for formatting

## Important Files

- **builddefs/** - Build system modules and feature definitions
- **quantum/keymap_common.c** - Keymap processing
- **quantum/action.c** - Key action execution
- **lib/chibios/** and **lib/lufa/** - USB stack submodules
- **docs/** - Full documentation (run `qmk docs` to browse locally on port 8936)

## Common Workflows

### Adding a New Keyboard

1. Create directory structure under `keyboards/`
2. Define hardware in `config.h` (matrix pins, size, diode direction)
3. Create `info.json` for data-driven features
4. Define LAYOUT macro in `<keyboard>.h`
5. Create default keymap in `keymaps/default/keymap.c`
6. Test: `make <keyboard>:default`

### Modifying Core Features

1. Make changes in `quantum/` or `tmk_core/`
2. Run tests: `make test:all`
3. Format: `qmk format-c --core-only <files>`
4. Ensure no regressions in existing keyboards

### Git Workflow

```bash
git submodule update --init --recursive  # Initialize LUFA, ChibiOS, etc.
# or
make git-submodule
```

---

## User Profile: newtonapple (David Dai)

This dev branch contains custom keymaps for keyboards owned by newtonapple.

### Keyboards with Custom Keymaps

24 keyboards with `newtonapple` keymaps:
- **60%**: ai03/polaris, dz60, dztech/dz60rgb, dztech/dz60rgb_ansi, wilba_tech/wt60_b
- **65%**: gray_studio/space65
- **Alice/Ergo**: projectkb/alice, boardwalk, primekb/prime_e
- **40%**: kbdfans/kbd4x, c39, tanuki, alpha, pain27, 40percentclub/gherkin, nightmare, the_royal/liminal, tkc/candybar/lefty, wsk/gothic50, ryloo_studio/m0110, monarch
- **Macropads**: 1upkeyboards/super16, keebio/bdn9, 2_milk

### Userspace Architecture (`users/newtonapple/`)

The userspace provides shared functionality across all keyboards:

```
users/newtonapple/
├── newtonapple.h      # Layer definitions, includes
├── newtonapple.c      # Main userspace code
├── wrappers.h         # LAYOUT wrapper macros
├── wrappers_ortho.h   # Ortholinear key blocks
├── wrappers_ansi.h    # ANSI staggered key blocks
├── macvim.h/c         # Vim-style navigation layer
├── mac.h/c            # macOS-specific shortcuts
├── space_cadet.h/c    # Space cadet shift functionality
├── process_records.h/c # Custom keycode processing
├── config.h           # Shared configuration
└── rules.mk           # Feature flags for all keymaps
```

### Layer System

Layers defined in `newtonapple.h`:

```c
enum newtonapple_layers {
  _QWERTY,   // Base QWERTY layer
  _CODE,     // Code-specific modifications
  _CAP,      // Shifted/capital letters
  _MACVIM,   // Vim-style navigation (hjkl = arrows, w/b = word movement)
  _VIMNUM,   // Number input within MACVIM layer
  _MOUSE,    // Mouse keys and scrolling
  _NUM,      // Number row and function keys
  _SYM,      // Symbols (!@#$%^&*) and brackets
  _LED,      // LED/RGB controls
  _ADJUST,   // System settings, reset, audio
  _AUDIO,    // Audio controls
  _FN        // Function layer
};
```

### Layout Pattern

Keymaps use **wrapper macros** that expand predefined key blocks, allowing consistent layouts across different keyboards:

```c
// Individual keymaps reference shared blocks
[_QWERTY] = LAYOUT_wrapper(
    ________________ORTHO_GRID_QWERTY_L1________________,
    ________________ORTHO_GRID_QWERTY_R1________________,
    ...
),
```

Key features of the layout system:
- **Modular blocks** - 5-6 key blocks per side per row defined in `wrappers_ortho.h` and `wrappers_ansi.h`
- **Split space** - Bottom row uses split space with layer-tap keys
- **Home row mods** - Modifier keys on home row positions (GUI, ALT, CTRL, SHIFT)
- **Dual-function keys** - Most bottom row keys are layer-tap or mod-tap

### Bottom Row Pattern (Common Across Keyboards)

```c
CRTL_SLBRC,   // Ctrl when held, [ when tapped
ALT_SBSLS,    // Alt when held, \ when tapped
GUI_T_EQL,    // GUI when held, = when tapped
KC_SPC,       // Space
MACVIM_SQUOT, // MACVIM layer when held, ' when tapped
SFT_T_QUOT,   // Shift when held, ' when tapped
NUM_MINS,     // NUM layer when held, - when tapped
SYM_SMINS,    // SYM layer when held, - when tapped
ADJ_SRBRC     // ADJUST layer when held, ] when tapped
```

### MACVIM Layer (Vim-Style Navigation)

Custom macOS Vim emulation (`macvim.h/c`):
- `h/j/k/l` → Arrow keys
- `w/b` → Word forward/backward (Option+arrows on macOS)
- `0/$` → Home/End of line (Cmd+arrows)
- `d/c/y/x` → Delete/change/yank/cut operations
- `i/o` → Insert mode / new line
- `u` → Undo
- Number repetition support (e.g., `5j` moves down 5 lines)

### Build Commands for newtonapple Keymaps

```bash
# Build specific keyboard
make ai03/polaris:newtonapple
make dz60:newtonapple
make primekb/prime_e:newtonapple

# Flash to device
make dz60:newtonapple:flash

# Build all newtonapple keymaps (one at a time)
make ai03/polaris:newtonapple
make boardwalk:newtonapple
# ... etc
```

### Adding a New Keyboard to newtonapple Collection

1. Create keymap directory: `keyboards/<kb>/keymaps/newtonapple/`
2. Create `keymap.c` using wrapper macros:
   ```c
   #include QMK_KEYBOARD_H
   #include "newtonapple.h"

   const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_QWERTY] = LAYOUT_wrapper(
       // Use appropriate blocks from wrappers_ortho.h or wrappers_ansi.h
     ),
     // Add other layers...
   };
   ```
3. Optional: Add `config.h` for keyboard-specific settings
4. Optional: Add `rules.mk` for additional features
5. Test: `make <kb>:newtonapple`

### Apple Silicon Mac Setup

QMK works natively on Apple Silicon (M1/M2/M3/M4) Macs. The `avr-gcc` toolchain has been patched for ARM64.

#### Initial Setup

```bash
# 1. Install Homebrew (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# 2. Install QMK CLI (takes a while on Apple Silicon - compiles from source)
brew install qmk/qmk/qmk

# 3. Add avr-gcc@8 to PATH (required - not auto-linked by Homebrew)
export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"
# Add to ~/.zshrc for persistence

# 4. Setup QMK environment (answer 'y' to prompts, choose option 3 to keep existing repo)
qmk setup

# 5. Install QMK Toolbox (optional GUI for flashing)
brew install --cask qmk-toolbox
```

**Note:** Installation takes longer on Apple Silicon because many packages are compiled from source rather than using pre-built binaries. The `avr-gcc@8` formula is keg-only and won't be in your PATH automatically.

#### Compiling Firmware

```bash
# Using make (recommended)
make ai03/polaris:newtonapple
make dz60:newtonapple
make primekb/prime_e:newtonapple

# Using QMK CLI
qmk compile -kb ai03/polaris -km newtonapple
qmk compile -kb dz60 -km newtonapple

# Output files are placed in the qmk_firmware root directory
# Format: <keyboard>_<keymap>.hex (AVR) or .bin/.uf2 (ARM)
```

#### Flashing Firmware

**Method 1: Command Line (Recommended)**

```bash
# Auto-detect bootloader and flash
make dz60:newtonapple:flash
# or
qmk flash -kb dz60 -km newtonapple

# For specific bootloader targets:
make <keyboard>:<keymap>:dfu          # Atmel DFU (many custom keyboards)
make <keyboard>:<keymap>:avrdude      # Caterina (Pro Micro, Elite-C)
make <keyboard>:<keymap>:teensy       # HalfKay (Teensy)
make <keyboard>:<keymap>:dfu-util     # STM32 DFU (ARM boards)
```

**Method 2: QMK Toolbox (GUI)**

1. Open QMK Toolbox
2. Select the `.hex` or `.bin` file from the qmk_firmware directory
3. Put keyboard into bootloader mode
4. Click "Flash"

**Note:** On Apple Silicon, QMK Toolbox runs under Rosetta. Some flasher binaries may have limited compatibility.

#### Entering Bootloader Mode

Methods to put keyboard into bootloader (varies by keyboard):

1. **RESET keycode** - Press the RESET key in your ADJUST layer (often `ADJ_SRBRC` + specific key)
2. **Physical reset button** - Press the reset button on the PCB
3. **Short RST to GND** - Briefly connect RST and GND pins
4. **Boot + Reset** - Hold boot button while pressing reset (USBasploader)
5. **Double-tap reset** - Quick double-press reset button (some Caterina bootloaders)

**Common bootloader timeouts:**
- Caterina (Pro Micro): 7 seconds to flash after entering bootloader
- HalfKay (Teensy): 7 seconds
- DFU: No timeout, stays in bootloader until flashed

#### Troubleshooting on Apple Silicon

**Permission Issues:**
```bash
# If flashing fails due to USB permissions
sudo make dz60:newtonapple:flash
```

**dfu-programmer not found:**
```bash
brew install dfu-programmer
```

**avrdude not found:**
```bash
brew install avrdude
```

**Teensy Loader issues:**
```bash
brew install teensy_loader_cli
```

**QMK Toolbox flasher binaries not working:**
- Toolbox runs under Rosetta but flasher binaries may fail
- Use command-line flashing as alternative
- Ensure Rosetta is installed: `softwareupdate --install-rosetta`

**If compilation fails:**
```bash
# Reinstall toolchain
qmk setup --yes

# Or manually install AVR toolchain
brew install avr-gcc@8 avr-binutils avr-libc

# For ARM keyboards
brew install arm-none-eabi-gcc
```

#### Quick Reference for newtonapple Keyboards

```bash
# 60% keyboards
make ai03/polaris:newtonapple:flash
make dz60:newtonapple:flash
make dztech/dz60rgb:newtonapple:flash
make dztech/dz60rgb_ansi:newtonapple:flash

# 40% keyboards
make primekb/prime_e:newtonapple:flash
make kbdfans/kbd4x:newtonapple:flash

# Alice layout
make projectkb/alice:newtonapple:flash
make boardwalk:newtonapple:flash

# Macropads
make keebio/bdn9:newtonapple:flash
make 1upkeyboards/super16:newtonapple:flash
```
