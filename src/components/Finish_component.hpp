#pragma once

#include "Charlie2D.hpp"

class Finish : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
};
