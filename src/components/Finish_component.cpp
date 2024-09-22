#include "Finish_component.hpp"
#include "components/Airplane_component.hpp"
#include "util.hpp"

void Finish::start() {}

void Finish::update(float deltaTime) {
  for (Airplane *airplane : GameManager::getComponents<Airplane>()) {
    Box &airplaneBox = airplane->entity->box;
    if (!airplaneBox.checkCollision(entity->box)) {
      continue;
    }

    nextLevel();
  }
}
