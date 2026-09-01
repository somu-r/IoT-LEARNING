int led = 8;

int TOTAL_TIME;
float duty_cycle;
int ontime;
int offtime;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  Serial.println("Enter Total Time:");
  while (Serial.available() == 0) {}
  TOTAL_TIME = Serial.parseInt();

  Serial.println("Enter Duty Cycle (%):");
  while (Serial.available() == 0) {}
  duty_cycle = Serial.parseInt();

  duty_cycle = duty_cycle / 100.0;

  ontime = duty_cycle * TOTAL_TIME;
  offtime = TOTAL_TIME - ontime;

  Serial.println(ontime);
  Serial.println(offtime);
}

void loop()
{
  digitalWrite(led, HIGH);
  delay(ontime);

  digitalWrite(led, LOW);
  delay(offtime);
}