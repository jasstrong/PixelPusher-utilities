PixelPusher-utilities
=====================

A collection of utilities to work with PixelPusher.

configtool
----------

A simple configuration tool to push stuff into a MP PixelPusher's EEPROM.
Also includes a handy terminal mode, showing the debug console!

Build it like so:

`gcc -oconfigtool configtool.c`

Invoke it like so:

`./configtool /dev/tty.usbmodem12341 ./pixel.rc`

If you're on a Mac.  If you're on Linux, then `/dev/ttyACM0` is more likely to be where it's at.
If you're on Windows, well, it's probably `COM9` or something.

It'll push the file into the EEPROM (be warned:  it will be truncated at 1022 bytes long) and 
then reboot the Pusher; you'll be left watching a live terminal onto the Pusher's console. You can type "Reboot" to
issue a hard reset, or type a lower-case "q" to quit.
