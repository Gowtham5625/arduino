// Define pins for IR sensor, seven segment display, and LED indicator
const int irSensorPin = 1;    // Pin connected to IR sensor output
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};  // Pins connected to segments a to g respectively
const int digitPins[] = {9, 10, 11, 12};  // Pins connected to digit 1 to 4 respectively
const int ledPin = 13;         // Built-in LED pin on Arduino

// Seven segment display segment patterns for digits 0 to 9 (common cathode)
const byte segmentPatterns[] = {
  B11111100,   // 0
  B01100000,   // 1
  B11011010,   // 2
  B11110010,   // 3
  B01100110,   // 4
  B10110110,   // 5
  B10111110,   // 6
  B11100000,   // 7
  B11111110,   // 8
  B11110110    // 9
};

// Variables
int count = 0;               // Counter for detected interruptions
bool lastState = LOW;        // Variable to store the previous state of IR sensor

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Set segment and digit pins as OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  // Read the state of the IR sensor
  bool currentState = digitalRead(irSensorPin);

  // Check for state change (object detected)
  if (currentState != lastState && currentState == HIGH) {
    count++;   // Increment count when an object passes through
    Serial.print("Count: ");
    Serial.println(count);
    digitalWrite(ledPin, HIGH);  // Turn on LED to indicate detection
    updateSevenSegment(count);   // Update seven segment display with current count
    delay(100);  // Briefly keep LED on to indicate detection
    digitalWrite(ledPin, LOW);   // Turn off LED
  }

  // Update last state
  lastState = currentState;
  
  delay(50);  // Small delay for stability
}

void updateSevenSegment(int number) {
  // Display the number on the seven segment display
  for (int digit = 0; digit < 4; digit++) {
    int digitValue = number % 10;  // Extract the last digit
    number /= 10;                  // Move to the next digit

    // Activate the digit
    digitalWrite(digitPins[digit], HIGH);

    // Set the segment pins based on the digit value
    for (int segment = 0; segment < 7; segment++) {
      bool segmentState = bitRead(segmentPatterns[digitValue], segment);
      digitalWrite(segmentPins[segment], segmentState);
    }

    // Brief delay to display the digit
    delay(10);

    // Deactivate the digit
    digitalWrite(digitPins[digit], LOW);
  }
}
