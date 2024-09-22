#pragma once

#include "Charlie2D.hpp"

class Boost : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

private:
  bool hasAirplaneLeft = true;
};
