#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
// #include <SPI.h>             // Arduino SPI library

#include "bitmap/pooolse_map.h"
#include "bitmap/dp.h"

// ST7789 TFT module connections
#define TFT_CS    10
#define TFT_DC     8
#define TFT_RST    9

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const unsigned char* epd_bitmap_poolse_arrays[] = {
    epd_bitmap_poolse,
    epd_bitmap_dp
};

int i = 0;

void setup() {
	tft.init(240, 240, SPI_MODE2);
  tft.setRotation(2);
  tft.setTextWrap(false);
}

void loop() {

  tft.fillScreen(ST77XX_BLACK);

  if(i == 2){

  tft.setCursor(20, 80);
  tft.setTextColor(ST77XX_BLACK, ST77XX_WHITE);
  tft.setTextSize(4);
  tft.print(" BUBU 1");

  i = 0;

  }else{

    tft.drawBitmap(0, 0, epd_bitmap_poolse_arrays[i], 240, 240, ST77XX_WHITE);
    i++;

  }

  delay(5000);

}
