#pragma once
#include <WiFi.h>
#include <WiFiClient.h>
#include "Command.h"
#include "Settings.h"

class RabbitClient {
private:
  WiFiClient client;

public:
  RabbitClient() {}

  bool connectToBroker() {
    return client.connect(RABBITMQ_HOST, RABBITMQ_PORT);

  
  }

  void sendMessage(const Command &cmd) {
    if (!client.connected()) {
      connectToBroker();
    }
    String message = cmd.get();
    client.println(message); // отправка как JSON по TCP
  }

  bool receiveMessage(Command &cmd) {
    if (!client.connected()) {
      if (!connectToBroker()) return false;
    }

    if (client.available()) {
      String line = client.readStringUntil('\n');
      cmd = Command(line);
      return true;
    }

    return false;
  }
};
