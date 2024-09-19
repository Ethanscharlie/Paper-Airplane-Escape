#pragma once

#include "Charlie2D.hpp"
#include "Event.hpp"

class Airplane : public Component {
public:
  void start() override;
  void update(float deltaTime) override;
  void onDestroy() override;

private:
  float force;
  bool launched = false;
  EventIdentifer eventId;
};
