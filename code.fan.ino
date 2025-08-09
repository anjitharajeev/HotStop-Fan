#include <DHT.h>

#define DHTPIN 2          // DHT sensor connected to pin 2
#define DHTTYPE DHT11     // Use DHT11 or DHT22
#define FAN_PIN 3         // Fan control pin via relay

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();  // Celsius
  
  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  if (temp >= 30) {
    // You're hot → turn OFF fan (useless behavior)
    digitalWrite(FAN_PIN, LOW);  // Fan off (relay inactive)
    Serial.println("You're hot → Fan is OFF");
  } else {
    // You're cool → turn ON fan (makes no sense!)
    digitalWrite(FAN_PIN, HIGH); // Fan on
    Serial.println("You're cool → Fan is ON");
  }

  delay(000);  // Wait 2 seconds
}


