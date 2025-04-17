#include <WiFi.h>
#include "Factory.h"
#include "RabbitRabbit.h"
#include "Settings.h"

// Создание объектов
Factory factory;
RabbitRabbit rabbitReader(factory);

void setup() {
  // Инициализация сериализации
  Serial.begin(115200);
  delay(1000);

  // Подключение к Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  rabbitReader.start_consuming(); 
  Serial.println("RabbitMQ Consumer Started");
}

void loop() {
  delay(1000); 
}
