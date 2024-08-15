const int irSensorPin = 2; // Digital pin for IR sensor
int irSensorValue = 0; // Variable to store the value from the sensor

void setup() {
  Serial.begin(9600); // Start the serial communication at 9600 baud rate
  pinMode(irSensorPin, INPUT); // Set the IR sensor pin as an input
}

void loop() {
  irSensorValue = digitalRead(irSensorPin); // Read the digital value from the sensor
  if (irSensorValue == LOW) {
    Serial.println("Obstacle detected!");
  } else {
    Serial.println("No obstacle.");
  }
  delay(500); // Wait for 500 milliseconds before taking another reading
}
