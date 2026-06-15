int en = 9;
int in1 = 7;
int in2 = 8;
int speedmotor=255;
int tiltpin=2;
int tiltvalue;
int LEDpin=5;
void setup() {
  
  pinMode(en, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(tiltpin,INPUT_PULLUP);
  pinMode(LEDpin,OUTPUT);
}

void loop() {
  tiltvalue=digitalRead(tiltpin);
  if(tiltvalue==HIGH){
  // Motor forward
  analogWrite(en,speedmotor);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(LEDpin,HIGH);
  }
  else{
  digitalWrite(en, 0);
  digitalWrite(LEDpin,LOW);
  }

  delay(2000);
}