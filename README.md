

```
arduino-cli core update-index

# duemilanove
arduino-cli compile --fqbn arduino:avr:diecimila lights

arduino-cli board list
arduino-cli upload -p /dev/cu.usbserial-A9007VOG --fqbn arduino:avr:diecimila lights
```