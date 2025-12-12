# SierraClock

Arduino-based clock/weather display for Ford Sierra vehicles. Displays temperature and humidity readings on an OLED screen.

## Hardware Requirements

* Arduino Nano/Micro
* BME280/BMP280 temperature/humidity/pressure sensor (I2C address: `0x76`)
* SH1106G OLED display 128x64 (I2C address: `0x3C`)

## I²C Connections

| Pin | Arduino |
|-----|---------|
| SDA | A4      |
| SCL | A5      |

## Required Libraries

* GyverBME280
* Adafruit GFX Library
* Adafruit SH110X

Install via Arduino IDE Library Manager or:

```bash
arduino-cli lib install "GyverBME280" "Adafruit GFX Library" "Adafruit SH110X"
```

## Install arduino-cli

### macOS
```bash
brew install arduino-cli
arduino-cli core install arduino:avr
```

### Linux
```bash
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
arduino-cli core install arduino:avr
```

## Build and Upload

```bash
# Compile
arduino-cli compile --fqbn arduino:avr:nano clock/clock.ino

# Upload (adjust port as needed)
arduino-cli upload -p /dev/cu.wchusbserial110 --fqbn arduino:avr:nano clock/clock.ino
```

## Wiring Diagrams

### BME280/BMP280

![image](https://github.com/adw0rd/SierraClock/assets/546889/73cc272a-2590-42a9-be6c-9fb5b1b6ba04)

### SH110X OLED

![image](https://github.com/adw0rd/SierraClock/assets/546889/10c34021-ec50-4217-a3f8-5bb827581ed5)
