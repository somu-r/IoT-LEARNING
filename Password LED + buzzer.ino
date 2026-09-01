String pass = "SOMU";
int ledPin = 10;
int buzzerPin = 8;
int attempts = 0;
int maxAttempts = 4;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, LOW);
  Serial.begin(9600);

  Serial.println("Enter password:");
}

void loop() {

  if (Serial.available() > 0) {

    String input = Serial.readStringUntil('\n');
    input.trim();

    // Check password
    if (input == pass) {

      Serial.println("Correct password!");

      // LED blink + buzzer beep
      for (int i = 0; i < 5; i++) {

        digitalWrite(ledPin, HIGH);

        tone(buzzerPin, 1000);  // 1000 Hz beep
        delay(200);

        noTone(buzzerPin);
        digitalWrite(ledPin, LOW);

        delay(300);
      }

      // Reset attempts
      attempts = 0;

      Serial.println("Enter password again:");
    }

    else {

      attempts++;

      Serial.println("Wrong password. Please try again.");

      // Wrong password: 2 beeps
      for (int i = 0; i < 2; i++) {
        tone(buzzerPin, 500);
        delay(200);
        noTone(buzzerPin);
        delay(200);
      }

      // After 4 wrong attempts
      if (attempts >= maxAttempts) {

        Serial.println("Too many wrong attempts!");
        Serial.println("System locked for 1 minute.");

        // Alarm
        for (int i = 0; i < 5; i++) {
          digitalWrite(ledPin, HIGH);
          tone(buzzerPin, 1500);
          delay(300);

          digitalWrite(ledPin, LOW);
          noTone(buzzerPin);
          delay(300);
        }

        // Lock system for 1 minute
        delay(6000);

        Serial.println("System unlocked.");
        Serial.println("Please enter password:");

        attempts = 0;
      }

      else {

        Serial.print("Attempts remaining: ");
        Serial.println(maxAttempts - attempts);

        Serial.println("Please try again:");
      }
    }
  }
}
