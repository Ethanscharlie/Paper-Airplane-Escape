#include "Moving_creater.hpp"
#include "SolidBody.hpp"
#include "components/Moving_component.hpp"

Entity* createMoving(Box box, Vector2f otherPos) {
    Entity* entity = GameManager::createEntity("Moving");
    entity->box = box;
    entity->add<SolidBody>();

    Sprite* sprite = entity->add<Sprite>();
    Image& image = sprite->image;
    image = Image("res/images/orangeBlock.jpg");

    Moving* moving = entity->add<Moving>();
    moving->pos2 = otherPos;
    
    return entity;
}
