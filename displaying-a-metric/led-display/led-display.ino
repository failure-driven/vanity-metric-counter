/*
  Arduino/ESP32/ESP8266 led-display

  Display a metric via on board LED

  Copyright (c) Michael Milewski <saramic@gmail.com>
*/

#define DEBUG false              // flag to turn on/off debugging

#define RAD_2 2 * M_PI
#define PERIOD_MILLIS 1000

#define LED_BUILTIN 2           // default GPIO 2 (blue)
#define LED_BUILTIN_ONBOARD 16  // optional onboard GPIO 16 (red) ESP8266 

double mathValue(double (*pMathFunction)(double rad))
{
  return (*pMathFunction)((millis() % PERIOD_MILLIS) * RAD_2 / PERIOD_MILLIS);
}

void ledShow()
{
  // max duty for analogWrite is 2^8 - 1 = 256,
  // math values range -1 .. +1
  // following math makes duyt range 0 .. 255
  const byte duty = (128 * mathValue(std::sin)) + 128;
#if DEBUG
  Serial.println(duty);
#endif
  analogWrite(LED_BUILTIN, duty);
  const byte cosDuty = (128 * mathValue(std::cos)) + 128;
  analogWrite(LED_BUILTIN_ONBOARD, cosDuty);
}

void setup()
{
#if DEBUG
  Serial.begin(115200);
#endif
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN_ONBOARD, OUTPUT);
}

void loop()
{
  ledShow();
  delay(20);
}
