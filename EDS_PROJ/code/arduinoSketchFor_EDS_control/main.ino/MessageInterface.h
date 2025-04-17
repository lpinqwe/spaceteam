#pragma once
#include "Command.h"

class MessageInterface {
public:
  Command command;

  MessageInterface(const Command &cmd) : command(cmd) {}
  virtual Command execute() = 0;
};
