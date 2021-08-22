/*
  Arduino/ESP32/ESP8266 7seg-display

  Display a metric via a 7 segment LED display driven by a MAX7219

  Copyright (c) Michael Milewski <saramic@gmail.com>
*/

/*
    https://github.com/noah1510/LedController

    and Not LedControl which does NOT support ESP32
      LedControl.h
      https://github.com/wayoda/LedControl
      http://wayoda.github.io/LedControl/

      // LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);

      LedControl lc = LedControl(23, 18, 5, 1);
*/
#include "LedController.hpp"

// SETUP
#define CS                  5
#define DIGITS_PER_SEGMENT  8
#define LETTER_SCROLL_DELAY  200
#define POST_TEXT_DELAY     2000
/*
                   => VCC
                   => GND
   GPIO23/SPI_MOSI => DIN
   GPIO5/SPI_CS0   => CS
   GPIO18/SPI_CLK  => CLK
*/
// single MAX72XX so the Dimensions are 1, 1
LedController<1, 1> lc = LedController<1, 1>();
// LedController<1, 1> lc = LedController<1,1>(DIN,CLK,CS); // without hardware SPI

void setup()
{
  Serial.begin(115200);
  lc.init(CS);
  lc.setIntensity(8); // 0 = low, 8 = medium
  lc.clearMatrix();
}

void writeWordsOn7Segment(char* text, size_t textSize)
{
  lc.clearMatrix();
  for (byte index = 0; index < textSize; index++) {
    for (byte letterIndex = 0; letterIndex < DIGITS_PER_SEGMENT; letterIndex++) {
      char letter = ' ';
      if (index - DIGITS_PER_SEGMENT + letterIndex > -1) {
        letter = text[index - DIGITS_PER_SEGMENT + letterIndex];
      }
      lc.setChar(0, DIGITS_PER_SEGMENT - 1 - letterIndex, letter, false);
    }
    delay(LETTER_SCROLL_DELAY);
  }
  delay(POST_TEXT_DELAY);
}

void writeMetric(unsigned long number)
{
  for (byte index = 0; index < DIGITS_PER_SEGMENT; index++) {
    unsigned long divisor = 1;
    for (byte offset = 0; offset < index; offset++) {
      divisor *= 10;
    }

    byte digit = number / divisor % 10;
    lc.setDigit(0, index % DIGITS_PER_SEGMENT, digit, false);
  }
}

void loop() {
  char welcomeText[] = "mEtric CountEr";
  writeWordsOn7Segment(welcomeText, sizeof(welcomeText) / sizeof(*welcomeText));
  for (byte displayCount = 0; displayCount < 3; displayCount++) {
    writeMetric(millis());
    delay(1000);
  }
}
