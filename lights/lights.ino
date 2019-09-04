#include "Adafruit_NeoTrellisM4.h"
#include "lightsOutMode.h"
#include "onOffMode.h"

// The NeoTrellisM4 object is a keypad and neopixel strip subclass
// that does things like auto-update the NeoPixels and stuff!
Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();

enum Mode { menu, lightsOut, onOff };

Mode mode = menu;

OnOffMode onOffMode = OnOffMode(trellis);
LightsOutMode lightsOutMode = LightsOutMode(trellis);

void setup(){
  Serial.begin(115200);
    
  trellis.begin();
  trellis.setBrightness(80);

  initMenu();
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
    case lightsOut: lightsOutMode.loop(); break;
    case onOff : onOffMode.loop(); break;
  }
  
  delay(10);
}

void initMenu() {
  for (int i=0; i<trellis.num_keys(); i++) {
    trellis.setPixelColor(i, 0);
  }
  trellis.setPixelColor(0, trellis.Color(255, 0, 0));
  trellis.setPixelColor(8, trellis.Color(255, 0, 0));
}

void menuLoop() {
  keypadEvent e = trellis.read();
  if ((e.bit.EVENT == KEY_JUST_PRESSED) && (e.bit.KEY == 0)) {
    Serial.println("Entered onOff mode");
    onOffMode.init();
    mode = onOff;
  }
  if ((e.bit.EVENT == KEY_JUST_PRESSED) && (e.bit.KEY == 8)) {
    Serial.println("Entered lightsOut mode");
    lightsOutMode.init();
    mode = lightsOut;
  }
}