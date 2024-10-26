#include <Adafruit_GFX.h>  
#include <Adafruit_ST7789.h> 
#include "HX711.h"

#include "bitmap/pooolse.h"
#include "bitmap/fuli.h"

#define TFT_CS    10
#define TFT_DC     8
#define TFT_RST    9

#define PS_OUT    4
#define PS_SCK    3

HX711 air_press;
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int i = 0;

const unsigned char* epd_bitmap_array[] = {
    epd_bitmap_pooolse,
    epd_bitmap_fuli
};

void setup() {

  air_press.begin(PS_OUT,PS_SCK);

	tft.init(240, 240, SPI_MODE2);

  tft.setRotation(2);
  tft.setTextWrap(false);
  tft.setTextColor(ST77XX_WHITE);

}

void loop() {

  tft.fillScreen(ST77XX_BLACK);

  if( (i % 2) == 0 ){

    air_press.power_up();

    float unit = air_press.get_value();
    tft.setTextSize(4);
    tft.setCursor(40, 80);
    tft.print(unit / 1000);
    tft.setCursor(40, 120);
    tft.setTextSize(3);
    tft.print("PRESSURE");

    air_press.power_down();

    i++;

    delay(2500);

  }else{

    bool is_end = false;

    switch(i){
      case 1:
        tft.setTextSize(5);
        tft.setCursor(40, 100);
        tft.print("BUBU-1");
        break;
      case 3:
        tft.setTextSize(7);
        tft.setCursor(20, 50);
        tft.print("DONT");
        tft.setCursor(20, 130);
        tft.print("PANIC");
        break;
      case 5:
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
        break;
      default:
        for (byte j = 0; j < (sizeof(epd_bitmap_array) - 2); j++) {
          tft.drawBitmap(0, 0, epd_bitmap_array[j], 240, 240, ST77XX_WHITE);
          if( j < (sizeof(epd_bitmap_array) - 3) ){
            delay(5000);
            tft.fillScreen(ST77XX_BLACK);
          }
        }

        is_end = true;
        break;
    }

    i = is_end ? 0 : (i + 1); 
    delay(5000);

  }

}
