#include "Finish_creater.hpp"
#include "components/Finish_component.hpp"

Entity *createFinish(Box box) {
  Entity *entity = GameManager::createEntity("Finish");
  entity->box = box;

  Sprite *sprite = entity->add<Sprite>();
  Image &image = sprite->image;
  image = Image("res/images/hoop.png");

  entity->add<Finish>();

  return entity;
}
