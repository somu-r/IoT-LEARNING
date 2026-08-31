int pot = A0;
int led = 9;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}
void loop() {
  int value = analogRead(pot);
  int new_value= value/4;
  Serial.print(" Value:");
  Serial.println(new_value);
  analogWrite(9, new_value);
}