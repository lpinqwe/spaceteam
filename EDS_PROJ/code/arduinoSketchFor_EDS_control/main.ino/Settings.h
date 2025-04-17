#pragma once

class Settings {
public:
  static String getHost() { return "192.168.1.100"; }
  static int getPort() { return 5678; }
  static String getSendQueue() { return "getQ1_esp"; }
  static String getReceiveQueue() { return "getQ2_esp"; }
};
