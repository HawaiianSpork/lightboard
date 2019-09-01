

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