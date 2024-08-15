#include <Wire.h>
#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2           // Pin connected to the DATA pin of the DHT sensor
#define DHTTYPE DHT11      // DHT 11 or DHT 22, depending on your sensor

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7,8,9,10,11,12);  // Change 0x27 to the correct I2C address of your LCD

void setup() {
  lcd.begin();            // Initialize the LCD
  lcd.backlight();        // Turn on the LCD backlight
  dht.begin();            // Initialize the DHT sensor
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature in Celsius

  if (isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Reading");
    lcd.setCursor(0, 1);
    lcd.print("Temperature!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print((char)223); // Degree symbol
    lcd.print("C");
  }

  delay(2000);  // Update every 2 seconds
}