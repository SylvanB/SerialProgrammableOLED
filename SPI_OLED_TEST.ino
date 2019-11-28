#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>


U8G2_SSD1327_WS_128X128_1_4W_SW_SPI u8g2(U8G2_R0, 6, 7, 5, 4, 3);

void setup(void) {
  Serial.begin(9600);
  u8g2.begin();
}

void loop(void) {
  const char* p2;
  String test = "";
  if (Serial.available() > 0) {
      Serial.print("Input now");
      // read the incoming byte:
      test = Serial.readString();
      int test_size = test.length();
      Serial.print(test_size);
      Serial.print("\n");
      char* p = (char*) malloc(test_size);

      for (int i = 0; i < test.length() - 1; ++i) {
        p[i] = test[i];
      }
      
      // say what you got:
      Serial.print("I received: ");
      Serial.println(test);
      
      //p2 = (const char*) malloc(test_size);
      p2 = p;
      Serial.println(p2);
      free(p);
    }  
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,24, "wat");
    u8g2.drawStr(0, 50, "lmao");
    u8g2.drawStr(0,80, p2);
  } while ( u8g2.nextPage() );
  //free(p2);
  
}
