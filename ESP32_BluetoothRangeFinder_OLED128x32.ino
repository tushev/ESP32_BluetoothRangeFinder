#include <BluetoothSerial.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ADDRESS_TO_MONITOR "00:00:00:00:00:00"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
BluetoothSerial SerialBT;

int lastRSSI = 0;

void btAdvertisedDeviceFound(BTAdvertisedDevice* pDevice) 
{
	//Serial.printf("Found a device asynchronously: %s\n", pDevice->toString().c_str());
  if (pDevice->getAddress().toString() == ADDRESS_TO_MONITOR) {    
    lastRSSI = pDevice->getRSSI();
  }
}

void setup() {
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.setTextColor(WHITE);

  display.clearDisplay();
  display.display();

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("Scan for:");
  display.setTextSize(1);
  display.setCursor(8, 22);
  display.println(ADDRESS_TO_MONITOR);
  display.display();
  delay(3000);

  SerialBT.begin("BTRangeFinder"); //Bluetooth device name
}

void loop() {
  // put your main code here, to run repeatedly:  
  if (SerialBT.discoverAsync(btAdvertisedDeviceFound)) {
    delay(5000);
    SerialBT.discoverAsyncStop();

    display.clearDisplay();    
    display.setTextSize(3);
    display.setCursor(32, 5);
    if (lastRSSI != 0) {
      display.print(lastRSSI);
      lastRSSI = 0;
    } 
    else 
      display.print("--");
    display.display();

  } else {
    Serial.println("Error on discoverAsync f.e. not workin after a \"connect\"");
  }

  delay(500);
}
