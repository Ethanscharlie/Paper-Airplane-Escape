#pragma once

#include "Charlie2D.hpp"

class ClickToScene : public Component {
public:
  void start() override;
  void update(float deltaTime) override;

  std::function<void()> onClick;
};
