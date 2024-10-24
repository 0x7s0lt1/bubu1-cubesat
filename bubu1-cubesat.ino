#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
// #include <SPI.h>             // Arduino SPI library

#include "bitmap/pooolse_map.h"
//#include "bitmap/dp.h"

// ST7789 TFT module connections
#define TFT_CS    10
#define TFT_DC     8
#define TFT_RST    9

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const unsigned char* epd_bitmap_poolse_arrays[] = {
    epd_bitmap_poolse
};

int i = 0;

void setup() {
	tft.init(240, 240, SPI_MODE2);
  tft.setRotation(2);
  tft.setTextWrap(false);

  tft.setTextColor(ST77XX_BLACK, ST77XX_WHITE);
}

void loop() {

  tft.fillScreen(ST77XX_BLACK);

  if(i == 1){

  tft.setTextSize(5);
  tft.setCursor(20, 80);
  tft.print("BUBU-1");

  i++;

  }
  else if(i == 2){

    tft.setTextSize(7);
    tft.setCursor(20, 40);
    tft.print("DONT");
    tft.setCursor(20, 120);
    tft.print("PANIC");


    i++;
  }
  else if(i == 3){

    tft.setTextSize(3);
    tft.setCursor(10, 20);
    tft.print("Luck is");
    tft.setCursor(10, 60);
    tft.print("when");
    tft.setCursor(10, 100);
    tft.print("preparation");
    tft.setCursor(10, 140);
    tft.print("meets");
    tft.setCursor(10, 180);
    tft.print("opportunity.");
    //Luck is when preparation meets opportunity

    i = 0;
  }
  else{

    tft.drawBitmap(0, 0, epd_bitmap_poolse_arrays[i], 240, 240, ST77XX_WHITE);
    i++;

  }

  delay(5000);

}
