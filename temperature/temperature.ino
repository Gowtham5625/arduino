// Include the RemoteXY library
#include <RemoteXY.h> 
#include <DHT.h>

// RemoteXY connection settings 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_WIFI_SSID "your_SSID"
#define REMOTEXY_WIFI_PASSWORD "your_PASSWORD"
#define REMOTEXY_SERVER_PORT 6377

// RemoteXY configuration 
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = 
  { /* Insert the RemoteXY configuration data here */ };

struct {
  char text_1[11];   // Humidity display
} RemoteXY;
#pragma pack(pop)

// DHT Sensor setup
#define DHTPIN 2          // Pin where the DHT sensor is connected
#define DHTTYPE DHT11     // DHT11 or DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  RemoteXY_Init();  // Initialize the RemoteXY interface
  dht.begin();      // Initialize the DHT sensor
}

void loop() {
  RemoteXY_Handler();  // Handle the RemoteXY interface

  // Read humidity
  float h = dht.readHumidity();

  if (isnan(h)) {
    strcpy(RemoteXY.text_1, "Error");  // Display error if sensor fails
  } else {
    char humidityStr[11];
    sprintf(humidityStr, "%.1f%%", h);
    strcpy(RemoteXY.text_1, humidityStr);  // Display humidity in the app
  }

  delay(1000);  // Update rate (once per second)
}
