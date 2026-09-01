int push = 2;
int led = 10;
int count = 0;
int buttonState;
int lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(push, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}
void loop() {
  buttonState = digitalRead(push);
  if (buttonState == LOW && lastButtonState == HIGH){
    count++;
    Serial.print("Count = ");
    Serial.println(count);
    if (count < 6) {
      digitalWrite(led, LOW);
    }
    else if (count == 6) {
      digitalWrite(led, HIGH);
      delay(3000);
      digitalWrite(led, LOW);
      count = 0;
    }
    else {
      digitalWrite(led, LOW);
    }
    delay(200);
  }
  lastButtonState = buttonState;
}