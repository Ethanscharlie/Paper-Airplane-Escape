#include "Boost_component.hpp"
#include "components/Airplane_component.hpp"

#define BOOST_FORCE 150

void Boost::start() {}

void Boost::update(float deltaTime) {
  for (Airplane *airplane : GameManager::getComponents<Airplane>()) {
    Box &airplaneBox = airplane->entity->box;
    if (!airplaneBox.checkCollision(entity->box)) {
      hasAirplaneLeft = true;
      continue;
    }

    if (!hasAirplaneLeft)
      continue;

    airplane->force += BOOST_FORCE;
    printf("boost %f\n", airplane->force);
    hasAirplaneLeft = false;
  }
}
