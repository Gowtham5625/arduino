// Seven Segment Display pins
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};
// IR Sensor pin
const int irSensorPin = 9;
// Buzzer pin
const int buzzerPin = 10;

// Segment values for numbers 0 to 9
const byte numbers[10] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111  // 9
};

int count = 0;

void setup() {
  // Initialize segment pins
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW); // Turn off all segments
  }
  // Initialize IR sensor pin
  pinMode(irSensorPin, INPUT);
  // Initialize buzzer pin
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); // Turn off buzzer
}

void loop() {
  // Check if IR sensor is triggered
  if (digitalRead(irSensorPin) == HIGH) {
    delay(100); // Debounce delay
    count = (count + 1) % 10; // Increment count and wrap around after 9

    // Display the count on the seven-segment display
    displayNumber(count);

    // If count is 9, sound the buzzer
    if (count == 9) {
      digitalWrite(buzzerPin, HIGH); // Turn on buzzer
      delay(1000); // Buzzer sound duration
      digitalWrite(buzzerPin, LOW); // Turn off buzzer
    }

    // Wait until IR sensor is not triggered
    while (digitalRead(irSensorPin) == HIGH) {
      delay(10);
    }
  }
}

void displayNumber(int num) {
  // Turn off all segments
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW);
  }

  // Turn on segments for the given number
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(numbers[num], i));
  }
}
