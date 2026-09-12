// Зуммер подключён к порту 10
int buzzer = 10;

void setup() {
  // Светодиоды подключены к портам 1–5
  for (int pin = 1; pin <= 5; pin++) {
    pinMode(pin, OUTPUT);
  }

  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Зелёные светодиоды и первый звук
  greenOn();
  sound(300, 400);

  // Красные светодиоды и второй звук
  redOn();
  sound(500, 400);

  // Зелёные светодиоды и третий звук
  greenOn();
  sound(700, 250);

  // Красные светодиоды и четвёртый звук
  redOn();
  sound(500, 500);

  delay(500);
}

void greenOn() {
  allOff();
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
}

void redOn() {
  allOff();
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
}

void allOff() {
  for (int pin = 1; pin <= 5; pin++) {
    digitalWrite(pin, LOW);
  }
}

void sound(int frequency, int time) {
  tone(buzzer, frequency);
  delay(time);
  noTone(buzzer);
  allOff();
  delay(100);
}