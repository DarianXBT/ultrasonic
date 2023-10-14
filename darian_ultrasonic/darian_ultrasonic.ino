// Ultraschall Sensor Pin-Konfiguration
const int trigPin = 8;
const int echoPin = 7;

void setup() {
  // Seriellen Monitor aktivieren
  Serial.begin(9600);
  
  // Konfiguration der Pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger-Impuls senden
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Echo-Zeit messen mit Mikrosekunden-Präzision
  unsigned long duration = pulseIn(echoPin, HIGH);
  
  // Berechnung der Entfernung in Zentimetern mit höherer Genauigkeit
  // Schallgeschwindigkeit in Luft bei 20°C: 343,5 m/s oder 0,03435 cm/µs
  float distance_cm = (duration * 0.03435) / 2.0;
  
  // Ausgabe der Entfernung im seriellen Monitor mit 2 Dezimalstellen
  Serial.print("Entfernung: ");
  Serial.print(distance_cm, 2);
  Serial.println(" cm");
  
  // Warte 1 Sekunde, bevor die nächste Messung durchgeführt wird
  delay(1000);
}
