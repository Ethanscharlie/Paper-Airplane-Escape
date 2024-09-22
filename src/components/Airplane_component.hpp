#pragma once

#include "Charlie2D.hpp"
#include "Event.hpp"
#include "Vector2f.hpp"

class Airplane : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
  void onDestroy() override;

  void reset();
  Angle getDireciton();

  float force;
  bool launched = false;
  EventIdentifer eventId;
  Vector2f startPos;
};
