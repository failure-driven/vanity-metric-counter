/*
  Arduino/ESP32/ESP8266 metric-via-serial

  Display a metric via serial port

  Copyright (c) Michael Milewski <saramic@gmail.com>
*/

#define RAD_2 2 * M_PI
#define PERIOD_MILLIS 1000

double mathValue(double (*)(double rad));

double sinValue()
{
  // 1 period of a sine wave is 2𝜋
  // starting at sin(0) and ending at sin(2𝜋) or sin(2 * M_PI)
  // millis() returns the milliseconds since boot time
  const int periodOffset = millis() % PERIOD_MILLIS;
  return sin(RAD_2 / PERIOD_MILLIS * periodOffset);
}

double mathValue(double (*pMathFunction)(double rad))
{
  return (*pMathFunction)((millis() % PERIOD_MILLIS) * RAD_2 / PERIOD_MILLIS);
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
//  Serial.print(sinValue());
  Serial.print("sin ");
  Serial.print(mathValue(std::sin));
  Serial.print(" cos ");
  Serial.println(mathValue(std::cos));
  delay(20);
}
