int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println("Light is on");
  //On Led light  
  digitalWrite(ledPin, HIGH);
  //Stay on Led for 1 Seconds
  delay(1000);
  
  Serial.println("Light is off");
  digitalWrite(ledPin, LOW);
  delay(5000);
}
