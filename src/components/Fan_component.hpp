#pragma once

#include "Charlie2D.hpp"

enum class FanDirection { Right, Left };

class Fan : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

  FanDirection fanDirection;
};
