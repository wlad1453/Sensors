/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor
  This example shows how to take Sensor Events instead of direct readings
  
  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please suppo rt Adafruit and open-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_BMP280.h>
 
Adafruit_BMP280 bmp280;
 
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println(F("BMP280"));

  while (!bmp280.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    delay(500);
  }
}
 
void loop() {
  float temperature = bmp280.readTemperature();
  float pressure = bmp280.readPressure();
  float altitude = bmp280.readAltitude(1013.25);
 
  Serial.print(F("Temperature = "));
  Serial.print(temperature);
  Serial.println(" *C");
 
  Serial.print(F("Pressure = "));
  Serial.print(pressure);
  Serial.println(" Pa");
 
  Serial.print(F("Altitude = "));
  Serial.print(altitude);
  Serial.println(" m");
 
  Serial.println();
  delay(2000);
}
