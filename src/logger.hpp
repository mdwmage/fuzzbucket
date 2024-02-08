//
// Created by phoenix on 07/02/24.
//

#ifndef FUZZBUCKET_LOGGER_H
#define FUZZBUCKET_LOGGER_H

#include <vector>

#include "fstream"
#include "iostream"

using namespace std;

namespace UI {

class Transport {
 public:
  virtual void send(const char* message) {
    throw "Cannot log to empty Transport";
  };
};

class Console : public Transport {
 public:
  void send(const char* message) override { printf("%s\n", message); };
};

class File : public Transport {
  ofstream target;

 public:
  File(const char* target) { this->target.open(target); }
  void send(const char* message) override { target << message << endl; };
  void close() { target.close(); }
};

class Logger {
  vector<UI::Transport*> Targets;
  void send(const string& message, const string& type) {
    for (auto& target : Targets) {
      target->send((type + "    " + message).c_str());
    }
  }

 public:
  void addTransport(UI::Transport* target) { Targets.push_back(target); }
  explicit Logger(Transport* targets[]) {
    for (int i = 0; i < sizeof(targets); i++) {
      addTransport(targets[i]);
    }
  }
  void info(const char* message) { send(message, "INFO"); }
  void warn(const char* message) { send(message, "WARN"); }
};

}  // namespace UI

#endif  // FUZZBUCKET_LOGGER_H
