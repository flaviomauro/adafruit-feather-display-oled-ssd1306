/*
 *******************************************************************************
   Description:
   Sample code to show text and draw images in SSD1306 Display.
   GitHub: https://github.com/flaviomauro/adafruit-feather-display-oled-ssd1306
 *******************************************************************************
   Item list:

   - 1 x Adafruit Feather
   - 1 x Micro USB cable
   - 1 x Protoboard
   - 1 x OLED SSD1306 Display
   - 4 x Jumper cables M/M

   External Library list:
   - U8g2lib.h - https://github.com/olikraus/u8g2
 *******************************************************************************
   @author: Flavio H. C. Mauro
   @date:   10-Jan-2017
   LinkedIn: https://br.linkedin.com/in/flaviomauro
 *******************************************************************************
*/

#include <U8g2lib.h>
const int I2C_CLOCK = 4; // OLED SCL connected to GPIO 4/D2
const int I2C_DATA  = 5; // OLED SDA connected to GPIO 5/D1

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, I2C_CLOCK, I2C_DATA);


void setup() {
  u8g2.begin(); // u8g2.begin() will sent the setup/init sequence to the display
}


void loop() {
  u8g2.firstPage();
  do {
    draw();
  } while ( u8g2.nextPage() );
  delay(2000);
}

void draw()
{

  //The famous Hello World!
  u8g2.setFont(u8g2_font_fub11_tf);
  u8g2.drawStr( 5, 57, "Hello World!");
  
  //Draw Temp information
  u8g2.drawStr( 5, 15, "23");
  u8g2.drawCircle(28, 8, 3);
  u8g2.drawStr( 34, 15, "C");

  //Draw Battery information
  u8g2.drawRFrame(105, 3, 20, 12 , 0);
  u8g2.drawBox(125, 6, 2, 6);
  u8g2.drawBox(107, 5, 4, 8);
  u8g2.drawBox(113, 5, 4, 8);
  u8g2.drawBox(119, 5, 4, 8);

  //Draw phone signal information
  u8g2.drawVLine(99, 0, 15);
  u8g2.drawVLine(98, 0, 15);
  u8g2.drawVLine(96, 4, 11);
  u8g2.drawVLine(95, 4, 11);
  u8g2.drawVLine(93, 8, 7);
  u8g2.drawVLine(92, 8, 7);
  u8g2.drawVLine(90, 12, 3);
  u8g2.drawVLine(89, 12, 3);
}
