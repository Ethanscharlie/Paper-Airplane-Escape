#pragma once

#include "Charlie2D.hpp"

class Lever : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

  bool hit = false;
  Entity* gate = nullptr;
};
