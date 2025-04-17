// Factory.h
#pragma once
#include <map>
#include "MessageInterface.h"
#include "TestCommand.h"

class Factory {
public:
  std::map<String, MessageInterface*> commands;

  Factory() {
    commands["test"] = nullptr; 
    commands["getxml"] = nullptr;  
    commands["getjson"] = nullptr;  
  }

  MessageInterface* createCommand(const Command &cmd) {
    String cmdType = cmd.msgCommand;
    cmdType.toLowerCase();

    if (cmdType == "test") {
      return new TestCommand(cmd); 
    } else {
      return nullptr;
    }
  }
};
