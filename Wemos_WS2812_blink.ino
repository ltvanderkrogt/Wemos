/*******************************************************************
    this is a basic example how to program a Telegram Bot
    using TelegramBOT library on ESP8266
 *                                                                 *
    Open a conversation with the bot, you can command via Telegram
    a led from ESP8266 GPIO
    https://web.telegram.org/#/im?p=@FlashledBot_bot
 *                                                                 *
    written by Giancarlo Bacchio
    modified by Leon van der Krogt (group commands and security)
 *******************************************************************/
/* Pin (on the board)  Function  ESP8266 correspondence
  TX    TXD       TXD
  RX    RXD       RXD
  A0    Analog input, max 3.3V input  A0
  D0  IO  GPIO16
  D1  IO, SCL GPIO5
  D2  IO, SDA GPIO4
  D3  IO, 10k Pull-up GPIO0
  D4  IO, 10k Pull-up, BUILTIN_LED  GPIO2  // do not use this as output, esp won't start at power on!
  D5  IO, SCK GPIO14
  D6  IO, MISO  GPIO12
  D7  IO, MOSI  GPIO13
  D8  IO, 10k Pull-down, SS GPIO15
  G GND GND
  5V  5V  –
  3V3 3.3V  3.3V
  RST Reset RST
*/


#include <Adafruit_NeoPixel.h> //Install [Adafruit_NeoPixel_Library](https://github.com/adafruit/Adafruit_NeoPixel) first.

#define PIN            4

int R;
int G;
int B;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
pixels.begin(); // This initializes the NeoPixel library.
}


void loop() {
    R = 0; G = 1; B = 0;
    for (int i = 0; i < 255; i++) {
      pixels.setPixelColor(0, pixels.Color(i * R, i * G, i * B));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(5); // Delay for a period of time (in milliseconds).
    }
        R = 1; G = 0; B = 0;
    for (int i = 0; i < 255; i++) {
      pixels.setPixelColor(0, pixels.Color(i * R, i * G, i * B));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(5); // Delay for a period of time (in milliseconds).
    }
        R = 0; G = 0; B = 1;
    for (int i = 0; i < 255; i++) {
      pixels.setPixelColor(0, pixels.Color(i * R, i * G, i * B));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(5); // Delay for a period of time (in milliseconds).
    }
  }
