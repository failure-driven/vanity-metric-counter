/*
  Arduino/ESP32/ESP8266 metric-via-serial

  Display a metric via serial port

  Copyright (c) Michael Milewski <saramic@gmail.com>
*/

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.println(1234);
  delay(1000);
}
