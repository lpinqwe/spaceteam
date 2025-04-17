#ifndef RABBITRABBIT_H
#define RABBITRABBIT_H

#include <WiFi.h>
#include "RabbitMQ.h" // Псевдокод, используется библиотека для работы с RabbitMQ на ESP32
#include "Factory.h"

class RabbitRabbit {
public:
  Factory& factory;

  RabbitRabbit(Factory& fact) : factory(fact) {
    // Инициализация объекта фабрики команд
  }

  void start_consuming() {
    // Здесь должен быть код для подключения к RabbitMQ
    // и получения сообщений

    // Подключение к RabbitMQ
    if (connectToRabbitMQ()) {
      // Если подключение успешно, начинаем получать сообщения
      Serial.println("Connected to RabbitMQ.");
    } else {
      Serial.println("Failed to connect to RabbitMQ.");
    }
  }

  bool connectToRabbitMQ() {
    // Использование библиотеки RabbitMQ для ESP32
    // Например, RabbitMQ клиент на ESP32, его нужно адаптировать под свой код
    return true;  // Заглушка
  }

void callback(String message) {
  // Преобразуем строку в команду
  Command command(message);

  // Получаем объект команды через фабрику
  MessageInterface* handler = factory.createCommand(command);

  if (handler != nullptr) {
    // Выполняем команду
    Command result = handler->execute();

    // Логируем результат
    Serial.println("Result:");
    Serial.println(result.get());
  } else {
    Serial.println("Unknown command: " + command.msgCommand);
  }
}

};

#endif
