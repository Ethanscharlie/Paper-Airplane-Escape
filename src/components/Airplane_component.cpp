#include "Airplane_component.hpp"
#include "InputManager.hpp"
#include "Vector2f.hpp"

#define INITIAL_FORCE 200
#define TRACTION 10
#define GRAVITY 80
#define ANGLE_MODER_MULTIPLIER 5

void Airplane::start() {
  eventId = Event::addEventListener("LeftMouseButtonDown", [this]() {
    if (launched)
      return;
    launched = true;
    force = INITIAL_FORCE;
  });
}

void Airplane::onDestroy() { Event::removeEventListener(eventId); }

void Airplane::update(float deltaTime) {
  if (launched) {
    Vector2f mousePos = InputManager::getMouseWorldPosition();
    Angle direction;
    direction.lookAt(entity->box.getCenter(), mousePos);

    entity->get<Sprite>()->angle = direction;

    entity->box.position += direction.getVector() * force * deltaTime;
    entity->box.position.y += GRAVITY * deltaTime;

    float differentAngleModifier =
        ANGLE_MODER_MULTIPLIER -
        abs(direction.getVector().x * ANGLE_MODER_MULTIPLIER);

    if (direction.getVector().y > 0) {
      force += GRAVITY * deltaTime;
    } else {
      force -= GRAVITY * deltaTime;
    }

    if (force < 0)
      force = 0;
  }
}
