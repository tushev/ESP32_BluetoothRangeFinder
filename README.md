# ESP32 Bluetooth RangeFinder (with OLED 128x32 display)
![](https://img.shields.io/badge/platform-Arduino--ESP32-brightgreen) [![CodeFactor](https://www.codefactor.io/repository/github/tushev/esp32_bluetoothrangefinder/badge)](https://www.codefactor.io/repository/github/tushev/esp32_bluetoothrangefinder)

A **very** simple RSSI Bluetooth monitor. Can be used as an approximate rangefinder.

## Partlist

* ESP32 development board
* SSD1306 128x32 OLED I2C display
* breadboard, wires
* at least 1A power supply + microUSB cable

## Usage

1. Change the address in the sketch:

```cpp
#define ADDRESS_TO_MONITOR "00:00:00:00:00:00"
```
2. Assemble the circuit
3. Compile and upload to ESP32

Current [RSSI value](https://en.wikipedia.org/wiki/Received_signal_strength_indication) will be shown on the display.

> The greater the RSSI value, the stronger the signal. 

> Thus, when an RSSI value is represented in a negative form (e.g. −100), **the closer the value is to 0, the stronger the received signal** has been.


## Circuit

| ESP32 DevBoard  | SSD1306 128x32 OLED I2C display |
| ------------- | ------------- |
| 3V3 | VIN |
| GND | GND |
| GPIO22/SCL | SCL |
| GPIO21/SDA | SDA |

⚠ **Make sure you are using at least 1A power supply + proper microUSB cable.**

Usual USB ports provide currents up to 500mA, which may be not enough.

![Circuit](https://raw.githubusercontent.com/tushev/ESP32_BluetoothRangeFinder_OLED128x32/main/ESP32_BluetoothRangeFinder_OLED128x32_bb.png)

