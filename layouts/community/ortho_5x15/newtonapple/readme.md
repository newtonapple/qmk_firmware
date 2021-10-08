# newtonapple's 5x15 Layout for Mac Vim Programmers

This layout is designed to reduce fingers / wrist movements for Qwerty programmers.

Layers:
* `_QWERTY` base layer.
* `_NUM`    layer brings number into the homerow.
* `_SYM`    layer brings shift-number / symbols into homerow.
* `_MACVIM` layer provides VIM-style edits / movements and various system wide shortcuts.
* `_MOUSE`  layer provides mouse emulation

## Example Make Command w/ XD75:
```
make xd75:newtonapple
```

Or, make & flash firmware all in one command:
```
make xd75:newtonapple:dfu
```

To turn on all LED functionalities or selectively turn on LED functionalities:
```
make ALL_LED=yes xd75:newtonapple:dfu
make BACKLIGHT_ENABLE=yes xd75:newtonapple:dfu
make RGBLIGHT_ENABLE=yes xd75:newtonapple:dfu
```
To turn off all LED functionalities:
```
make ALL_LED=no xd75:newtonapple:dfu
```
