#pragma once
#include <ArduinoJson.h>
struct Command {
  String msgID;
  String msgPayload;
  String msgCommand;

  Command() {}

  Command(String jsonStr) {
    StaticJsonDocument<256> doc;
    DeserializationError error = deserializeJson(doc, jsonStr);
    if (!error) {
      msgCommand = doc["msgCommand"] | "";
      msgID = doc["msgID"] | "";
      msgPayload = doc["msgPayload"] | "";
    }
  }

  String get()const {
    StaticJsonDocument<256> doc;
    doc["msgID"] = msgID;
    doc["msgPayload"] = msgPayload;
    doc["msgCommand"] = msgCommand;
    String output;
    serializeJson(doc, output);
    return output;
  }
};
