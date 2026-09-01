int pins[] = {11,10,9,8};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  for (int count = 0; count < 16; count++) {
    for (int bit = 0; bit < 4; bit++) {
      int val = (count >> bit) & 1;
      digitalWrite(pins[bit], val);
    }
    delay(1000);
  }
}