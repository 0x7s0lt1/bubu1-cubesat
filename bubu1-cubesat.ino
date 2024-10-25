#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include "HX711.h"

#include "bitmap/pooolse_map.h"

// ST7789 TFT module connections
#define TFT_CS    10
#define TFT_DC     8
#define TFT_RST    9

// Pressure sensor connections
#define PS_OUT    4
#define PS_SCK    3

HX711 air_press;
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int i = 0;

const unsigned char* epd_bitmap_poolse_arrays[] = {
    epd_bitmap_poolse
};

void setup() {

  air_press.begin(PS_OUT,PS_SCK);
  //air_press.set_scale(2280.f);  // this value is obtained by calibrating the scale with known weights; see the README for details
  //air_press.set_scale(2280.f);
  //air_press.tare();    

	tft.init(240, 240, SPI_MODE2);

  tft.setRotation(2);
  tft.setTextWrap(false);
  tft.setTextColor(ST77XX_WHITE);


}

void loop() {

  tft.fillScreen(ST77XX_BLACK);

  if( (i % 2) == 0 ){

    air_press.power_up();

    float unit = air_press.get_value();  //parameter: 10 if average
    tft.setTextSize(4);
    tft.setCursor(30, 80);
    tft.print(unit / 1000);
    tft.setCursor(30, 120);
    tft.setTextSize(3);
    tft.print("Pressure");

    air_press.power_down();

    i++;

  }else{


    if(i == 1){

    tft.setTextSize(5);
    tft.setCursor(40, 100);
    tft.print("BUBU-1");

    i++;

    }
    else if(i == 3){

      tft.setTextSize(7);
      tft.setCursor(20, 50);
      tft.print("DONT");
      tft.setCursor(20, 130);
      tft.print("PANIC");


      i++;
    }
    else if(i == 5){

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

      i++;
    }
    else{

      tft.drawBitmap(0, 0, epd_bitmap_poolse_arrays[i], 240, 240, ST77XX_WHITE);
      i = 0;

    }


  }


  delay(5000);

}
