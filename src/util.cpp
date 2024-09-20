#include "util.hpp"
#include "ShadowFilter.hpp"

void addCollider(Box box) {
  Entity *entity = GameManager::createEntity("");
  entity->box = box;
  entity->add<SolidBody>();
}

void loadLevel(std::function<void()> level) {
  for (Entity *entity : GameManager::getAllObjects()) {
    if (entity->checkComponent<ShadowFilter>())
      continue;
    if (entity->tag == "background")
      continue;
    if (entity->checkComponent<Light>())
      continue;
    entity->toDestroy = true;
  }

  level();
}
