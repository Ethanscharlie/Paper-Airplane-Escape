#include "Airplane_creater.hpp"
#include "components/Airplane_component.hpp"

Entity *createAirplane() {
  Entity *entity = GameManager::createEntity("Airplane");
  entity->layer = 10;

  entity->box = Box(-188.946, -262.225, 40.8492, 20.205);

  Sprite *sprite = entity->add<Sprite>();
  sprite->image = Image("res/images/cannon.png");

  Airplane *airplane = entity->add<Airplane>();

  return entity;
}
