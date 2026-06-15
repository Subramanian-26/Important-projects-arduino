int sensorPin = A0;
int redLED = 13;
int greenLED = 12;
int sensorValue = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if (sensorValue >600) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  } 
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  delay(1000);
}