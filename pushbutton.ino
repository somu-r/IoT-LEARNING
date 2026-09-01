int push = 2;
int led = 10;

void setup() {
  Serial.begin(9600);
  pinMode(push, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int value = digitalRead(push);
  Serial.println(value);

  if (value == HIGH) {
    digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }

  delay(100);
}