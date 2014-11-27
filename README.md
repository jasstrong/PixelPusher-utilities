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
issue a hard reset, or type a lower-case "q" to quit.  

If the config file parameter is omitted then it just reboots the pusher.  (If you skip a parameter, you may not issue any later ones.)

The third parameter can be absent;  if it is, you get the console thingy.  If it's 'echo', you get to see the first five seconds' worth of output from the pusher.  If it's anything else, you see nothing at all.  This is handy for scripting.

A transcript of how Maxime Dangles got it working
--------------------------------------------------

I'll let Maxime speak in his own words:

so, for people who want to put their pixel.rc in the PP (and, if like me, you need more detail, hahaha), i'm on mac :

- check first you install this update in your PP (you can re-update your PP with the lastest firmware after) : http://forum.heroicrobotics.com/thread/247/pixelpusher-firmware-updated-super-flasher
- download configtool : http://forum.heroicrobotics.com/thread/248/simple-eeprom-config-tool-source
- unzip it in your root folder
- in configtool folder edit the pixel.rc file as you want (save it !)
- run terminal

- you'll see that
```
> Last login: Thu Nov 27 08:00:40 on ttys000
> (name of your computer):~ (NAME OF YOUR COMPUTER)$
```
- write : cd configtool
press enter, your terminal root change, you'll see that now :
```
> Last login: Thu Nov 27 08:00:40 on ttys000
> (name of your computer):~ (NAME OF YOUR COMPUTER)$ 
> (name of your computer):configtool (NAME OF YOUR COMPUTER)$
```
- now write : ./configtool /dev/tty.usbmodem12341 pixel.rc
and press enter !

- the script will start, this is what i have :

```
> Last login: Thu Nov 27 08:02:31 on ttys000
> lesloulous:~ LES_LOULOUS$ cd /configtool
> lesloulous:configtool LES_LOULOUS$ ./configtool /dev/tty.usbmodem12341 pixel.rc
> ./configtool: writing config.
>
>
> Press q to quit.
>
> PixelPusher Supervisor ROM 1.3 booting
> Reset holdoff 1020 milliseconds
> Supervisor:  write new config file.
> pixels=360
> 
> strip1=apa102
> strip2=apa102
> strip3=apa102
> strip4=apa102
> strip5=apa102
> strip6=apa102
> ?
>
> Supervisor:  wrote 1023 byte(s).
> Still didn'tSupervisor:  Resetting main processor.
> Reset holdoff 1020 milliseconds
> get IP address.  Retrying.
> No address.  Trying agPixelPusher MP 1.38 ready and waiting!
> In Host_Init
> Initializing Host Stack
> Host Initialized
> Connect a Mass Storage device
> Could not enumerate device, retry 0: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 1: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 2: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 3: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 4: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 5: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 6: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 7: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 8: result = -1
> Connect a Mass Storage device
> Could not enumerate device, retry 9: result = -1
> Could not read config file from USB.  Trying LocalFileSystem.
> PixelPusher MP does not support LocalFileSystem.
> Attempting to read config from Supervisor.
> EXTRACTSupervisor:  Reading config from EEPROM.
> pixels=360
>
> strip1=apa102
> strip2=apa102
> strip3=apa102
> strip4=apa102
> strip5=apa102
> strip6=apa102
>
> ?Supervisor: config read complete.
>
>
> Got 214 bytes of config data.
> Reading config file pixel.rc
> Defaulting to no extension segments.
> Defaulting to port 9897 for strip data push.
> eth:  defaulting to dhcp
> Assuming eight strips.
> No controller number configured, defaulting to 0.
> No controller group configured, defaulting to 0.
> Configured for 360 pixels per segment.
> Computed max strips per packet = 1
> Overriding configured maximum strips per packet.
> Strip 1 colour ordering RGB.
> Strip 1 configured as APA102.
> Initial colour for strip 1 set to 0x000000
> Strip 2 colour ordering RGB.
> Strip 2 configured as APA102.
> Initial colour for strip 2 set to 0x000000
> Strip 3 colour ordering RGB.
> Strip 3 configured as APA102.
> Initial colour for strip 3 set to 0x000000
> Strip 4 colour ordering RGB.
> Strip 4 configured as APA102.
> Initial colour for strip 4 set to 0x000000
> Strip 5 colour ordering RGB.
> Strip 5 configured as APA102.
> Initial colour for strip 5 set to 0x000000
> Strip 6 colour ordering RGB.
> Strip 6 configured as APA102.
> Initial colour for strip 6 set to 0x000000
> Strip 7 colour ordering RGB.
> Strip 7 configured as APA102.
> Initial colour for strip 7 set to 0x000000
> Strip 8 colour ordering RGB.
> Strip 8 configured as APA102.
> Initial colour for strip 8 set to 0x000000
> Configured.  Let us proceed.
> Connecting... 
> No address.  Trying again...
> Still didn't get IP address.  Retrying.
> No address.  Trying again...
> Still didn't get IP address.  Retrying.
> No address.  Trying again...
```

- when you see this, press q to quit terminal :
```
> Configured. Let us proceed.
> Connecting...
> No address. Trying again...
> Still didn't get IP address. Retrying.
> No address. Trying again...
> Still didn't get IP address. Retrying.
> No address. Trying again...
```
- it's done, and i hope it'll help :)






