
#ifndef _ON_OFF_MODE_H_
#define _ON_OFF_MODE_H_

#include <Arduino.h>
#include "Adafruit_NeoTrellisM4.h"

class OnOffMode {

public:
  OnOffMode(Adafruit_NeoTrellisM4 &t);
  void loop();
  void init();

private:
  Adafruit_NeoTrellisM4 *trellis;
  boolean *lit_keys;
  uint32_t Wheel(byte);
};

#endif _ON_OFF_MODE_H_