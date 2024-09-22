#include "Boost_creater.hpp"
#include "components/Boost_component.hpp"

Entity *createBoost(Box box) {
  Entity *entity = GameManager::createEntity("Boost");
  entity->box = box;

  Sprite *sprite = entity->add<Sprite>();
  Image &image = sprite->image;
  image = Image("res/images/hoop.png");

  Boost* boost = entity->add<Boost>();

  return entity;
}
