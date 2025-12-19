#include <OneButton.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneButton button(A0, true);
#define L1 2
#define L2 3
#define L3 4
int RLY1 = LOW;
int RLY2 = LOW;
int RLY3 = LOW;
void setup() {
  
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("OneButton Demo");
  lcd.setCursor(0, 1);
  lcd.print("Ready");
  button.attachClick(singleClick);
  button.attachDoubleClick(doubleClick);
  button.attachLongPressStop(longClick);
}

void loop() {
  
  button.tick();
  delay(10);
}
void doubleClick() {
  RLY1 = !RLY1;
  digitalWrite(L1, RLY1); 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Double Click");
  lcd.setCursor(0, 1);
  lcd.print("Relay1: ");
  lcd.print(RLY1 ? "ON " : "OFF");
  delay(250);
}
void singleClick() {
  RLY2 = !RLY2;
  digitalWrite(L2, RLY2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Single Click");
  lcd.setCursor(0, 1);
  lcd.print("Relay2: ");
  lcd.print(RLY2 ? "ON " : "OFF");
  delay(250);
}

void longClick() {
  RLY3 = !RLY3;
  digitalWrite(L3, RLY3);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Long Press");
  lcd.setCursor(0, 1);
  lcd.print("Relay3: ");
  lcd.print(RLY3 ? "ON " : "OFF");
  delay(250);
}
