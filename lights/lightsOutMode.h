
#ifndef _LIGHTS_OUT_MODE_H_
#define _LIGHTS_OUT_MODE_H_

#include <Arduino.h>
#include "Adafruit_NeoTrellisM4.h"

class LightsOutMode {

public:
  LightsOutMode(Adafruit_NeoTrellisM4 &t);
  void loop();
  void init();

private:
  Adafruit_NeoTrellisM4 *trellis;
  boolean *lit_keys;
  void invertKey(int);
};

#endif _LIGHTS_OUT_MODE_H_