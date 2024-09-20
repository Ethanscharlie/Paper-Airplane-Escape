#include "Airplane_creater.hpp"
#include "Vector2f.hpp"
#include "components/Airplane_component.hpp"

Entity *createAirplane(Vector2f startPos) {
  Entity *entity = GameManager::createEntity("Airplane");
  entity->layer = 10;

  entity->box.position = startPos;
  entity->box.size = {40.8, 20.2};

  Sprite *sprite = entity->add<Sprite>();
  sprite->image = Image("res/images/cannon.png");

  Airplane *airplane = entity->add<Airplane>();

  return entity;
}
