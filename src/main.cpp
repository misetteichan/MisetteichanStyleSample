#include <MisetteichanStyle.h>

int8_t white, yellow;
bool flag = true;

void setup() {
  M5.begin();
  white = M5.getPin(mstc_style::port::a_outside);
  yellow = M5.getPin(mstc_style::port::a_inside);
  pinMode(white, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  const auto begin = millis();
  if (flag) {
    digitalWrite(white, HIGH);
    // Yellowだけブリンクするよ
    for (auto i = 0; i < 4; ++i) {
      digitalWrite(yellow, i % 2 == 0 ? HIGH : LOW);
      delay(100);
    }
    digitalWrite(yellow, HIGH);

  } else {
    digitalWrite(white, LOW);
    digitalWrite(yellow, LOW);
  }
  while (millis() - begin < 500) {
    delay(1);
  }
  flag = !flag;
}
