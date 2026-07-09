#include <IRremote.hpp>

int redPin = 11;
int greenPin = 9;
int bluePin = 10;

int receiverPin = 5;

bool power = false;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);

  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);
}

void loop()
{
  if (IrReceiver.decode())
  {

    // ---------------- Power Button ----------------
    if (IrReceiver.decodedIRData.decodedRawData == 0xFF00BF00)
    {
      power = true;

      // White
      analogWrite(redPin, 255);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 255);

      Serial.println("Power On");
    }

    // ---------------- FUNC/STOP Button ----------------
    if (IrReceiver.decodedIRData.decodedRawData == 0xFD02BF00)
    {
      power = false;

      // OFF
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);

      Serial.println("OFF");
    }

    // --------- Colour Buttons Work Only When Power is ON ---------
    if (power == true)
    {
      // ---------------- Button 1 : Red ----------------
      if (IrReceiver.decodedIRData.decodedRawData == 0xEF10BF00)
      {
        analogWrite(redPin, 255);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);

        Serial.println("Red");
      }

      // ---------------- Button 0 : White ----------------
      if (IrReceiver.decodedIRData.decodedRawData == 0xF30CBF00)
      {
        analogWrite(redPin, 255);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 255);

        Serial.println("White");
      }

      // ---------------- Button 2 : Green ----------------
      if (IrReceiver.decodedIRData.decodedRawData == 0xEE11BF00)
      {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);

        Serial.println("Green");
      }

      // ---------------- Button 3 : Blue ----------------
      if (IrReceiver.decodedIRData.decodedRawData == 0xED12BF00)
      {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255);

        Serial.println("Blue");
      }

      // ---------------- Button 4 : Purple ----------------
      if (IrReceiver.decodedIRData.decodedRawData == 0xEB14BF00)
      {
        analogWrite(redPin, 255);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255);

        Serial.println("Purple");
      }

      // ---------------- Button 5 : Cyan ----------------
      if (IrReceiver.decodedIRData.decodedRawData == 0xEA15BF00)
      {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 255);

        Serial.println("Cyan");
      }

      // ---------------- Button 6 : Yellow ----------------
      if (IrReceiver.decodedIRData.decodedRawData == 0xE916BF00)
      {
        analogWrite(redPin, 255);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);

        Serial.println("Yellow");
      }
    }

    IrReceiver.resume();
  }
}