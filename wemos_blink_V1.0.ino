void BlinkLED(); // BlinkLED(color, times, milliseconds);

//RGB led wemos
int Green = 14; // D5 = GPIO14
int Red = 12; // D6 = GPIO12
int Blue = 13; // D7 = GPIO13

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);  // initialize onboard LED as output
  pinMode(Blue, OUTPUT);    // Initialize the LED pin as an output
  pinMode(Red, OUTPUT);     // Initialize the LED pin as an output
  pinMode(Green, OUTPUT);   // Initialize the LED pin as an output
}

void loop() {
  BlinkLED(Green, 1, 100);
  BlinkLED(Blue, 1, 100);
  BlinkLED(Red, 1, 100);
  BlinkLED(BUILTIN_LED, 1, 100);
}

void BlinkLED(uint8_t color, int times, int milliseconds)
{
  for (int i = 1; i < times + 1 ; i++ ) {
    digitalWrite(color, !digitalRead(color));
    delay(milliseconds);
  }
}
