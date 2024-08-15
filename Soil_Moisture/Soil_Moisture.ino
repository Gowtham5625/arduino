const int soilMoisturePin = A0; // Analog pin for soil moisture sensor
int soilMoistureValue = 0; // Variable to store the value from the sensor

void setup() {
  Serial.begin(9600); // Start the serial communication at 9600 baud rate
  pinMode(soilMoisturePin, INPUT); // Set the soil moisture sensor pin as an input
}

void loop() {
  soilMoistureValue = analogRead(soilMoisturePin); // Read the analog value from the sensor
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  delay(2000); // Wait for 2 seconds before taking another reading
}
