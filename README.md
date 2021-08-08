# Vanity Metric Counter

The story of building a vanity metric counter for displaying vanity metrics in a startup, home, whatever.

## TL;DR

```
make
```

## Background

Every company, startup, fitness junkie, YouTube star or person has a vanity metric they may want to display. Be it the number of customers, number of followers or the number kilometers covered. This could be displayed physically in a prominent position to help awarness and to drive the on lookers further. What better way to display it then through an LED or e-paper display powered by one of the many internet connected, embedded electronic devices like an Arduino, ESP32 or ESP8266.

This may seem easy, but what would it take to be able to gift this to your "boss"? like a kind of "consumer electronics" device. Usually the programmer "hacks" the code, put's their wifi credentials right in the code and adds where the vanity metric endpoint is, as well as how to authenticate and parse the output. In the proposed build here, the bootstrapping of the device should be able to be done by the end user, with no programming tools nor experience.

Here is my story of building just that.

## Overview

To allow a non technical end user to "bootstrap" the setup of an ESP32 style device to display custom vanity metrics the following steps need to be performed.

1. power on
1. inform the user the power is switched on and the device is booting
  1. alternately inform the user that there is no power
  1. or that the device is failing to boot
1. inform the user the device is ready to be configured
1. allow the user to connect to the device
  1. serial?
  1. bluetooth?
  1. device runs an AP (Access Point) to connect to the device via it's own WiFi hotspot?
  1. maybe a QR code on an OLED display informs the user what the WiFi is called?
1. once connected, allow the user to configure the SSID and password
  1. via a web form
  1. allow the device to pre-populate the form with available WiFi SSID's to reduce typing
  1. and save the selected credentials to EEPROM on the device? or Flash?
1. inform the user that the device is trying to connect to WiFi
  1. alternatively that it cannot connect?
  1. and it goes back to being an AP to be configured again
1. infrom the user the device is on the WiFi
1. inform the user how to set the vanity metric credentials
  1. maybe a QR code is dispalyed on the device's mDNS (multicast DNS) name? http://counter.local ? what if 2 devices are on the network?
1. save the vanity metric credentials to EEPROM or Flash
1. inform the user the vanity metric is being fetched
  1. inform the user it failed to fetch
  1. allow user to reconfigure it
1. display the vanity metric on the web view of the device
1. display the vanity metric on the display of the device
1. the device is now setup and opperational! 🎉
1. inform the user the data source is no longer reponding
1. inform the user the wifi is no longer connected
1. inform the user the battries are going flat
1. allow user to reset the data source
1. allow user to reset the WiFi
1. allow the user to reset the whole device, including WiFi

as you can see, there are a lot of steps to allow a non technical user to deal with a web connected device.

The approach I plan to take is as follows:

1. choose the device Arduino, ESP32, ESP8266, other; the development environment; the build process
1. look at all the ways a metric can be displayed: Serial port, Serial port plotting, on board LED, 7 segment display, OLED display, etc
1. WiFi connect the device and display a metric from a remote site
1. WiFi use the internet connectivity of the device to also display the metric and make it pretty by using a frontend framework to generate the code to be displayed by the device
1. Create a web form to allow the vanity metric credentials to be input, saved and used to fetch the metric. Also the start of an FSM (finite state machine).
1. Run the device in AP mode as a WiFi hotspot and allow the user to set WiFi credentials for their home WiFi. More FSM and maybe display a QR code to help user find where to go to configure the device.
1. Putting it all together
  1. AP to setup WiFi
  1. once internet connected, setup data source
  1. poll data
  1. display data
1. Dealing with all the edge cases, resetting the device
1. other displays - e-paper and longer powerdown polling
1. battery charger
1. flip dot display

## Progress

1. **Development Environment**
  - download latest [Arduino IDE](https://www.arduino.cc/en/software) from arduino.cc
    - OR use [VSCode](https://code.visualstudio.com/) and this [Arduino extension](https://maker.pro/arduino/tutorial/how-to-use-visual-studio-code-for-arduino) - note that you still need standarad Arduino IDE isntalled.
  - get a board, probably ESP32 is your best bet (from Jaycar locally in Melbourne or on Ebay, Amazon, Banggood, etc)
1. **Displaying a metric**
   [displaying-a-metric](./displaying-a-metric)
1. **Fetch a metric** over the internet

   ...
