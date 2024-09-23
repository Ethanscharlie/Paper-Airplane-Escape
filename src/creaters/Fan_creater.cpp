#include "Fan_creater.hpp"
#include "SDL_render.h"
#include "components/Fan_component.hpp"

Entity *createFan(Box box, FanDirection fanDirection) {
  Entity *entity = GameManager::createEntity("Fan");
  entity->box = box;

  Sprite *sprite = entity->add<Sprite>();
  Image &image = sprite->image;
  image = Image("res/images/fan.png");
  if (fanDirection == FanDirection::Left) {
    image.flip = SDL_FLIP_HORIZONTAL;
  }

  sprite->addAnimation(
      "wind", {Image("res/images/fan.png"), Image("res/images/fan2.png")},
      0.3);
  sprite->animations["wind"]->loop();

  Fan *fan = entity->add<Fan>();
  fan->fanDirection = fanDirection;

  //
  Entity *fanbody = GameManager::createEntity("Fanbody");
  fanbody->box = box;
  fanbody->box.size.x = box.size.y / 4;

  fanbody->add<Sprite>()->image = {"res/images/fanbody.png"};

  switch (fanDirection) {
  case FanDirection::Right:
    break;
  case FanDirection::Left:
    fanbody->box.position.x = box.getRight() - fanbody->box.size.x;
    fanbody->get<Sprite>()->image.flip = SDL_FLIP_HORIZONTAL;
    break;
  }

  return entity;
}
