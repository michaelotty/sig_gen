void setup() {
  pinMode(9, OUTPUT);
  //Fast PWM mode and OCR1A as TOP level
  TCCR1A = _BV(WGM10) | _BV(WGM11) | _BV(COM1A0) | _BV(COM1B0);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS10);
  TCCR2A = _BV(COM2A0) | _BV(WGM21);

  //OCR1A = 65535; //40kHz = 199
}

void loop() {
  //Fast PWM
  TCCR1A = _BV(WGM10) | _BV(WGM11) | _BV(COM1A0) | _BV(COM1B0);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS10);
  TCCR2A = _BV(COM2A0) | _BV(WGM21);
  OCR1A = 199;//40kHz
  delayMicroseconds(499);//One less reduces glitch at the end

  //Write low for duration
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR2A = 0;
  digitalWrite(9, LOW);
  delay(5);
}
