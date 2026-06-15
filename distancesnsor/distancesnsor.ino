int trigPin=6;
int echoPin=5;
int buzzerPin=10;
int pingtravelTime;
int distance;
int LEDpin=13;
void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LEDpin,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,	HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingtravelTime=pulseIn(echoPin,HIGH);
  distance = pingtravelTime * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 15)
  {
    tone(buzzerPin, 1000); 
    digitalWrite(LEDpin,HIGH);
  }
  else
  {
    noTone(buzzerPin);
    digitalWrite(LEDpin,LOW);
  }

  delay(30);
 
  
}