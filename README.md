Games for my children on the [Adafruit Trellis](https://www.adafruit.com/product/3938)

## What it does

When the board starts a menu is lit up.  Depending on which light is pushed the board will enter that game.  To return the menu press the upper left and upper right buttons at the same time.

### Games:
 - On/Off - When a button is pressed it turns on to a random color or off
 - Lights Out - any key pressed toggles the on state of that key and the adjacent keys, the objective is to turn all the keys off.

## Building and Installing on the Mac

This assumes you have installed arduino-cli
```
arduino-cli core update-index

arduino-cli core --additional-urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json install adafruit:samd

arduino-cli lib --additional-urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json install "Adafruit NeoTrellis M4 Library"
arduino-cli lib --additional-urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json install "Adafruit Keypad"
arduino-cli lib --additional-urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json install "Adafruit NeoPixel"
arduino-cli lib --additional-urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json install "Adafruit DMA neopixel library"
arduino-cli lib --additional-urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json install MIDIUSB

arduino-cli compile --fqbn adafruit:samd:adafruit_trellis_m4 lights

arduino-cli board list
arduino-cli upload -p /dev/cu.usbmodem1D11301 --fqbn adafruit:samd:adafruit_trellis_m4 lights
```

Listen to serial port
```
cat /dev/cu.usbmodem1D11301
```