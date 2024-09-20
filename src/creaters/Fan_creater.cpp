#include "Fan_creater.hpp"
#include "SDL_render.h"
#include "components/Fan_component.hpp"

Entity* createFan(Box box, FanDirection fanDirection) {
    Entity* entity = GameManager::createEntity("Fan");
    entity->box = box;

    Sprite* sprite = entity->add<Sprite>();
    Image& image = sprite->image;
    image = Image("res/images/fan.jpg");
    image.alpha = 150;
    if (fanDirection == FanDirection::Left) {
      image.flip = SDL_FLIP_HORIZONTAL;
    }

    Fan* fan = entity->add<Fan>();
    fan->fanDirection = fanDirection;
    
    return entity;
}
