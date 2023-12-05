#include <Wire.h>

#define TEMPERATURE_SENSOR A0
#define VENTILATOR_PIN 8
#define LED_PIN 13
#define BUZZER_PIN 9

void setup() {
  pinMode(VENTILATOR_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int temperatura = analogRead(TEMPERATURE_SENSOR);
  float temperaturaCelsius = temperatura * 0.48828125;

  Serial.print("Temperatura: ");
  Serial.print(temperaturaCelsius);
  Serial.println(" C");

  if (temperaturaCelsius >= 30) {
    digitalWrite(VENTILATOR_PIN, HIGH); // Liga o ventilador
  } else {
    digitalWrite(VENTILATOR_PIN, LOW); // Desliga o ventilador
  }

  if (temperaturaCelsius > 50) {
    digitalWrite(LED_PIN, HIGH); // Liga o LED vermelho
    tone(BUZZER_PIN, 1000); // Liga a buzina
  } else {
    digitalWrite(LED_PIN, LOW); // Desliga o LED vermelho
    noTone(BUZZER_PIN); // Desliga a buzina
  }

  delay(1000); // Aguarda um segundo antes da próxima leitura
}
