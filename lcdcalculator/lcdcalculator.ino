#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int db4 = 9;
int db5 = 10;
int db6 = 11;
int db7 = 12;

LiquidCrystal lcd(rs, en, db4, db5, db6, db7);

float num1, num2, result;
char op;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  lcd.print("LCD Calculator");
  delay(2000);
  lcd.clear();

  Serial.println("Enter: num1 operator num2");
  Serial.println("Example: 10 + 5");
  lcd.println("Enter: num1 operator num2");
  delay(2000);
  lcd.clear();
  lcd.println("Example: 10 + 5");
  delay(2000);
  lcd.clear();
             
}

void loop() {

  if (Serial.available() > 0) {

    num1 = Serial.parseFloat();
    op = Serial.read();
    num2 = Serial.parseFloat();

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(num1);
    lcd.print(op);
    lcd.print(num2);

    switch (op) {

      case '+':
        result = num1 + num2;
        break;

      case '-':
        result = num1 - num2;
        break;

      case '*':
        result = num1 * num2;
        break;

      case '/':
        if (num2 != 0)
          result = num1 / num2;
        else {
          lcd.setCursor(0, 1);
          lcd.print("Math Error");
          return;
        }
        break;

      default:
        lcd.setCursor(0, 1);
        lcd.print("Invalid Operator ");
        return;
    }

    lcd.setCursor(0, 1);
    lcd.print("=");
    lcd.print(result);
  }
}