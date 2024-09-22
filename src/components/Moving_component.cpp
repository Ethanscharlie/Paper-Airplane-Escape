#include "Moving_component.hpp"

void Moving::start() { pos1 = entity->box.position; }

void Moving::update(float deltaTime) {
  if (disable)
    return;
  Vector2f currentPosition = entity->box.position;
  if (movingToEnd) {
    // Check Past
    Vector2f direction = (pos2 - currentPosition).normalize();
    entity->box.position += direction * speed * deltaTime;

    if (currentPosition.dist(pos2) < lowSpeed)
      movingToEnd = false;
  } else {

    // Check Past
    Vector2f direction = (pos1 - currentPosition).normalize();
    entity->box.position += direction * speed * deltaTime;

    if (currentPosition.dist(pos1) < lowSpeed)
      movingToEnd = true;
  }
}
