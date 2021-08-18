# ESP32 PinOut

**Note:** board layout is illustrative only and may change depending on
manufacturer.

**Note:** 

- all GPIOs support PWM and interrupts
- GPIOs 34-39 are input only
- do not use GPIOs 6 - 11 - which are not part of this pin out

## Serial, Control and DAC pins

```
                                      ------------------
                                     | |--|  |--|  |--| |
  Chip-enable signal, Active High EN | |  |--|  |--|  | | GPIO23                 SPI_MOSI  HS1_STROBE
                   SENSOR_VP  GPIO36 |  --------------  | GIPO22  EMAC_TXD1      U0RTS     I2C_SCL
                   SENSOR_VN  GPIO39 | |              | | GIPO1   EMAC_RXD2      U0TXD     CLK OUT3
                   VDET_1     GPIO34 | | ESP-WROOM-32 | | GPI03                  U0RXD     CLK OUT2
                   VDET_2     GPIO35 | |              | | GPI021  EMAC_TX_EN               I2C_SDA
                   XTAL_32K_P GPIO32 | |              | | GPI019  EMAC_TXD0      U0CTS     SPI_MISO
                   XTAL_32K_N GPIO33 | |              | | GPI018                 SPI_CLK   HS1_DATA7
            DAC_1  EMAC_RXD0  GPIO25 | |              | | GPI05   EMAC_RX_CLK    SPI_CS0   HS1_DATA6
            DAC_2  EMAC_RXD1  GPIO26 |  --------------  | GPI017  EMAC_CLKOUT180 U2_TXD    HS1_DATA5
                   EMAC_RX_DV GPIO27 |                  | GPI016  EMAC_CLKOUT    U2_RXD    HS1_DATA4
HS2_CLK   SD_CLK   EMAC_TXD2  GPIO14 |                  | GPI04   EMAC_TX_ER               HSPIHD    SD_DATA1 HS2_DATA1
HSPI_CLK  MTMS                       |                  |
HS2_DATA2 SD_DATA2 EMAC_TXD3  GPIO12 |                  | GPI02                            HSPIWP
HSPI_MISO MTDI                       |                  |
HS2_DATA3 SD_DATA3 EMAC_RX_ER GPIO13 |                  | GPI015  EMAC_RXD3      MIDO      HSPI_CS0  SD_CMD   HS2_CMD
HSPI_MOSI MTCK                       |                  |
                              GND    | EN   _____  BOOT | GND
                              VIN    | [ ] / USB \  [ ] | VDD 3V3
                                      ------------------
```

## Analog Pin

```
                                      ------------------
                                     | |--|  |--|  |--| |
                              EN     | |  |--|  |--|  | | GPIO23
            ADC PA  ADC1_CH0  GPIO36 |  --------------  | GIPO22
            ADC PA  ADC1_CH3  GPIO39 | |              | | GIPO1
                    ADC1_CH6  GPIO34 | | ESP-WROOM-32 | | GPI03
                    ADC1_CH7  GPIO35 | |              | | GPI021
                    ADC1_CH4  GPIO32 | |              | | GPI019
                    ADC1_CH5  GPIO33 | |              | | GPI018
                    ADC2_CH8  GPIO25 | |              | | GPI05
                    ADC2_CH9  GPIO26 |  --------------  | GPI017
                    ADC2_CH7  GPIO27 |                  | GPI016
                    ADC2_CH6  GPIO14 |                  | GPI04   ADC2_CH0
                    ADC2_CH5  GPIO12 |                  | GPI02   ADC2_CH2
                    ADC2_CH4  GPIO13 |                  | GPI015  ADC2_CH3
                              GND    | EN   _____  BOOT | GND
                              VIN    | [ ] / USB \  [ ] | VDD 3V3
                                      ------------------
```

## Port Pin

```
                                      ------------------
                                     | |--|  |--|  |--| |
                              EN     | |  |--|  |--|  | | GPIO23
                  RTC_GPIO0   GPIO36 |  --------------  | GIPO22
                  RTC_GPIO3   GPIO39 | |              | | GIPO1
                  RTC_GPIO4   GPIO34 | | ESP-WROOM-32 | | GPI03
                  RTC_GPIO5   GPIO35 | |              | | GPI021
                  RTC_GPIO9   GPIO32 | |              | | GPI019
                  RTC_GPIO8   GPIO33 | |              | | GPI018
                  RTC_GPIO6   GPIO25 | |              | | GPI05
                  RTC_GPIO7   GPIO26 |  --------------  | GPI017
                  RTC_GPIO17  GPIO27 |                  | GPI016
                  RTC_GPIO16  GPIO14 |                  | GPI04   RTCIO10
                  RTC_GPIO15  GPIO12 |                  | GPI02   RTCIO12
                  RTC_GPIO14  GPIO13 |                  | GPI015  RTCIO13
                              GND    | EN   _____  BOOT | GND
                              VIN    | [ ] / USB \  [ ] | VDD 3V3
                                      ------------------
```

