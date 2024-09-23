#include "StaticScene_creater.hpp"
#include "components/ClickToScene_component.hpp"
#include "util.hpp"

Entity *loadStaticscene(Image image, std::function<void()> clickLoad) {
  Entity *entity = GameManager::createEntity("StaticScene");
  entity->box.size = GameManager::gameWindowSize;
  entity->box.setWithCenter({0, 0});
  entity->layer = 30;

  entity->add<Sprite>()->image = image;

  entity->add<ClickToScene>()->onClick = clickLoad;

  return entity;
}
