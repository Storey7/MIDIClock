# Arduino MIDI clock

## Overview

The primary aim of this project is to develop a cheap and easy-to-use interface between a Digital Audio Workstation (DAW) and the control voltage used by analogue synthesizers, using an Arduino UNO.


### Goals

#### Primary

 * Receive MIDI clock input via usb
 * Output analogue control voltage / audio pulses. 

#### Secondary

 * Display showing current BPM and output type
 * Switches for altering the output. (1V/2V/5V, 1/2/4 pulses-per-quarter note etc.)

## Using Arduino UNO as USB MIDI device

To use the the UNO as a MIDI input device, you must first flash the Atmega16u2 chip with MIDI firmware.
The following steps outline this process:

1. Download Flip.
2. Download [HIDUINO](https://github.com/ddiakopoulos/hiduino/tree/master/compiled_firmwares) (MIDI firmware) and [Arduino](https://github.com/arduino/ArduinoCore-avr/tree/master/firmwares/atmegaxxu2/arduino-usbserial) (Original firmware) hex files. 
3. Upload project .ino schematic. (Important. You won't be able to upload schematics via usb once the chip has been flashed.)
4. Short these two pins to reset the chip. 
5. Run Flip and load the HIDUINO hex file. Click run to verify the hex, and then click start application to load the hex onto the chip.
6. Reset the Arduino. Your computer should now recognise it as a MIDI device and begin installing drivers. 
7. Once this is complete, your arduino should be listed as a MIDI controller in the DAW of your choice. 


## Example projects / Inspiration
[MIDIMatrix](http://www.erikoostveen.co.uk/#anchor2)

[MIDI Light controller](https://www.youtube.com/watch?v=98BkaUU0cMQ)

[Arduino MIDI Playground](http://playground.arduino.cc/Main/MIDILibrary)

[Reply 10 is very helpful](http://forum.arduino.cc/index.php/topic,52076.0.html)