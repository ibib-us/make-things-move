#pragma once

#include <unordered_map>
#include <functional>

class Controller {
public:
  Controller();
  void init(const std::string& robotName);
  void update();
  void registerCallback(const std::string& buttonName, std::function<void(bool)> callback);

private:
  struct ButtonData {
    bool state;
    std::function<void(bool)> callback;
  };
  std::unordered_map<std::string, ButtonData> buttonStates;
  void setButtonState(const std::string& buttonName, bool newState);
  static void defaultCallback(bool newState);
};