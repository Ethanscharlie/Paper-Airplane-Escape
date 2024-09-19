#include "Airplane_creater.hpp"
#include "components/Airplane_component.hpp"

Entity *createAirplane() {
  Entity *entity = GameManager::createEntity("Airplane");
  entity->layer = 10;

  entity->box = Box(-473.25, -379.50, 88.50, 43.50);

  Sprite *sprite = entity->add<Sprite>();
  sprite->image = Image("res/images/cannon.png");

  Airplane* airplane = entity->add<Airplane>();

  return entity;
}
