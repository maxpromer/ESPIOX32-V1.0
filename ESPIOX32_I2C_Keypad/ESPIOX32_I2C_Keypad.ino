
// Display includes
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// I2C Keypad includes
#include <i2c_keypad.h>

// LCD pin config
#define TFT_DC   27
#define TFT_CS   15 
#define TFT_RST  26

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);
I2CKEYPAD key(22, 19);

void setup() {
  Serial.begin(115200);
  Serial.println("ESPIOX32 I2C Keypad Test!");
  
  tft.begin(240E6); // Setup Display
  tft.setRotation(3);
  
  key.begin(0x20, 100); // Setup I2C Keypad

  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(3);
  tft.println("Ready!");

  tft.setTextColor(ILI9341_RED);
  key.on(PRESS, [](char key) { // void on(KEYPAD_EVENT event, KeypadEventCallback callback) ;
    Serial.print("PRESS: ");
    Serial.println(key);

    tft.print(key);
  });
}

void loop() {
  key.scand();
}
