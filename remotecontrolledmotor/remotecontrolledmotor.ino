#include <IRremote.hpp>   // Include the IR Remote library

int en = 9;
int in1 = 7;
int in2 = 8;
int greenpin=3;
int redpin=11;

int speedmotor ;

int receiverPin = 10;

// Variables
bool motorState = false;     // Motor initially OFF
bool forward = true;         // Initial direction is forward

void setup()
{
  pinMode(en, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(redpin,OUTPUT);

  Serial.begin(9600);

  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);
}

void loop()
{
  // Check if any button on the remote is pressed
  if (IrReceiver.decode())
  {
    
    if (IrReceiver.decodedIRData.decodedRawData == 0xFF00BF00)
    {
      if (motorState == false)
      {
        motorState = true;
        Serial.println("Power on");
      }
      else
      {
        motorState = false;
        Serial.println("Power off");
      }
    }

    
    if (IrReceiver.decodedIRData.decodedRawData == 0xF906BF00)
    {
      forward = true;
      speedmotor=0;
      Serial.println("Forward");
      digitalWrite(greenpin,HIGH);
      digitalWrite(redpin,LOW);
      
    }

    if (IrReceiver.decodedIRData.decodedRawData == 0xFB04BF00)
    {
      forward = false;
      speedmotor=0;
      Serial.println("Backward");
      digitalWrite(greenpin,LOW);
      digitalWrite(redpin,HIGH);
    }

    // ---------------- Speed Up ----------------
    if (IrReceiver.decodedIRData.decodedRawData == 0xF50ABF00)
    {
      Serial.print("Speed = :");
      Serial.println(speedmotor);
      speedmotor = speedmotor + 50;
      

      if (speedmotor > 255)
      {
        speedmotor = 255;
        Serial.print("Speed = :");
        Serial.println(speedmotor);
      }
    }

    // ---------------- Slow Down ----------------
    if (IrReceiver.decodedIRData.decodedRawData == 0xF708BF00)
    {
      Serial.print("Speed = :");
      Serial.println(speedmotor);
      speedmotor = speedmotor - 50;
      
      if (speedmotor < 0)
      {
        speedmotor = 0;
        Serial.print("Speed = :");
        Serial.println(speedmotor);
      }
    }

    // Ready for next button press
    IrReceiver.resume();
  }

  // -------- Motor Control --------

  if (motorState == true)
  {
    analogWrite(en, speedmotor);

    if (forward == true)
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }

    if (forward == false)
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }
  }

  if (motorState == false)
  {
    analogWrite(en, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}