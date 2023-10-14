const int trigPin = 8;
const int echoPin = 7;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  unsigned long duration = pulseIn(echoPin, HIGH);
  
  float distance_cm = (duration * 0.03435) / 2.0;
  
  Serial.print("Entfernung: ");
  Serial.print(distance_cm, 2);
  Serial.println(" cm");
  
  delay(1000);
}
