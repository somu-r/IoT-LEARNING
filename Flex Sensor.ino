int flexPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(flexPin);
  Serial.println(sensorValue);
  delay(2000);
}
