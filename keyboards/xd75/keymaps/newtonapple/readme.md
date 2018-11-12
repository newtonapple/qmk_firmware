# newtonapple's XD75 Layout for Mac Vim Programmers

This layout is designed to reduce fingers / wrist movements for Qwerty programmers.

Layers:
* `_QWERTY` base layer.
* `_NUM`    layer brings number into the homerow.
* `_SYM`    layer brings shift-number / symbols into homerow.
* `_MACVIM` layer provides VIM-style edits / movements and various system wide shortcuts.
* `_MOUSE`  layer provides mouse emulation

## Make Command:
```
make xd75:newtonapple
```
After the make command, there should now be a `./xd75_newtonapple.hex` file located in the qmk_firmware directory.

## Flash via QMK Toolbox (GUI)
QMK Toolbox:
* select Microcontroller: `atmega32u4`
* open local xd75_newtonapple.hex
* reset keyboard (through pinholes reset located in the middle of the keyboard, or firmware `RESET` key)
* click the flash button


## Flash via dfu-programmer  (commandline, requires a 2nd keyboard)
Reset keyboard (you should see the following message):
```
*** DFU device connected
```

From another keyboard type the following:
```
dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash ./xd75_newtonapple.hex
dfu-programmer atmega32u4 reset
```

