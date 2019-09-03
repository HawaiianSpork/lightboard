#include "Adafruit_NeoTrellisM4.h"

// The NeoTrellisM4 object is a keypad and neopixel strip subclass
// that does things like auto-update the NeoPixels and stuff!
Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();

enum Mode { menu, onOff };

Mode mode = menu;
boolean *lit_keys;

void setup(){
  Serial.begin(115200);
    
  trellis.begin();
  trellis.setBrightness(80);

  lit_keys = new boolean[trellis.num_keys()];

  for (int i=0; i<trellis.num_keys(); i++) {
    lit_keys[i] = false;
  }

  initMenu();
}

void initOnOff() {
  for (int i=0; i<trellis.num_keys(); i++) {
    trellis.setPixelColor(i, 0);
  }
}
  
void loop() {
  trellis.tick();

  if (trellis.isPressed(0) && trellis.isPressed(7)) {
    Serial.println("reset mode");
    initMenu();
    mode = menu;
  }
  switch(mode) {
    case menu : menuLoop(); break;
    case onOff : onOffLoop(); break;
  }
  
  delay(10);
}

void initMenu() {
  for (int i=0; i<trellis.num_keys(); i++) {
    trellis.setPixelColor(i, 0);
  }
  trellis.setPixelColor(0, trellis.Color(255, 0, 0));
}

void menuLoop() {
  keypadEvent e = trellis.read();
  if ((e.bit.EVENT == KEY_JUST_PRESSED) && (e.bit.KEY == 0)) {
    Serial.println("Entered onOff mode");
    initOnOff();
    mode = onOff;
  }
}

void onOffLoop() {
  while (trellis.available()){
    keypadEvent e = trellis.read();
    
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      int key = e.bit.KEY;  // shorthand for what was pressed
      Serial.print(key); Serial.println(" pressed");
      lit_keys[key] = !lit_keys[key];
      if (lit_keys[key]) {
        trellis.setPixelColor(key, Wheel(random(255)));
      } else {
        trellis.setPixelColor(key, 0);
      }      
    }
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return trellis.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return trellis.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return trellis.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
