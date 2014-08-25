PixelPusher-utilities
=====================

A collection of utilities to work with PixelPusher.

configtool
----------

A simple configuration tool to push stuff into a MP PixelPusher's EEPROM.
Also includes a handy terminal mode, showing the debug console!

The included binary works on OS X Mavericks on my particular computer.  If it doesn't work for you, you should build your own copy.

Build it like so:

`gcc -oconfigtool configtool.c`

Invoke it like so:

`./configtool /dev/tty.usbmodem12341 ./pixel.rc echo`

Or something like this:

`./configtool /dev/tty.usbmodem12341 ./pixel.rc no`

Or the classic:

`./configtool /dev/tty.usbmodem12341 ./pixel.rc`

This way is stylish too:

`./configtool /dev/tty.usbmodem12341`

The first parameter is the serial device that appeared when you connected the USB cable.
If you're on a Mac, the one given above is probably right.  If you're on Linux, then `/dev/ttyACM0` is more likely to be where it's at.
If you're on Windows, well, it's probably `COM9` or something.  Good luck with that.

The second parameter is the config file to push to the device.
It'll push the file into the EEPROM (be warned:  it will be truncated at 1022 bytes long) and 
then reboot the Pusher; you'll be left watching a live terminal onto the Pusher's console. You can type "Reboot" to
issue a hard reset, or type a lower-case "q" to quit.  If the config file parameter is omitted then it just reboots the pusher.  (If you skip a parameter, you may not issue any later ones.)

The third parameter can be absent;  if it is, you get the console thingy.  If it's 'echo', you get to see the first five seconds' worth of output from the pusher.  If it's anything else, you see nothing at all.

