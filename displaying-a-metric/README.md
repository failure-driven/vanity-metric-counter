# Displaying a metric

You have a number/metric and you want to display it using an Arduino.

Arduino and associated boards often have an on board LED (light emitting diode) surely this could be usefull to display something? otherwise to program a device you end up connecting to it via a Serial interface, that same interface could be used to fetch the metric. Clearly these are small steps to get started but pretty quickly you will want to display numbers as numbers on a display like a dedicated 7 segment display or a more versatile OLED display

## Display a metric via serial port

The following sketch [metric-via-serial](./metric-via-serial/metric-via-serial.ino) is as simple is it gets. There are 2 default methods in an arduino sketch, the setup called at setup, and the loop called repeatadly whilst the Arduino is on. The setup step sets up a Serial port at 115,200 bps. The loop method repeadley prints 1,234 and waits 1,000 ms (1 second) before printing it again. Note that this will NOT mean the number gets printed accurately every second, as the printing of the number will take some number of milliseconds so don't assume the following code would be any use for a clock.

```{c}
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(1234);
  delay(1000);
}
```

sets up a serial connection and displays the number 1,234 on that serial port every 1 second. You can connect to it via the `Serial Monitor` from the

  Arduino IDE -> Tools -> `Serial Monitor`

or directly from the command line as follows assuming the speed is 11,5200 bps (bits per second)

```{sh}
# check for available devices
ls /dev/cu.usb*
/dev/cu.usbserial-0001

# connect using screen
screen /dev/cu.usbserial-0001 115200

# to get help in screen (ctrl key and a key)
CTRL-a ?
# to exit
CTRL-a CTRL-\

# alternately use cu (man cu for more info)
sudo cu -s 115200 -l /dev/cu.usbserial-0001
```

## display a sine wave

As displaying the same number is not that exciting, you could easily change this code to display the values of a sine wave - [sinewave-metric](./sinewave-metric/sinewave-metric.ino).

```{c}
#define RAD_2 2 * M_PI
#define PERIOD_MILLIS 1000

double sinValue()
{
  // 1 period of a sine wave is 2𝜋
  // starting at sin(0) and ending at sin(2𝜋) or sin(2 * M_PI)
  // millis() returns the milliseconds since boot time
  const int periodOffset = millis() % PERIOD_MILLIS;
  return sin(RAD_2 / PERIOD_MILLIS * periodOffset);
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.print(sinValue());
  delay(20);
}
```

this does not look very impressive in the `Serial Monitor`

```{log}
0.03
0.16
0.28
0.40
0.51
0.62
0.71
0.80
0.87
0.92
```

But we can not only plot the sine trigonometric function, but the cosine as well and when we pre-pend each data point with a label it can be displayed using the

  Arduino IDE -> Tools -> `Serial Plotter`

to give us something like

![sin and cos trigonometric functions plotted](images/sin_cos_plot.jpg)

in this case the math function is being passed as an argument to get the associated math value. Note: also a lot of the boiler plate from the previous code snippet have been removed.

```{c}
double mathValue(double (*pMathFunction)(double rad))
{
  return (*pMathFunction)((millis() % PERIOD_MILLIS) * RAD_2 / PERIOD_MILLIS);
}

void loop()
{
  Serial.print("sin ");
  Serial.println(mathValue(std::sin));
  Serial.print(", cos ");
  Serial.println(mathValue(std::cos));
  delay(20);
}
```

## display on an LED

The serial port is not very consumer centric, given you need to connect to it manually via a screen session or IDE enabled plotter. One output device that comes on most Arduino like boards is an onboard LED (light emitting diode). Let's use that as a display next.

## 7 segment display

## OLED display
