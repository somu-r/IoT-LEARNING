int ldr = A5;
int relay = 7;

void setup()
{
  pinMode(ldr, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(ldr);

  Serial.print("value = ");
  Serial.println(value);

  if (value < 50)
  {
    digitalWrite(relay, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(relay, LOW);
  }
}