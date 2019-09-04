#include "lightsOutMode.h"

LightsOutMode::LightsOutMode(Adafruit_NeoTrellisM4 &t) {
  trellis = &t;
  lit_keys = new boolean[trellis->num_keys()];

  for (int i=0; i<trellis->num_keys(); i++) {
    lit_keys[i] = false;
  }
}

void LightsOutMode::init() {
  for (int i=0; i<trellis->num_keys(); i++) {
    lit_keys[i] = false;
    trellis->setPixelColor(i, 0);
  }

  lit_keys[11] = true;
  trellis->setPixelColor(11, trellis->Color(255, 255, 255));
}

void LightsOutMode::loop() {
  while (trellis->available()){
    keypadEvent e = trellis->read();
    
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      int key = e.bit.KEY;  // shorthand for what was pressed
      Serial.print(key); Serial.println(" pressed");
      invertKey(key);
      if ((key + 1) % 8 != 0) {
        invertKey(key + 1);
      }
      if (key % 8 != 0) {
        invertKey(key - 1);
      }
      if (key >= 8) {
        invertKey(key - 8);
      }
      if (key <= 23) {
        invertKey(key + 8);
      }
    }
  }
}

void LightsOutMode::invertKey(int key) {
    lit_keys[key] = !lit_keys[key];
    if (lit_keys[key]) {
      trellis->setPixelColor(key, trellis->Color(255, 255, 255));
    } else {
      trellis->setPixelColor(key, 0);
    }  
}