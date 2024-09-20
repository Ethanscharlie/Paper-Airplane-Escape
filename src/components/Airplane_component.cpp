#include "Airplane_component.hpp"
#include "InputManager.hpp"
#include "SolidBody.hpp"
#include "Vector2f.hpp"

// #define INITIAL_FORCE 200
// #define TRACTION 10
// #define GRAVITY 80
// #define ANGLE_MODER_MULTIPLIER 5
#define INITIAL_FORCE 150
#define TRACTION 70
#define GRAVITY 40
#define ANGLE_MODER_MULTIPLIER 2

void Airplane::start() {
  eventId = Event::addEventListener("LeftMouseButtonDown", [this]() {
    if (launched)
      return;
    launched = true;
    force = INITIAL_FORCE;
  });

  startPos = entity->box.position;
}

void Airplane::onDestroy() { Event::removeEventListener(eventId); }

void Airplane::update(float deltaTime) {
  if (!launched)
    return;

  Angle direction = getDireciton();

  entity->get<Sprite>()->angle = direction;

  entity->box.position += direction.getVector() * force * deltaTime;
  entity->box.position.y += GRAVITY * deltaTime;

  float differentAngleModifier =
      ANGLE_MODER_MULTIPLIER -
      abs(direction.getVector().x * ANGLE_MODER_MULTIPLIER);

  if (direction.getVector().y > 0) {
    force += GRAVITY * 1.8 * differentAngleModifier * deltaTime;
  } else {
    force -= GRAVITY * differentAngleModifier * deltaTime;
    force -= TRACTION * deltaTime;
  }

  if (force < 0)
    force = 0;

  for (SolidBody *solid : GameManager::getComponents<SolidBody>()) {
    Box box = solid->entity->box;
    if (box.checkCollision(entity->box)) {
      reset();
      launched = false;
    }
  }
}

void Airplane::reset() { entity->box.position = startPos; }

Angle Airplane::getDireciton() {
  Vector2f mousePos = InputManager::getMouseWorldPosition();
  Angle direction;
  direction.lookAt(entity->box.getCenter(), mousePos);
  return direction;
}
