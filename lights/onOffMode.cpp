#include "onOffMode.h"

OnOffMode::OnOffMode(Adafruit_NeoTrellisM4 &t) {
  trellis = &t;
  lit_keys = new boolean[trellis->num_keys()];

  for (int i=0; i<trellis->num_keys(); i++) {
    lit_keys[i] = false;
  }
}

void OnOffMode::init() {
  for (int i=0; i<trellis->num_keys(); i++) {
    trellis->setPixelColor(i, 0);
  }
}

void OnOffMode::loop() {
  while (trellis->available()){
    keypadEvent e = trellis->read();
    
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      int key = e.bit.KEY;  // shorthand for what was pressed
      Serial.print(key); Serial.println(" pressed");
      lit_keys[key] = !lit_keys[key];
      if (lit_keys[key]) {
        trellis->setPixelColor(key, Wheel(random(255)));
      } else {
        trellis->setPixelColor(key, 0);
      }      
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t OnOffMode::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return trellis->Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return trellis->Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return trellis->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}