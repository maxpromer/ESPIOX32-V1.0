
// Display includes
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"


#include "WiFi.h"

// LCD pin config
#define TFT_DC   27
#define TFT_CS   15 
#define TFT_RST  26
#define TFT_LED  25

// Image
extern const uint16_t image_1[];
extern const uint16_t image_2[];
extern const uint16_t image_3[];

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

void drawBitmapColor(const uint16_t *image_data) {
  tft.setAddrWindow(0, 0,  320 - 1, 240 - 1);
  for (unsigned long index=0;index<320*240;index++) {
    tft.pushColor(image_data[index]);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("ESPIOX32 I2C Keypad Test!");

  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH);
  
  tft.begin(40E6); // Setup Display
  tft.setRotation(3);
}

void loop() {
  tft.drawRGBBitmap(0, 0, image_1, 320, 240);
  delay(3000);
  tft.drawRGBBitmap(0, 0, image_2, 320, 240);
  delay(3000);
  tft.drawRGBBitmap(0, 0, image_3, 320, 240);
  delay(3000);
}
