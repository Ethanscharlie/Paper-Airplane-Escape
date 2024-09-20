#include "background_creater.hpp"

Entity *createBackground() {
  Entity *entity = GameManager::createEntity("background");

  entity->box.size = GameManager::gameWindowSize;
  entity->box.setWithCenter({0, 0});
  entity->add<Sprite>()->image = {"res/images/Levels/level1.jpg"};
  entity->layer = -1;

  return entity;
}
