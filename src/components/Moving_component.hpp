#pragma once

#include "Charlie2D.hpp"
#include "Vector2f.hpp"

class Moving : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

  bool movingToEnd = true;
  bool disable = false;
  float speed = 60.0f;
  const float lowSpeed = 8;
  Vector2f pos1;

  Vector2f pos2;
};