## Touch Pin

```
                                      ------------------
                                     | |--|  |--|  |--| |
                              EN     | |  |--|  |--|  | | GPIO23
                              GPIO36 |  --------------  | GIPO22
                              GPIO39 | |              | | GIPO1
                              GPIO34 | | ESP-WROOM-32 | | GPI03
                              GPIO35 | |              | | GPI021
                      Touch9  GPIO32 | |              | | GPI019
                      Touch8  GPIO33 | |              | | GPI018
                              GPIO25 | |              | | GPI05
                              GPIO26 |  --------------  | GPI017
                      Touch7  GPIO27 |                  | GPI016
                      Touch6  GPIO14 |                  | GPI04   Touch0
                      Touch5  GPIO12 |                  | GPI02   Touch2
                      Touch4  GPIO13 |                  | GPI015  Touch3
                              GND    | EN   _____  BOOT | GND
                              VIN    | [ ] / USB \  [ ] | VDD 3V3
                                      ------------------
```

## All pins

```
                                                 ------------------
                                                | |--|  |--|  |--| |
        Chip-enable signal, Active Hight EN     | |  |  |  |  |  | | GPIO23                 SPI_MOSI  HS1_STROBE
                                                | |  |  |  |  |  | |
           ADC PA  RTC_GPIO0  SENSOR_VP  GPIO36 | |  |--|  |--|  | | GIPO22  EMAC_TXD1      U0RTS     I2C_SCL
                                                |  --------------  |
           ADC PA  RTC_GPIO3  SENSOR_VN  GPIO39 | |              | | GIPO1   EMAC_RXD2      U0TXD     CLK OUT3
                                                | |              | |
                   RTC_GPIO4  VDET_1     GPIO34 | |              | | GPI03                  U0RXD     CLK OUT2
                                                | | ESP-WROOM-32 | |
                   RTC_GPIO5  VDET_2     GPIO35 | |              | | GPI021  EMAC_TX_EN               I2C_SDA
                                                | |              | |
           Touch9  RTC_GPIO9  XTAL_32K_P GPIO32 | |              | | GPI019  EMAC_TXD0      U0CTS     SPI_MISO
                                                | |              | |
           Touch8  RTC_GPIO8  XTAL_32K_N GPIO33 | |              | | GPI018                 SPI_CLK   HS1_DATA7
                                                | |              | |
           DAC_1   RTC_GPIO6  EMAC_RXD0  GPIO25 | |              | | GPI05   EMAC_RX_CLK    SPI_CS0   HS1_DATA6
                                                | |              | |
           DAC_2   RTC_GPIO7  EMAC_RXD1  GPIO26 |  --------------  | GPI017  EMAC_CLKOUT180 U2_TXD    HS1_DATA5
                                                |                  |
           Touch7  RTC_GPIO17 EMAC_RX_DV GPIO27 |                  | GPI016  EMAC_CLKOUT    U2_RXD    HS1_DATA4
                                                |                  |
          Touch6   RTC_GPIO16 EMAC_TXD2  GPIO14 |                  | GPI04   EMAC_TX_ER     ADC2_CH0  RTCIO10  Touch0
HS2_CLK   SD_CLK   HSPI_CLK   MTMS              |                  |                        HSPIHD   SD_DATA1 HS2_DATA1
          Touch5   RTC_GPIO15 EMAC_TXD3  GPIO12 |                  | GPI02                  ADC2_CH2  RTCIO12  Touch2
HS2_DATA2 SD_DATA2 HSPI_MISO  MTDI              |                  |                        HSPIWP
          Touch4   RTC_GPIO14 EMAC_RX_ER GPIO13 |                  | GPI015  EMAC_RXD3      ADC2_CH3  RTCIO13  Touch3
HS2_DATA3 SD_DATA3 HSPI_MOSI  MTCK              |                  |                        MIDO HSPI_CS0 SD_CMD   HS2_CMD
                                         GND    |                  | GND
                                                |                  |
                                         VIN    | EN   _____  BOOT | VDD 3V3
                                                | [ ] / USB \  [ ] |
                                                 ------------------
```

