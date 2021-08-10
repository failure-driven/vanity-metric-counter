/*
  Arduino/ESP32/ESP8266 led-display

  Display a metric via on board LED

  Copyright (c) Michael Milewski <saramic@gmail.com>
*/

#define DEBUG true              // flag to turn on/off debugging

#define RAD_2 2 * M_PI
#define PERIOD_MILLIS 1000

#define LED_BUILTIN          2  // default GPIO 2 (blue)
#define LED_BUILTIN_ONBOARD 16  // optional onboard GPIO 16 (red) ESP8266 only

#if defined(ESP32)
#define LEDC_CHANNEL_0         0
#define LEDC_TIMER_13_BIT     13 // duty resolution of 13 bits 2^13 = 8192 discrete levels of LED intensity
#define MAX_DUTY            8192 // 2^LEDC_TIMER_RESOLUTION
#define LEDC_BASE_FREQ      5000 // 5kHz has maximum duty resolution of 13 bits
#endif

int duty(int maxDuty, double (*pMathFunction)(double rad) = sin)
{  
  const double magnitude = (*pMathFunction)((millis() % PERIOD_MILLIS) * RAD_2 / PERIOD_MILLIS);
  // math values range -1 .. +1
  // following math makes duty range 0 .. maxDuty ie 0 .. 256
  const int duty = ((maxDuty/2) * magnitude) + (maxDuty/2);
  
#if DEBUG
  Serial.println(duty);
#endif

  return duty;
}

void ledShow()
{
#if defined(ESP32)
  ledcWrite(LEDC_CHANNEL_0, duty(MAX_DUTY));
#else
  analogWrite(LED_BUILTIN, duty(256)); // 2^8
#endif

#if defined(ESP8266) // only ESP8266 has a 2nd inbuilt LED
  analogWrite(LED_BUILTIN_ONBOARD, duty(256, std::cos));
#endif
}

void setup()
{
#if DEBUG
  Serial.begin(115200);
#endif

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN_ONBOARD, OUTPUT);

#if defined(ESP32)
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(LED_BUILTIN, LEDC_CHANNEL_0);
#endif
}

void loop()
{
  ledShow();
  delay(20);
}
