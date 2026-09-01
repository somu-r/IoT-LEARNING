String str1, str2;
void setup() {
  Serial.begin(9600);
  Serial.println("Enter first string:");
  while (Serial.available() == 0);
  str1 = Serial.readStringUntil('\n');
  Serial.println("Enter second string:");
  while (Serial.available() == 0);
  str2 = Serial.readStringUntil('\n');
  Serial.println(str1);
  Serial.println(str2);
}
void loop() {
}
