#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("entire your message!");
  // set up LCD column and row numbers
  lcd.begin(16, 2);
  lcd.print("hello world!");
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    if (message.length() > 0) {
      Serial.println(message);
      lcd.clear();
      lcd.print(message);
    }
  }
}
