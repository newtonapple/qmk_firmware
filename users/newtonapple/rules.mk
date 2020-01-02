SRC += newtonapple.c \
       mac.c \
       macvim.c \
       space_cadet.c \
       process_records.c

BOOTMAGIC_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
EXTRAFLAGS += -flto

## Build options example:
# turn on all LED options:
#    make ALL_LEDS=true xd75:newtonapple
ifeq ($(strip $(ALL_LEDS)), yes)
    BACKLIGHT_ENABLE = yes
    RGBLIGHT_ENABLE  = yes        # Enable WS2812 RGB underlight.
    VELOCIKEY_ENABLE = yes        # speed up underglow animation when typing fast
else ifeq ($(strip $(ALL_LEDS)), no) # turn off all LEDs
    BACKLIGHT_ENABLE = no
    RGBLIGHT_ENABLE  = no
    VELOCIKEY_ENABLE = no
else
    # selectively turn on LED options
    # make BACKLIGHT_ENABLE=true xd75:newtonapple
    ifeq ($(strip $(BACKLIGHT_ENABLE)), yes)
        BACKLIGHT_ENABLE = yes
    else ifeq ($(strip $(BACKLIGHT_ENABLE)), no)
        BACKLIGHT_ENABLE = no
    endif

    ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
        RGBLIGHT_ENABLE = yes
        VELOCIKEY_ENABLE = yes
    else ifeq ($(strip $(RGBLIGHT_ENABLE)), no)
        RGBLIGHT_ENABLE = no
        VELOCIKEY_ENABLE = no
    endif
endif

