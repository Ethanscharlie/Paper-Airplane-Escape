#include "Lever_component.hpp"
#include "components/Airplane_component.hpp"

void Lever::start() {}

void Lever::update(float deltaTime) {

  for (Airplane *airplane : GameManager::getComponents<Airplane>()) {
    Box &airplaneBox = airplane->entity->box;
    if (!airplaneBox.checkCollision(entity->box))
      continue;

    hit = true;
    entity->get<Sprite>()->image = Image("res/images/lever2.png");
    if (gate) {
      gate->toDestroy = true;
      gate = nullptr;
    }
  }
}
