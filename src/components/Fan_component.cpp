#include "Fan_component.hpp"
#include "components/Airplane_component.hpp"

#define FAN_POWER 100

int checkFanDirection(FanDirection fanDirection,
                      float airplaneHorizontalDirection) {
  int directionMultiplier = 0;

  switch (fanDirection) {
  case FanDirection::Right:
    if (airplaneHorizontalDirection > 0) {
      directionMultiplier = 1;
    }
    break;
  case FanDirection::Left:
    if (airplaneHorizontalDirection < 0) {
      directionMultiplier = -1;
    }
    break;
  }

  return directionMultiplier;
}

void Fan::start() {}

void Fan::update(float deltaTime) {
  for (Airplane *airplane : GameManager::getComponents<Airplane>()) {
    Box &airplaneBox = airplane->entity->box;
    if (!airplaneBox.checkCollision(entity->box))
      continue;

    float airplaneHorizontalDirection = airplane->getDireciton().getVector().x;
    float directionMultiplier =
        checkFanDirection(fanDirection, airplaneHorizontalDirection);

    if (directionMultiplier == 0)
      continue;

    airplaneBox.position.x += directionMultiplier * FAN_POWER * deltaTime;
  }
}
