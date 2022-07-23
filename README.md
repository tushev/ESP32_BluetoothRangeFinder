# ESP32_BluetoothRangeFinder_OLED128x32
A very simple RSSI Bluetooth monitor. Can be used as ~ a rangefinder.

## Partlist

* ESP32 development board
* SSD1306 128x32 OLED I2C display
* breadboard, wires
* at least 1A power supply + microUSB cable

## Usage

1. Change the address in the sketch:

```
#define ADDRESS_TO_MONITOR "00:00:00:00:00:00"
```
2. Assemble the circuit
3. Compile and upload to ESP32

Current RSSI value will be shown on the display.

>  The greater the RSSI value, the stronger the signal. 

> Thus, when an RSSI value is represented in a negative form (e.g. −100), the closer the value is to 0, the stronger the received signal has been.