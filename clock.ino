#include <GyverBME280.h>
GyverBME280 bme;

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
// #define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};


void setup()   {
  Serial.begin(9600);
  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
  // display.setContrast (0); // dim display
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();

  // testdrawtriangle();
  // delay(1000);
  // display.clearDisplay();

  // testfilltriangle();
  // delay(1000);
  // display.clearDisplay();

  // text display tests
  // display.setTextSize(1);
  // display.setTextColor(SH110X_WHITE);
  // display.setCursor(0, 12);
  // display.println("Failure is always an option");
  // display.setTextColor(SH110X_BLACK, SH110X_WHITE); // 'inverted' text
  // display.println(3.141592);
  // display.setTextSize(2);
  // display.setTextColor(SH110X_WHITE);
  // display.print("0x");
  // display.println(0xDEADBEEF, HEX);
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // invert the display
  // display.invertDisplay(true);
  // delay(1000);
  // display.invertDisplay(false);
  // delay(1000);
  // display.clearDisplay();

  //Serial.begin(9600);
  Serial.println("Start");
  
  // запуск датчика и проверка на работоспособность
  if (!bme.begin(0x76)) Serial.println("Error!");

}


void loop() {
  // // температура
  // Serial.print("Temperature: ");
  // Serial.println(bme.readTemperature());
  // // влажность
  // Serial.print("Humidity: ");
  // Serial.println(bme.readHumidity());
  // давление
  // Serial.print("Pressure: ");
  // Serial.println(bme.readPressure());
  // Serial.println();
  // delay(1000);

  display.setCursor(0, 12);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.println(bme.readTemperature());
  display.setTextSize(1);
  display.println("    ");
  // display.setTextColor(SH110X_BLACK, SH110X_WHITE); // 'inverted' text
  display.setTextSize(2);
  display.println(bme.readHumidity());
  display.display();
  delay(1000);
  display.clearDisplay();
}


void testdrawtriangle(void) {
  for (int16_t i = 0; i < min(display.width(), display.height()) / 2; i += 5) {
    display.drawTriangle(display.width() / 2, display.height() / 2 - i,
                         display.width() / 2 - i, display.height() / 2 + i,
                         display.width() / 2 + i, display.height() / 2 + i, SH110X_WHITE);
    display.display();
    delay(1);
  }
}

void testfilltriangle(void) {
  uint8_t color = SH110X_WHITE;
  for (int16_t i = min(display.width(), display.height()) / 2; i > 0; i -= 5) {
    display.fillTriangle(display.width() / 2, display.height() / 2 - i,
                         display.width() / 2 - i, display.height() / 2 + i,
                         display.width() / 2 + i, display.height() / 2 + i, SH110X_WHITE);
    if (color == SH110X_WHITE) color = SH110X_BLACK;
    else color = SH110X_WHITE;
    display.display();
    delay(1);
  }
}
