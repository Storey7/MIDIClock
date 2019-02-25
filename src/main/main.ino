/*Todo: 
 * CV output
 * Dynamic customisation of pulses per note/voltage levels. 
*/

#include <MIDI.h>

#if defined(USBCON)
#include <midi_UsbTransport.h>

static const unsigned sUsbTransportBufferSize = 16;
typedef midi::UsbTransport<sUsbTransportBufferSize> UsbTransport;

UsbTransport sUsbTransport;

MIDI_CREATE_INSTANCE(UsbTransport, sUsbTransport, MIDI);

#else // No USB available, fallback to Serial
MIDI_CREATE_DEFAULT_INSTANCE();
#endif

//MIDI clock signals.
byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;


const int pulseOutPin = 10;
const int ledPin = 13;

void handleNoteOn(byte inChannel, byte inNumber, byte inVelocity)
{
    digitalWrite(ledPin, HIGH);
    digitalWrite(pulseOutPin, HIGH);
}
void handleNoteOff(byte inChannel, byte inNumber, byte inVelocity)
{
    digitalWrite(ledPin, LOW);
    digitalWrite(pulseOutPin, LOW);
}

void setup() {
    MIDI.begin();
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);

    /*
    MIDI.setHandleClock(handleClock);
    MIDI.setHandleStart(handleStart);
    MIDI.setHandleStop(handleStop);
    MIDI.setHandleContinue(handleContinue);
    */
    pinMode(pulseOutPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.println("Arduino ready.");
}

void loop() {
    MIDI.read();
}

