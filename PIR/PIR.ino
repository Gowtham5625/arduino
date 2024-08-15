const int pirSensorPin = 2; // Digital pin for PIR sensor
int pirSensorValue = 0; // Variable to store the value from the sensor

void setup() {
  Serial.begin(9600); // Start the serial communication at 9600 baud rate
  pinMode(pirSensorPin, INPUT); // Set the PIR sensor pin as an input
}

void loop() {
  pirSensorValue = digitalRead(pirSensorPin); // Read the digital value from the sensor
  if (pirSensorValue == HIGH) {
    Serial.println("Motion detected!");
  } else {
    Serial.println("No motion.");
  }
  delay(500); // Wait for 500 milliseconds before taking another reading
}
