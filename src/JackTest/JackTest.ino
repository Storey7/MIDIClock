const int pulseOutPin = 10;
const int ledPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pulseOutPin, OUTPUT);
}

void loop() {
  digitalWrite(pulseOutPin, HIGH);
  delay(100);
  digitalWrite(pulseOutPin, LOW);
  delay(100);
  
}
