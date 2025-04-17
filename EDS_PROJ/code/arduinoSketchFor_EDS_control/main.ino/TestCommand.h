#pragma once
#include "MessageInterface.h"

class TestCommand : public MessageInterface {
public:
  TestCommand(const Command &cmd) : MessageInterface(cmd) {
    Serial.println("TestCommand initialized:");
    Serial.println(cmd.get());
  }

  Command execute() override {
    command.msgPayload = "<data>This is test payload</data>";
    return command;
  }
};
