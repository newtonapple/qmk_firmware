# newtonapple's 4x12 Layout for Mac Vim Programmers

This layout is designed to reduce fingers / wrist movements for Qwerty programmers.

Layers:
* `_QWERTY` base layer.
* `_NUM`    layer brings number into the homerow.
* `_SYM`    layer brings shift-number / symbols into homerow.
* `_MACVIM` layer provides VIM-style edits / movements and various system wide shortcuts.
* `_MOUSE`  layer provides mouse emulation

## Example Make Command:
```
make planck:newtonapple
```

Or, make & flash firmware all in one command:
```
sleep 3 && make planck/rev6:newtonapple:dfu-util
make zlant:newtonapple:dfu
```

To turn on all LED functionalities or selectively turn on LED functionalities:
```
make ALL_LED=yes planck/rev6:newtonapple:dfu-util
make RGBLIGHT_ENABLE=yes zlant:newtonapple:dfu
```
To turn off all LED functionalities:
```
make ALL_LED=no planck/rev6:newtonapple:dfu-util
```
