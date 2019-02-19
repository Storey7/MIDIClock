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

//Pulse per quarter note. Each beat has 24 pulses.
//Tempo is based on software inner BPM.
const int pulseOutPin = 3;
const int ledPin = 13;

void handleNoteOn(byte inChannel, byte inNumber, byte inVelocity)
{
    Serial.print("NoteOn  ");
    Serial.print(inNumber);
    digitalWrite(ledPin, HIGH);
    tone(pulseOutPin, 440);
}
void handleNoteOff(byte inChannel, byte inNumber, byte inVelocity)
{
    Serial.print("NoteOff ");
    Serial.print(inNumber);
    digitalWrite(ledPin, LOW);
    noTone(pulseOutPin);
}

void setup() {
    Serial.begin(115200);
    while (!Serial);
    MIDI.begin();
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    pinMode(ledPin, OUTPUT);
    Serial.println("Arduino ready.");
}

void loop() {
    MIDI.read();
}

