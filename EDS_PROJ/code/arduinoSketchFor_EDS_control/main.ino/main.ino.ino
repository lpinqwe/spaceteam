#include <Arduino.h>
#include "TestCommand.h"

void setup() {
  Serial.begin(115200);

  String inputJson = "{\"msgID\":\"123\",\"msgCommand\":\"test\",\"msgPayload\":\"original\"}";

  Command inputCommand(inputJson);

  TestCommand test(inputCommand);
  Command result = test.execute();

  Serial.println("Result command:");
  Serial.println(result.get());
}

void loop() {
}
